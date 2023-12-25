const { application } = require('express');
const asyncHandler = require('../utils/asyncHandler');

const registerUser = asyncHandler(async (req, res) => {
    const {name,email,phone,password} = req.body
    console.log(name,email,phone,password)
    if([name,email,phone,password].some((field)=>field?.trim() === "")){
        throw new apierror(400,"Please fill all the fields!")
    }
})



module.exports = {registerUser}