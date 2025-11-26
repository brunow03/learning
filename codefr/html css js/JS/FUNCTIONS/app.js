function addTwoNumbers(a, b) {
	// let a = 2;
	// let b = 5;
	let sum = a + b;
	console.log(sum);
}


function greet(typeOfGreeting) {
	alert(typeOfGreeting);
}



let btn1 = document.querySelector("#btn1");
let greetBtn = document.querySelector("#greetBtn");

// addTwoNumbers();	

btn1.addEventListener('click', function(){
	addTwoNumbers(5, 10);
});

greetBtn.addEventListener('click', function(){
	greet("Good Morning");
});