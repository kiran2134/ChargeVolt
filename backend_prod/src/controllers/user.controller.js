const User=require('../models/user.model.js');
//Import User Model from models/user.model.js
const asyncHandler = require('../utils/asyncHandler.js');
//Import Async Handler from utils/asyncHandler.js
const apierror = require('../utils/apierror.js');
//Import API Error from utils/apierror.js
const jwt = require('jsonwebtoken');
//Import JWT fronm jsonwebtoken
const mongoose = require('mongoose');
//Import Mongoose
const apiresponse = require('../utils/apiresponse.js');
//Import API Response from utils/apiresponse.js

const registerUser = asyncHandler(async (req, res) => {
    const {name,email,phone,password} = req.body
    //Get name, email, phone and password from request body
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    //Regex to validate email
    const phoneRegex = /^\d{10}$/;
    //Regex to validate phone number
    const passwordRegex = /^(?=.*[a-zA-Z\d]).{8,}$/;
    //Regex to validate password

    if([name,email,phone,password].some((field)=>field === undefined || (field?.trim() === ""))){
        //If any of the fields are undefined or empty
        throw new apierror(400,"Please fill all the fields!")
    }

    if(emailRegex.test(email) === false){
        //If email is invalid
        throw new apierror(400,"Please enter a valid email!")
    }

    if(phoneRegex.test(phone) === false){
        //If phone number is invalid
        throw new apierror(400,"Please enter a valid phone number!")
    }

    if(passwordRegex.test(password) === false){
        //If password is invalid
        throw new apierror(400,"Please enter a valid password!")
    }

    const Useralreadyexists = await User.findOne({
        //Check if user already exists
        $or: [{email}, {phone}]
    })

    if(Useralreadyexists){
        throw new apierror(409,"User account already exists!")
    }

    const user = await User.create({
        //Create new user
        name,
        email: email.toLowerCase(),
        //Convert email to lowercase
        phone,
        password
    })

    const createdUser = await User.findById(user._id).select(
        //Find user by id and exclude password and refreshToken fields
        "-password -refreshToken"
    )

    if(!createdUser){
        //If user is not created
        throw new apierror(500,"Error creating user!")
    }

    return res.status(201).json(
        //Return success response
        new apiresponse(200,createdUser,"User registered successfully!")
    )
})

const loginUser = asyncHandler(async (req, res) => {
    const {email, password}= req.body;
    //Get email and password from request body
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    //Regex to validate email

    if([email,password].some((field)=>field === undefined || (field?.trim() === ""))){
        //If any of the fields are undefined or empty
        throw new apierror(400,"Please fill all the fields!")
    }

    if(emailRegex.test(email) === false){
        //If email is invalid
        throw new apierror(400,"Please enter a valid email!")
    }

    const user = await User.findOne({email:email.toLowerCase()})
    //Find user by email

    if(!user){
        //If user does not exists
        throw new apierror(401,"User Account does not exists!")
    }
    const isPasswordValid = await user.isPasswordCorrect(password)
    //Check if password is correct
    if(!isPasswordValid){
        throw new apierror(401,"Incorrect Password!")
    }

    const {accessToken, refreshToken} = await generateAccessAndRefreshTokens(user._id);
    //Generate access and refresh tokens by calling generateAccessAndRefreshTokens function

    const loggedInUser = await User.findById(user._id).select("-password -refreshToken")
    //Find user by id and exclude password and refreshToken fields

    const options= {
        //Set cookie options
        httpOnly: true,
        secure: true
    }

    return res.status(200)
    .cookie("accessToken",accessToken,options)
    .cookie("refreshToken",refreshToken,options)
    .json(new apiresponse(200,{
        user: loggedInUser, accessToken, refreshToken
    },
    "User logged in successfully!")
    )
})

const generateAccessAndRefreshTokens = async(userID)=>{
    try{
        const user = await User.findById(userID)
        //Find user by id
        const accessToken = user.generateAccessToken()
        //Generate access token
        const refreshToken = user.generateRefreshToken()
        //Generate refresh token

        user.refreshToken = refreshToken
        await user.save({validateBeforeSave: false})
        //Save refresh token to database

        return {accessToken,refreshToken}
    }catch(err){
        throw new apierror(500,"Error generating tokens!")
    }
}

