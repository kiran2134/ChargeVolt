import { axiosInstance } from "../axios"
import axios from "axios";
export const login = async(loginInfo)=>{

    try{
        // console.log('Sending login request:', loginInfo);
        const {data,status} = await axios.post('http://localhost:8081/api/v1/user/login',loginInfo);

        if(status != 200){
            throw new Error(data);
        }
        if(status == 200){
            return {success:true,userData:data.data}
        }
    }
    catch(e){
        return {success:false,message:e.response.data.data}
    }
}

export const register = async(loginInfo)=>{
    
    try {
        console.log("login "+JSON.stringify(loginInfo));
        const { data, status } = await axios.post(
            "http://localhost:8081/api/v1/user/register",
            loginInfo
        );
        console.log(status);
        if (status != 201) {
            throw new Error(data);
        }
        console.log(data);
        return { success: true, userData: data.data };
    } catch (e) {
        return { success: false, message: e.response.data.data };
    }
}

export const authLogin = async(token)=>{
    try {
        const { data, status } = await axios.get("http://localhost:8081/api/v1/user/get-user", {
            headers: {
                Authorization: `Bearer ${token}`,
            },
        });

        if (status == 200) {
            return data.data;
        }
    } catch (e) {
        return { success: false, 
                 message: e.response.data.data };
    }
}