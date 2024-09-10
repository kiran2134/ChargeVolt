require('dotenv').config()
//Import Environment Variables from .env file
const db_conn = require("./db/db_conn.js")
//Import Database Connection Function
const app = require("./app.js")
//Import Express App
db_conn()
//Establish Database Connection


app.listen(8081, () => {
    //Start Express Server
        console.log(`Server listening at PORT 8081`)
    })
