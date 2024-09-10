//import { axiosInstance } from "./axios";
import axios from "axios";
export const getStationByLocation = async(locationData,token)=>{
     console.log("at api"+locationData);
    try{
        const {data,status} = await axios.get('http://localhost:8081/api/v1/station/locate-station',{
            headers:{
                "Authorization":`Bearer ${token}`
            },
            params:{address:locationData}
        })
        //console.log("at api"+data);
        if( status != 200){
            throw new Error(data)
        }
        return {success:true,stationData:data};
    }
    catch(e){
        return {success:false,message:e.response.data.data}
    }
}

export const getLocation = async(locationData,key)=>{
    
    try{

        const {data,status} = await axios.get('https://maps.googleapis.com/maps/api/geocode/json',{
            params:
            {
                address:locationData,
                key:"AIzaSyAPxr3RCUpOO6peXtnAaDCjgCLmbzhccMQ"
            }
        })

        if( status != 200){
            throw new Error(data)
        }
        return {success:true,latLang:data.results[0].geometry.location};
    }
    catch(e){
        return {success:false,message:e}
    }
}

export const getSlotData = async(stationName)=>{
    try{
        const {data,status} = await axios.get('http://localhost:8081/api/v1/station/getslotbystation',{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            },
            params:{station_name:stationName}
        })
        if( status != 200){
            throw new Error(data)
        }
        console.log(data);
        return {success:true,slotData:data};
    }
    catch(e){
        return {success:false,message:e.response.data.data}
    }
}

export const getUserVehicle = async()=>{
    
    try{
        console.log(localStorage.getItem('accessToken'));
        const {data,status} = await axios.get('http://localhost:8081/api/v1/user/get-vehicle',{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        if( status != 200){
            throw new Error(data)
        }
        return {success:true,vehicles:data.data};
    }
    catch(e){
        return {success:false,message:e.response.data.data}
    }
}

export const getUserBookings = async()=>{
    
    try{

        const {data,status} = await axios.get('http://localhost:8081/api/v1/booking/get-booking',{
            headers:{
                "Authorization":`Bearer ${localStorage.getItem('accessToken')}`
            }
        })
        if( status != 200){
            throw new Error(data)
        }
        return {success:true,booking:data.data};
    }
    catch(e){
        return {success:false,message:e.response.data.data}
    }
}

