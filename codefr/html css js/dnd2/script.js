

const draggables = document.querySelectorAll('.draggable');
const blank = document.getElementById("blank");
const checkAnswer = document.getElementById("checkAnswer");
const answerMessage = document.getElementById("answerMessage");
let answer = "";



checkAnswer.addEventListener('click', function() {
    const correctAnswer = "html";

    if (answer === correctAnswer) {
        answerMessage.style.display = "block";
        answerMessage.textContent = "Your answer is correct!";
        answerMessage.style.color = "green";
    } else {
        answerMessage.style.display = "block";
        answerMessage.textContent = "Your answer is incorrect!";
        answerMessage.style.color = "red";
    }
   
})

draggables.forEach(draggable => {
    draggable.addEventListener("dragstart", function(event) {
        event.dataTransfer.setData('text/plain', event.target.textContent)
    })
} )

blank.addEventListener('dragover', function(event) {
    event.preventDefault();
})

blank.addEventListener('drop', function(event) {
    event.preventDefault();
    answer = event.dataTransfer.getData('text/plain').toLowerCase();
    blank.value = answer

    // if (answer === "html") {
    //     alert("Congratulations!, the answer is correct!");
    // } else {
    //     alert("The answer is wrong! Try again");
    // }
})



