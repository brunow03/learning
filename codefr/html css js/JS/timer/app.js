
let timerDisplay = document.querySelector("#timerDisplay");
let startBtn = document.querySelector("#startBtn");
let stopBtn = document.querySelector("#stopBtn");
let theTimer = 0;
let myTimer;

startBtn.addEventListener("click", function(){
	
	myTimer = setInterval(function() {
		// alert("AE FILHA DA PUTA!!!!!");
		
		theTimer++;
		timerDisplay.innerHTML = theTimer;

	}, 50);

})

stopBtn.addEventListener("click", function() {

	clearInterval(myTimer);
	timerDisplay.innerHTML = 0;
	theTimer = 0;

})

clearInterval(myTimer);


