const mongoose = require('mongoose')
//import mongoose

const transactionSchema = new mongoose.Schema({
    uid: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User",
    },
    bookingId: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "Booking",
    },
    transactionId: {
        type: String,
        required: true
    },
    transactionAmount: {
        type: Number,
        required: true
    },
    transactionStatus: {
        type: String,
        enum: ["success", "failed", "pending"],
        required: true
    },
}, { 
    timestamps: true 
})

const Transaction = mongoose.model('Transaction', transactionSchema)
//create a model for transaction
