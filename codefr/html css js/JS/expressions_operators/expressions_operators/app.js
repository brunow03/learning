let displayArea = document.querySelector("#displayArea");
// let inputBox = document.querySelector("inputBox");
let myBtn = document.querySelector("#myBtn");

myBtn.addEventListener("click", function () {
   let a = 5;
   let b = 3;
   // let c = a + b;
   // let c = a - b;
   let c = a / b;
   // let c = a * b;
   // let c = a % b; // remainder
   // let c = a ** b; // power

   displayArea.innerHTML = c;

   // identity: === (more strict than ==)
   // nonidentity !== (more strict than !=)

   // =
   // *=
   // **=
   // /=
   // %=
   // +=
   // -=

});