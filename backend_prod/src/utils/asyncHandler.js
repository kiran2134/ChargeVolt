const asyncHandler = (requestHandler) => {
    (req, res, next) => {
        Promise.resolve(requestHandler(req, res, next)).c
        atch((err)=>next(err));
    }
}



module.exports = asyncHandler;