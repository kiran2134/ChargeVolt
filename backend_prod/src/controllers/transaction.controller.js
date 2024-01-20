const Station = require('../models/station.model.js')
//Import Station Model
const Slot = require('../models/slot.model.js')
//Import Slot Model
const User = require('../models/user.model.js')
//Import User Model
const asyncHandler = require('../utils/asyncHandler.js')
//Import Async Handler from utils/asyncHandler.js
const apierror = require('../utils/apierror.js')
//Import API Error from utils/apierror.js
const apiresponse = require('../utils/apiresponse.js')
//Import API Response from utils/apiresponse.js
const populateSlot = require('../utils/populateSlot.js')
//Import Populate Slot from utils/populateSlot.js

const transaction = asyncHandler(async(req,res) => {
    const {amount, uid, bookingId, transactionid} = req.body
})

module.exports = {
}