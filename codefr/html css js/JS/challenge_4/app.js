
let body = document.querySelector("body");

let btn1 = document.querySelector("#btn-red");
let btn2 = document.querySelector("#btn-yellow");
let btn3 = document.querySelector("#btn-blue");
let btn4 = document.querySelector("#btn-green");
let btn5 = document.querySelector("#btn-reset");

btn1.addEventListener('click', function(){
	body.style.background = "#e94560";
});

btn2.addEventListener('click', function(){
	body.style.background = "#ffd66b";
});

btn3.addEventListener('click', function(){
	body.style.background = "#0278ae";
});

btn4.addEventListener('click', function(){
	body.style.background = "#61b15a";
});

btn5.addEventListener('click', function(){
	body.style.background = "#fff";
});


// document.querySelector("#btn-reset").addEventListener('mousedown', (e) => {
// 	e.target.tabIndex = 0;  // Enable focus for this click
// });

// document.querySelector("#btn-reset").addEventListener('blur', (e) => {
// 	e.target.tabIndex = -1; // Disable focus after losing it
// });