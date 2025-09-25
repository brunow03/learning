// {<input type="number" id="numberBox">
// 		<button><i class="fas fa-plus-circle" id="plus"></i></button>
// 		<button><i class="fas fa-minus-circle" id="minus"></i></button>
// 		<button><i class="fas fa-sync-alt" id="reset"></i></button>}


let numberBox = document.querySelector("#numberBox");
const plus = document.querySelector("#plus");
const minus = document.querySelector("#minus");
const reset = document.querySelector("#reset");

let my_number = 0;

numberBox.value = my_number;
// my_number = Number(numberBox.value);

plus.addEventListener('click', function() {
	my_number = Number(numberBox.value);
	my_number = my_number + 1;
	numberBox.value = my_number;
});

minus.addEventListener('click', function() {
	my_number = Number(numberBox.value);
	my_number = my_number - 1;
	numberBox.value = my_number;
});

reset.addEventListener('click', function() {
	my_number = 0;
	numberBox.value = my_number;
});


