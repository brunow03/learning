let myData = [

	{
		first_name: "Bruno",
		last_name: "Mendes",
		age: 29,
		fullname: function () {
			return this.first_name + " " + this.last_name;
		}
	},
	
	{
		first_name: "Bruno",
		last_name: "Mendes",
		age: 29,
		fullname: function () {
			return this.first_name + " " + this.last_name;
		}
	},

	{
		first_name: "Bruno",
		last_name: "Mendes",
		age: 29,
		fullname: function () {
			return this.first_name + " " + this.last_name;
		}
	}
];


// myData.forEach((item, idx) => {
// 	console.log(item);
// });

// for (var i = 0; i <= myData.length - 1; i++) {
// 	console.log(myData[i].first_name);
// }

// let listHolder = document.querySelector("#listHolder");

// let tr = document.createElement("tr");

// tr.innerHTML = `
// 			<td>1</td>
// 			<td>Mark</td>
// 			<td>Otto</td>
// 			<td>@mdo</td>
// 			`;

// listHolder.appendChild(tr);


let listHolder = document.querySelector("#listHolder");
let firstname = document.querySelector("#firstName");
let lastname = document.querySelector("#lastName");
let age = document.querySelector("#age");
let btnSubmit = document.querySelector("#btnSubmit");

btnSubmit.addEventListener("click", function () {
	if (firstName.value.trim() == "" || lastName.value.trim() == "" || age.value.trim() == "") {
		alert("Fill out the form completely");
	} else {
		let copyData = [...myData];
		let newEntry = {
			first_name: firstName.value.trim(),
			last_name: lastName.value.trim(),
			age: age.value.trim(),
			fullname: function () {
				return this.first_name + " " + this.last_name;
			} 
		}

		copyData.push(newEntry);

		myData.splice(0, myData.length, ...copyData);

		listHolder.innerHTML = "";

		renderRecord();
		firstName.value = "";
		lastName.value = "";
		age.value = "";
	}
})


// listHolder.appendChild(tr);

// myData.forEach((item, index) => {
// 	let tr = document.createElement("tr");
// 	tr.innerHTML = `
// 			<td>${index + 1}</td>
// 			<td>${item.fullname()}</td>
// 			<td>${item.age}</td>
// 			`;
// 	listHolder.appendChild(tr);
// });

function renderRecord() {
	myData.forEach((item, index) => {
		let tr = document.createElement("tr");
		tr.innerHTML = `
				<td>${index + 1}</td>
				<td>${item.fullname()}</td>
				<td>${item.age}</td>
				`;
		listHolder.appendChild(tr);
	});
}

renderRecord();

