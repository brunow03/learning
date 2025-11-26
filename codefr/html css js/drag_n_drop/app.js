const draggables = document.querySelectorAll(".draggables");

const dropzone  = document.getElementById("dropzone");

// console.log(draggables);

draggables.forEach(draggable => {
	draggable.addEventListener("dragstart", function(event) {
		event.dataTransfer.setData('text/plain', event.target.textContent);
	})
})

dropzone.addEventListener('dragover', function(event) {
	event.preventDefault();
	const text = event.dataTransfer.getData('text/plain');
	dropzone.value = text.dataTransfer.getData('text/plain');
	dropzone.value = text;
})









