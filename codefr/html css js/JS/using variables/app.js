// document.querySelector("#my_title").innerHTML = "MY WEBSITE"

let title = document.querySelector("#my_title");

let my_textbox = document.querySelector("#my_textbox");

let btn1 = document.querySelector("#myBtn");

// title.innerHTML = "THIS IS MY FORM";

// title.style.color = "steelblue";

// title.innerHTML = "WEB DEVELOPMENT";

btn1.addEventListener('click', function() {
	alert("You clicked me!");
	title.innerHTML = my_textbox.value;
});
