const User=require('../models/user.model.js');
const asyncHandler = require('../utils/asyncHandler.js');
const apierror = require('../utils/apierror.js');
const jwt = require('jsonwebtoken');
const mongoose = require('mongoose');
const apiresponse = require('../utils/apiresponse.js');

const registerUser = asyncHandler(async (req, res) => {
    const {name,email,phone,password} = req.body
    
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    const phoneRegex = /^\d{10}$/;
    const passwordRegex = /^(?=.*[a-zA-Z\d]).{8,}$/;

    if([name,email,phone,password].some((field)=>field === undefined || (field?.trim() === ""))){
        throw new apierror(400,"Please fill all the fields!")
    }
    if(emailRegex.test(email) === false){
        throw new apierror(400,"Please enter a valid email!")
    }
    if(phoneRegex.test(phone) === false){
        throw new apierror(400,"Please enter a valid phone number!")
    }
    if(passwordRegex.test(password) === false){
        throw new apierror(400,"Please enter a valid password!")
    }
    const Useralreadyexists = await User.findOne({
        $or: [{email}, {phone}]
    })

    if(Useralreadyexists){
        throw new apierror(409,"User account already exists!")
    }

    const user = await User.create({
        name,
        email: email.toLowerCase(),
        phone,
        password
    })

    const createdUser = await User.findById(user._id).select(
        "-password -refreshToken"
    )
    if(!createdUser){
        throw new apierror(500,"Error creating user!")
    }

    return res.status(201).json(
        new apiresponse(200,createdUser,"User registered successfully!")
    )
})



module.exports = {registerUser}