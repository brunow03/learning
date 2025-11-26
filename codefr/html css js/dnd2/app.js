const draggables = document.querySelectorAll('.draggable');
const blank = document.getElementById("blank");

draggables.forEach(draggable => {
    draggable.addEventListener("dragstart", function(event) {
        event.dataTransfer.setData('text/plain', event.target.textContent);
    })
})

blank.addEventListener('dragover', function(event) {
    event.preventDefault();
})

blank.addEventListener('drop', function(event) {
    event.preventDefault();
    const answer = event.dataTransfer.getData('text/plain').toLowerCase();
    blank.value = answer;

    if (answer == "html") {
        alert("Congratulations! The answer is correct!");
    } else {
        alert("The answer is wrong! Try again");
    }

});


// eventTeller.innerHTML = "testing";
