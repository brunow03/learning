const Sequelize = require('sequelize');
const sequelize = new Sequelize('teste', 'root', '&43546195mercurio', {
	host: "localhost",
	dialect: 'mysql'
});

const Postagem = sequelize.define('postagens',{
	titule: {
		type: Sequelize.STRING
	},
	conteudo: {
		type: Sequelize.TEXT
	}
});

// Postagem.create({
// 	titule: "UM TITULO QUALQUER",
// 	conteudo: "Alguma coisa"
// })

const Usuario = sequelize.define('usuarios', {
	nome: {
		type: Sequelize.STRING
	},
	sobrenome: {
		type: Sequelize.STRING
	},
	idade: {
		type: Sequelize.INTEGER
	},
	email: {
		type: Sequelize.STRING
	}
});

// Usuario.sync({force: true});

Usuario.create({
	nome: "Bruno",
	sobrenome: "Mendes",
	idade: 20,
	email: "bruno.mendes.003@gmail.com"
});

// sequelize.authenticate().then(function(){
// 	console.log("Conectado com sucesso!");
// }).catch(function(erro){
// 	console.log("Falha ao se conectar: " + erro);
// });
