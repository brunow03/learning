let tbody = document.querySelector("#tbody");
let submitBtn = document.querySelector("#submitBtn");
let firstname = document.querySelector("#firstname");
let lastname = document.querySelector("#lastname");

submitBtn.addEventListener("click", function(){
	// alert("Working!");
	if (firstname.value.trim() == "" || lastname.value.trim() == "") {
		alert("Please fill out the form completely");
	} else {
		let new_row = document.createElement("tr");

		let new_firstname = document.createElement("td");
		let new_lastname = document.createElement("td");
		
		new_firstname.innerHTML = firstname.value;
		new_lastname.innerHTML = lastname.value;

		new_row.appendChild(new_firstname);
		new_row.appendChild(new_lastname);

		tbody.appendChild(new_row);

		firstname.value = "";
		lastname.value = "";

	}
});
