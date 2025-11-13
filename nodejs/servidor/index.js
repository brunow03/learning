const express = require("../node_modules/express")
const app = express()
const handlebars = require('express-handlebars')
const bodyParser = require('body-parser')
const Post = require('./models/Post')
const { where } = require("sequelize")

// app.get("/", function(req, res){
// 	res.sendFile(__dirname + "./html/index.html");
// });

// app.get("/sobre", function(req, res){
// 	res.sendFile(__dirname + "./html/sobre.html");
// });

// app.get("/blog", function(req, res){
// 	res.send("Bem-vindo ao meu blog!");
// });

// app.get("/ola/:nome/:cargo", function(req, res){
// 	res.send(req.params);
// });

// Config
	// Template Engine
		app.engine('handlebars', handlebars.engine({defaultLayout: 'main'}))
		app.set('view engine', 'handlebars')
	// Body Parser
		app.use(bodyParser.urlencoded({extended: false}))
		app.use(bodyParser.json())

// Rotas
	app.get('/', function(req,res){
		Post.findAll({ order: [['id', 'DESC']] }).then(function(posts){
			
			const plainPosts = posts.map(post => post.toJSON());
			// console.log(posts)

			res.render('home', {posts: plainPosts})
			// res.render('home', {nome: "bruno", sobrenome: "mendes" })
		}).catch(function(error) {
			res.send("Erro ao carregar posts: " + error);
		});
		// res.render('home')
	})

	app.get('/cad', function(req, res){
		res.render('formulario')
	})

	app.post('/add', function(req, res){
		
		Post.create({
			titulo: req.body.titulo,
			conteudo: req.body.conteudo
		}).then(function(){
			// res.send("Post criado com sucesso!")
			res.redirect('/')
		}).catch(function(erro){
			res.send("Houve um erro: " + erro)
		})

		// req.body.conteudo
		// res.send("Texto: " + req.body.titulo + " Conteudo: " + req.body.conteudo)
		// res.send('FORMULARIO RECEBIDO!')

	})

	app.get('/deletar/:id', function(req,res){
		Post.destroy({where: {'id': req.params.id}}).then(function(){
			res.send("Postagem deletada com sucesso!")
		}).catch(function(erro){
			res.send("Esta postagem não existe!")
		})
	})

app.listen(8081, function(){
	console.log("Servidor rodando na porta: http://localhost:8081")
})
// localhost:8081
