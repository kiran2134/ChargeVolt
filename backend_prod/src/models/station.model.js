const mongoose = require('mongoose');
//Import Mongoose
const stationSchema = new mongoose.Schema({
    sid: {
        type: mongoose.Schema.Types.UUID,
        ref: 'Station',
        //Reference to Station Model
        required: true,
        unique: true
    },
    city: {
        type: String,
        required: [true, "City cannot be empty!"],
        minlength: [3, "City must be at least 3 characters!"],
        maxlength: [32, "City must be at most 32 characters!"]
    },
    state: {
        type: String,
        required: [true, "State cannot be empty!"],
        minlength: [3, "State must be at least 3 characters!"],
        maxlength: [32, "State must be at most 32 characters!"]
    }
},
{timestamps: true});
//Add createdAt and updatedAt fields automatically managed by Mongoose


const Station = mongoose.model("Station", stationSchema);
//Create Station Model

module.exports = Station;
//Export Station Model