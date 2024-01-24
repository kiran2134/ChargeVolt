import React, { useEffect, useState } from 'react'
import Container from '../components/Container'
import { getUserBookings } from '../api/GET'
import { getTimeSlot } from '../utils/helper'
import { Fuel } from 'lucide-react'

import blob from '../assets/blur.svg'

const UserBooking = () => {

    const [bookingData,setBookingData] = useState(null)
    const [loading,setLoading] = useState(true)
    useEffect(()=>{
        setLoading(true)
        const fetchBookings = async ()=>{
            const res = await getUserBookings();
            if(res.success){
                setBookingData(res.booking)
            }
            setLoading(false)
        }    

        fetchBookings()
    },[])

    console.log(bookingData);

    if(loading){
        return <div>Loading</div>
    }
  return (
    <Container>
        <div className='w-[80%] h-full mt-20 flex-box flex-col justify-start col-span-3 '>
            <h1 className=" small-title text-violet-500 self-start">Bookings</h1>


            <div className=' w-full flex-box flex-wrap justify-start  content-start gap-10 p-5 mt-10 border-teal-500 '>
                {
                    bookingData?
                    bookingData.map(bookingData=>{
                        return <BookingCard bookingData={bookingData}/> 
                    })
                    :
                    <h1>No Bookings</h1>
                }  
            </div>
        </div>
    </Container>
  )
}

export default UserBooking

const BookingCard = ({bookingData})=>{
    return(
        <div className=' flex-box flex-col relative rounded-xl  text-white bg-[radial-gradient(ellipse_at_top_right,_var(--tw-gradient-stops))] from-violet-500 via-indigo-500 to-purple-600 shadow-lg group'>
            <div className='flex-box px-3 py-5 rounded-md gap-3'>
                <Fuel size={40} />
                <h1 className=' text-xl font-bold text-white '>{bookingData.stationName}</h1>
            </div>
            <div className=' flex-box flex-col group-hover:translate-y-[-60px] duration-300 items-start gap-3 rounded-xl px-8 py-5 text-slate-900 bg-[radial-gradient(ellipse_at_bottom_left,_var(--tw-gradient-stops))] from-purple-200 via-violet-100 to-indigo-100 z-10'>

                    <h1 className='text-lg font-semibold '>{bookingData?.bookingSlotType}</h1> 
                    <h1 className='text-lg '>{bookingData?.registrationNumber}</h1> 
                    <div className=' flex-box gap-3'>
                        <h1 className=' text-md font-semibold '>{new Date(bookingData?.bookingDate).toLocaleDateString('en-GB')}</h1>
                        <h1 className='text-md font-semibold'>{getTimeSlot(bookingData?.bookingTime)}</h1> 
                    </div>
                <div className=' flex-box justify-between w-full'>
                </div>


            </div>
                <button className=' px-3 py-2 bottom-3  hover:text-white font-semibold rounded-md absolute text-sm bg-red-500 duration-300 '>Cancel Booking</button>
        </div>
    )
}