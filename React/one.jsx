import React, { useState } from 'react'

const one = () => {

    function counter() {
        const [counter, setCounter] = useState(0)

        const handleClick = () => {
            setCounter(counter + 1)
            setCounter(counter + 1)
        }


    }

  return (
    <div>
      <button onClick={handleClick}> Count : {counter} </button>
    </div>
  )
}

export default one
