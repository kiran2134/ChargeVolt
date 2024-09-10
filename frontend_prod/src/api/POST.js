import { axiosInstance } from "./axios"
import axios from "axios"
export const makeBooking = async (bookingData)=>{

    try{
        
        const {data,status} = await axios.post('http://localhost:8081/api/v1/booking/reserve',bookingData,{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        console.log(data,status);
        if(status != 201){
        throw new Error(data)
        }
        return {data,status};
        
    }
    catch(e){        
        return {success:false,message:e};
    }
}

//cancel-reservation

export const cancelBooking = async (bookingData)=>{

    try{
        
        const {data,status} = await axios.post('http://localhost:8081/api/v1/booking/cancel-reservation',bookingData,{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        console.log(data,status);
        if(status != 200){
        throw new Error(data)
        }
        return {data,status};
    }
    catch(e){        
        return {success:false,message:e};
    }
}

export const addVehicle = async (vehicleData)=>{

    try{
        console.log(vehicleData)
        const {data,status} = await axios.post('http://localhost:8081/api/v1/user/add-vehicle',vehicleData,{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        if(status !== 201){
        throw new Error(data)
        }
        return {success:true,response:data.data};
        
    }
    catch(e){
        
        return {success:false,message:e.response.data.data};
    }
}

export const createOrder = async (orderData)=>{
    try{
        const {data, status} = await axiosInstance.post('/transaction/razorpayordergen',orderData,{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        if(status != 200){
            throw new Error(data)
        }
        return {sucess:true, response:data.data}
    }
    catch(e){
        return {success:false,message:e.response.data.data};
    }
}

export const verifyPayment = async (signatureData)=>{
    try{
        const {data, status} = await axiosInstance.post('/transaction/verifysignature',signatureData,{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        if(status != 200){
            throw new Error(data)
        }
        return {success:true, response:data.data}
    }
    catch(e){
        return {success:false,message:e.response.data.data};
    }
}
