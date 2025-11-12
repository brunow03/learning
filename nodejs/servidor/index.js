const express = require("../node_modules/express");

const app = express();

app.get("/", function(req, res){
	res.sendFile(__dirname + "./html/index.html");
});

app.get("/sobre", function(req, res){
	res.sendFile(__dirname + "./html/sobre.html");
});

app.get("/blog", function(req, res){
	res.send("Bem-vindo ao meu blog!");
});

app.get("/ola/:nome/:cargo", function(req, res){
	res.send(req.params);
});

app.listen(8081, function(){
	console.log("Servidor rodando na porta: http://localhost:8081");
});
// localhost:8081
