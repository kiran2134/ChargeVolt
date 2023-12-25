const { registerUser, loginUser, logoutUser, refreshAccessToken } = require('../controllers/user.controller.js');
//Import User Controller from user.controller.js

const { verifyJWT } = require('../middlewares/auth.middleware.js');
//Import JWT Verification Middleware from auth.middleware.js

const Router = require('express').Router;
//Import Express Router
const router = Router();
//Create Router

router.route("/register").post(registerUser);
//Register User Route

router.route("/login").post(loginUser);
//Login User Route

router.route("/logout").post(verifyJWT, logoutUser);
//Secure Logout User Route
router.route("/refresh-token").post(verifyJWT, refreshAccessToken)
//Secure Refresh Access Token Route

module.exports = router;
//Export User Router