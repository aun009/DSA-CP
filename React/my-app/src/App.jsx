import React from 'react'
import { useState } from 'react'

const App = () => {

  const [counter, setCounter] = useState(0)

  const handleButtonClick = () => {
    setCounter(prev => prev + 1)
    setCounter(prev => prev + 1)
  }

  return (
    <div>
        <button onClick={handleButtonClick}>Count : {counter}</button>
    </div>
  )
}

export default App





