import React from 'react'
import Button from './Button'

const SlotType = ({text,value,onClick,time}) => {
  console.log(text,value,onClick,time);
  function formatTime(isoString) {
    const date = new Date(isoString);
    const options = {
        hour: 'numeric',
        minute: 'numeric',
        hour12: true,
    };
    return date.toLocaleTimeString('en-US', options);
}

  return (
    <Button
    text={formatTime(time)}
    value={value}
    onClick={onClick}
    className={text == value ? " bg-[radial-gradient(ellipse_at_top_left,_var(--tw-gradient-stops))] from-violet-400 via-violet-600 to-sky-600 text-white" : ""}
    />
  )
}

export default React.memo(SlotType)