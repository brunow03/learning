const Sequelize = require('sequelize')

// Conexão com o banco de dados MySQL
const sequelize = new Sequelize('POSTAPP', 'root', '&43546195mercurio', {
	host: "localhost",
	dialect: 'mysql'
})

module.exports = {
	Sequelize: Sequelize,
	sequelize: sequelize
}
