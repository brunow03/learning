{/* <div class="container">
<button id="btnRed">Red</button>
<button id="btnYellow">Yellow</button>
<button id="btnBlue">Blue</button>
<button id="btnGreen">Green</button>
<button id="btnWhite">Reset</button>
</div> */}


let background = document.querySelector("#background");
let btnRed = document.querySelector("#btnRed");
let btnYellow = document.querySelector("#btnYellow");
let btnBlue = document.querySelector("#btnBlue");
let btnGreen = document.querySelector("#btnGreen");
let btnWhite = document.querySelector("#btnWhite");


btnRed.addEventListener('click', function () {
    background.style.background = "#e94560";
});

btnYellow.addEventListener('click', function () {
    background.style.background = "#ffd66b";
});

btnBlue.addEventListener('click', function () {
    background.style.background = "#0278ae";
});

btnGreen.addEventListener('click', function () {
    background.style.background = "#61b15a";
});

btnWhite.addEventListener('click', function () {
    background.style.background = "#fff";
});