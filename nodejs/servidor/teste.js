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
Postagem.sync()


// sequelize.authenticate().then(function(){
// 	console.log("Conectado com sucesso!");
// }).catch(function(erro){
// 	console.log("Falha ao se conectar: " + erro);
// });



