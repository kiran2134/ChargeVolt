const mongoose = require("mongoose")

require("dotenv").config();

const dbConnect = () => {
    mongoose.connect("mongodb://localhost:27017/miniproject",

    
   )
   .then(()=>console.log("success connected") )
   .catch((error)=>{
    console.log("Issue in DB Connection ");
       console.log(error.message);
       process.exit(1);
   });

}   

module.exports = dbConnect;