import React, { useState } from "react";

function MyComponent() {
    
    const [count, setCount] = useState(0);
    
    function increment() {
        setCount(count + 1);
        // setCount(c => c + 1);
        // setCount(c => c + 1);
        // setCount(c => c + 1);
    };

    function decrement() {
        setCount(count - 1);
    };

    function reset() {
        setCount(0);
    };

    return( <div>
                <p>Counte: {count}</p>
                <button onClick={decrement}>Decrement</button>
                <button onClick={reset}>Reset</button>
                <button onClick={increment}>Increment</button>

            </div>
    );
}

export default MyComponent
