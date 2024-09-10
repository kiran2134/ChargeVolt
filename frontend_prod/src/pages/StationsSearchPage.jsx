import React, { useCallback, useContext, useRef, useState } from "react";
import { Form } from "react-router-dom";
import blurBg from "/src/assets/gridbg.png";
import { Search } from "lucide-react";
import SearchStationCard from "../components/SearchStationCard";
import electric from "/src/assets/marker-icon.png";

import {
    useJsApiLoader,
    GoogleMap,
    StandaloneSearchBox,
    MarkerF,
    InfoWindowF,
} from "@react-google-maps/api";

import mapStyle from "../utils/mapStyle";
import { getLocation, getStationByLocation } from "../api/GET";
import { Data } from "../context/DataContext";
import { searchStationAction } from "../action/action";
import ProtectedRoute from "../components/utils/ProtectedRoute";
import Title from "../components/Title";
import { markers } from "../utils/markers";
// import dotenv from "dotenv"

// dotenv.config()

const StationsSearchPage = () => {
    const [activeMarker, setActiveMarker] = useState(null);

    const locationNameRef = useRef("");

    const [location, setLocation] = useState({
        lat: 18.5204303,
        lng: 73.8567437,
    });

    const handleActiveMarker = (marker) => {
        if (marker === activeMarker) {
            return;
        }
        setActiveMarker(marker);
    };

    const [map, setMap] = useState(null);
    const context = useContext(Data);

    const { extend, isLoaded } = useJsApiLoader({
        googleMapsApiKey: import.meta.env.VITE_API_KEY,
        libraries: ["places"],
        mapIds: ["77e9b6d157be5f17"],
    });

    const onLoad = useCallback(function callback(map) {
        const bounds = new window.google.maps.LatLngBounds(location);
        bounds.extend(location);
        map.setZoom(15);
        // map.fitBounds(bounds);
        setMap(map);
    }, []);

    const handleFormSubmit = async () => {
        const searchLocation = locationNameRef.current.value;
        console.log("sl  "+searchLocation)
        const res = await getStationByLocation(
            searchLocation,
            localStorage.getItem("accessToken")
        );
        const { latLang } = await getLocation(
            searchLocation,
            import.meta.env.VITE_API_KEY
        );
        if (res.success) {
            // extend(latLang)
            //console.log("in ssp  "+JSON.stringify(res.stationData.data));
            context.SEARCH_STATION_DISPATCH({
                type: searchStationAction.ADD_DATA,
                payload: res.stationData.data,
            });
        } else {
            // TODO: handle not response
            context.SEARCH_STATION_DISPATCH({
                type: searchStationAction.RESET_DATA,
            });
        }
        const bounds = new window.google.maps.LatLngBounds(latLang);
        console.log("bounds  "+bounds);
        var zoom = map.getZoom();
        map.setZoom(11);
        setLocation(latLang);
        bounds.extend(location);
        // map.fitBounds(bounds);
    };

    if (!isLoaded) {
        return (
            <div className="flex items-center justify-center text-5xl w-full h-screen">
                Loading
            </div>
        );
    }

    return (
        <section className="  w-full h-screen overflow-hidden relative grid grid-cols-3 bg-[#f8f1ff]">
            <div className=" z-10 col-span-1 overflow-hidden border-green-500 w-full h-[90%] flex-box gap-5 justify-start flex-col mt-[5em]  ">
                <div className=" w-3/4 ">
                    <Title text={"Stations"} />
                    <hr className=" w-full h-1 bg-violet-500 rounded-xl" />
                </div>

                <div className=" w-[85%] h-[100%]  overflow-y-scroll no-scrollbar border-red-500  gap-8 flex-box justify-start flex-col">
                    {context.SEARCH_STATION ? (
                        context.SEARCH_STATION.map((stationData) => {
                            return (
                                <SearchStationCard stationData={stationData} />
                            );
                        })
                    ) : (
                        <div className=" text-2xl font-semibold mt-[50%]">
                            No Data
                        </div>
                    )}
                </div>
            </div>

            <div className=" z-10  col-span-2 w-full  gap-5 flex-box flex-col  border-black">
                {/* SEARCH BAR */}
                <div className=" w-3/4 h-[20%] mt-[5em] grid grid-cols-4 gap-5">
                    <div className=" w-full h-full flex-box flex-col justify-evenly rounded-2xl py-3 gap-5 col-span-4">
                        <Form className="w-full flex-box  rounded-2xl">
                            <div className=" w-full h-full flex-box  bg-violet-100 shadow-sm rounded-3xl overflow-hidden">
                                <div className="w-[90%] bg-violet-100 h-14 text-2xl placeholder:text-xl focus:outline-none">
                                    <StandaloneSearchBox>
                                        <input
                                            ref={locationNameRef}
                                            type="text"
                                            className="w-[90%] bg-violet-100 h-14 text-xl placeholder:text-xl focus:outline-none "
                                            placeholder="Search for a Area..."
                                        />
                                    </StandaloneSearchBox>
                                </div>

                                <button
                                    type="submit"
                                    onClick={handleFormSubmit}
                                    className=" text-violet-700 "
                                >
                                    <Search />
                                </button>
                            </div>
                        </Form>
                        
                        
                    </div>
                </div>

                <div className=" w-3/4 mt-5 h-[60%] rounded-2xl overflow-hidden shadow-xl ">
                    <GoogleMap
                        center={location}
                        zoom={12}
                        onLoad={onLoad}
                        options={{
                            styles: mapStyle,
                            disableDefaultUI: true,
                            maxZoom: 16,
                            minZoom: 7,
                        }}
                        mapContainerStyle={{
                            width: "100%",
                            height: "100%",
                        }}
                    >
                        {markers.map(({ id, name, position }) => (
                            <MarkerF
                                key={id}
                                position={position}
                                onClick={() => {
                                    map.setZoom(14);
                                    setLocation(position);
                                    bounds.extend(location);
                                }}
                                onMouseOver={() => handleActiveMarker(id)}
                                icon={electric}
                            >
                                {activeMarker === id ? (
                                    <InfoWindowF
                                        onCloseClick={() =>
                                            setActiveMarker(null)
                                        }
                                    >
                                        <div>
                                            <p>{name}</p>
                                        </div>
                                    </InfoWindowF>
                                ) : null}
                            </MarkerF>
                        ))}
                    </GoogleMap>
                </div>
            </div>

            <img
                src={blurBg}
                alt="background"
                className=" w-full h-full object-cover opacity-10 absolute top-0 "
                draggable={false}
            />
        </section>
    );
};

export default StationsSearchPage;
