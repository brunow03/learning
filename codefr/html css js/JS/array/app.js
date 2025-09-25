let displayArea = document.querySelector("#displayArea");
let inputBox = document.querySelector("#inputBox");
let myBtn = document.querySelector("#myBtn");





// WHILE LOOP

// let x = 0;

// while (x < 100) {
// 	x++;
// 	console.log(x);
// }



// DO WHILE LOOP

// let x = 0;
// do {
// 	x++;
// 	console.log(x);
// } while (x < 10);



// FOR LOOP

// let x = 0;

// for (let x = 0; x < 10; x++) {
// 	console.log(x);
// }

let languages = ["javascript", "php", "python"];
languages.push("C++");

// displayArea.innerHTML = languages;

for (let language of languages) {
	let li = document.createElement("li");
	li.innerHTML = language;
	displayArea.appendChild(li);
}

myBtn.addEventListener('click', function() {
	let new_language = inputBox.value;
	languages.push(new_language);

	let li = document.createElement("li");
	li.innerHTML = new_language;
	displayArea.appendChild(li);
});

// let fruits = ["apple", "banana", "berry"];
// fruits.push("orange");
// console.log(fruits);
// fruits.pop();
// fruits.shift();
// fruits.unshift("grape");

// let banana_index = fruits.indexOf("banana");

// displayArea.innerHTML = fruits;



// myBtn.addEventListener("click", function () {


// 	let new_fruit = inputBox.value;
// 	fruits.push(new_fruit);
// 	displayArea.innerHTML = fruits;



// });