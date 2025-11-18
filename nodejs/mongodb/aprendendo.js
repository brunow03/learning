const mongoose = require('mongoose')

// Configurando o mongoose
mongoose.Promise = global.Promise;
mongoose.connect("mongodb://localhost/aprendendo", {
	useNewUrlParser: true,
    useUnifiedTopology: true
}).then(() => {
	console.log("MongoDB conectado")
}).catch((err) => {
	console.log("Houve um erro ao se conectar ao MongoDB: " + err)
})

// Model - Usuarios
	// Definindo o model
	const UsuarioSchema = mongoose.Schema({
		nome: {
			type: String,
			require: false
		},
		sobrenome: {
			type: String,
			require: true
		},
		email: {
			type: String,
			require: true
		},
		idade: {
			type: Number,
			require: true
		},
		pais: {
			type: String
		}

	})

// Collection
mongoose.model('usuarios', UsuarioSchema)

const Camila = mongoose.model('usuarios')

new Camila({
	nome: "Camila",
	sobrenome: "Pitanga",
	email: "camila@hotmail.com",
	idade: 40,
	pais: "Estados Unidos"
}).save().then(() => {
	console.log("Usuario criado com sucesso!")
}).catch((err) => {
	console.log("Houve um erro ao registrar o usuario: " + err)
})









