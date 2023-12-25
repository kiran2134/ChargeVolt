const user=require('../models/user.model.js');
const asyncHandler = require('../utils/asyncHandler.js');
const apierror = require('../utils/apierror.js');
const jwt = require('jsonwebtoken');
const mongoose = require('mongoose');


const registerUser = asyncHandler(async (req, res) => {
    const {name,email,phone,password} = req.body
    

    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    const phoneRegex = /^\d{10}$/;
    const passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,}$/;

    if([name,email,phone,password].some((field)=>field?.trim() === "")){
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

    console.log(name,email,phone,password)
})



module.exports = {registerUser}