const mongoose = require('mongoose');

const bookingSchema = new mongoose.Schema({
    uid: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User",
        required: true
    },
    bookingSlotType: {
        type: String,
        enum: [
            "DC-CCS1",
            "DC-CCS2",
            "DC-CHADEMO",
            "DC-GB/T",
            "AC-TYPE1",
            "AC-TYPE2",
            "AC-IEC",
            "AC-BHARATAC001",
            "DC-BHARATDC001",
            "HYBRID-TESLA",
        ],
        required: true,
        uppercase: true
    },
    registrationNumber: {
        type: String,
        required: true,
        validate: {
            validator: function (v) {
                return /^[a-zA-Z]{2}\d{2}[a-zA-Z]{2}\d{4}$/.test(v);
            },
            message: props => `${props.value} is not a valid vehicle number!`
        }
    },
    stationName: {
        type: String,
        required: true
    },
    bookingDate: {
        type: Date,
        required: true,
        validate: {
            validator: function (v) {
                return v instanceof Date && !isNaN(v);
            },
            message: props => `${props.value} is not a valid date!`
        }
    },
    bookingTime: {
        type: String,
        enum: ["slot1", "slot2", "slot3", "slot4", "slot5", "slot6", "slot7", "slot8", "slot9", "slot10", "slot11", "slot12", "slot13", "slot14", "slot15", "slot16"],
        required: true
    }
},{timestamps: true});

const Booking = mongoose.model("Booking", bookingSchema);

module.exports = Booking;
