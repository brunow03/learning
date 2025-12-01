from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SECRET_KEY'] = 'LASKDMALSDK1DK-120K21-0D1K-2'

db = SQLAlchemy(app)
migrate = Migrate(app, db)

from estudo.views import homepage
from estudo.models import Contato