const logoutUser = asyncHandler(async (req, res) => {
    await User.findByIdAndUpdate(req.user._id,{
        //Find user by id and update refreshToken to undefined
        $set: {
            refreshToken: undefined
        }
    },{
        new: true
        //Return updated user
    })
    const options = {
        //Set cookie options
        httpOnly: true,
        secure: true
    }
    return res.status(200)
    .clearCookie("accessToken",options)
    .clearCookie("refreshToken",options)
    .json(new apiresponse(200,{},"User logged out successfully!"))
})

const refreshAccessToken = asyncHandler(async (req, res) => {
    try {
        const incomingRefreshToken = req.cookies.refreshToken || req.body.refreshToken
        //Get refresh token from cookies or request body

        if(!incomingRefreshToken){
            throw new apierror(400,"Unauthorized Request!")
        }
        const decodedToken = jwt.verify(
            //Verify refresh token
            incomingRefreshToken,
            process.env.REFRESH_TOKEN_SECRET,
        )
        const user = await User.findById(decodedToken?._id)
        //Find user by id
    
        if(!user){
            throw new apierror(401,"Invalid Refresh Token!")
        }
        if(incomingRefreshToken !== user?.refreshToken){
            //If incoming refresh token does not match with the one in database
            throw new apierror(401,"Refresh Token is Expired!")
        }
        const options = {
            //Set cookie options
            httpOnly: true,
            secure: true
        }
    
        const {accessToken, newrefreshToken} = await generateAccessAndRefreshTokens(user._id)
        //Generate new access and refresh tokens by calling generateAccessAndRefreshTokens function
    
        return res.status(200)
        .cookie("accessToken",accessToken,options)
        .cookie("refreshToken",newrefreshToken,options)
        .json(new apiresponse(200,{
            accessToken, refreshToken: newrefreshToken
        },"Access Token Refreshed Successfully!"))
    } catch (error) {
        throw new apierror(401,"Invalid Refresh Token!")
    }
})

const deleteAccount = asyncHandler(async (req, res) => {
    const terminationconfirmpass = req.body.terminationconfirmpass
    if(terminationconfirmpass === undefined || (terminationconfirmpass?.trim() === "")){
        //If password is undefined or empty
        throw new apierror(400,"Please enter your password to confirm termination!")
    }
    //Get password from request body
    const user = await User.findById(req.user._id)
    const isPasswordValid = await user.isPasswordCorrect(terminationconfirmpass)
    //Check if password is correct
    if(!isPasswordValid){
        //If password is incorrect
        throw new apierror(401,"Incorrect Password! Termination Aborted!")
    }
    const terminateAccount = await User.findByIdAndDelete(req.user._id)
    if(!terminateAccount){
        //If user is not found
        throw new apierror(500,"Trust Me Something seriously went wrong while termination!")
        //this should never execute
    }
    //Find user by id and delete
    return res.status(200)
    .json(new apiresponse(200,{},"User Account Terminated Successfully!"))
})

const changePassword = asyncHandler(async (req, res) => {
    const {oldPassword, newPassword, confirmNewPassword} = req.body
    //Get old password and new password from request body
    const passwordRegex = /^(?=.*[a-zA-Z\d]).{8,}$/;
    //Regex to validate password

    if([oldPassword,newPassword,confirmNewPassword].some((field)=>field === undefined || (field?.trim() === ""))){
        //If any of the fields are undefined or empty
        throw new apierror(400,"Please fill all the fields!")
    }
    if(newPassword !== confirmNewPassword){
        //If new password and confirm new password do not match
        throw new apierror(400,"New Password and Confirm New Password do not match!")
    }
    if(passwordRegex.test(newPassword) === false){
        //If password is invalid
        throw new apierror(400,"Please enter a valid password!")
    }

    const user = await User.findById(req.user._id)
    //Find user by id
    const isPasswordValid = await user.isPasswordCorrect(oldPassword)
    //Check if password is correct
    if(!isPasswordValid){
        //If password is incorrect
        throw new apierror(401,"Incorrect Password!")
    }
    user.password = newPassword
    //Set password to new password
    await user.save()
    //Save user
    return res.status(200)
    .json(new apiresponse(200,{},"Password changed successfully!"))
})

module.exports = {registerUser,loginUser,logoutUser, refreshAccessToken, deleteAccount, changePassword}
//Export User Controller Functions