{/* <div class="container">
        <h3>Creating Element using Javascript</h3>
        <input id="myTextbox" type="text" placeholder="Enter data">
        <button id="btn">Create Element</button>
    </div>

    <div class="container2">
        <ul id="my_list">
            <li>sample data</li>
        </ul>
    </div> */}


  
let myTextbox = document.querySelector("#myTextbox");
let btn = document.querySelector("#btn");
let my_list = document.querySelector("#my_list");

btn.addEventListener('click', function () {

    let entered_data = myTextbox.value;

    if (entered_data.trim() == "") {
        
        alert("Please enter data");

    } else {

        let new_elem = document.createElement("li");
        new_elem.innerHTML = myTextbox.value.toLowerCase();
        my_list.appendChild(new_elem);

    }

    
});



