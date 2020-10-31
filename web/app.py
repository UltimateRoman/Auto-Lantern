from flask import Flask, render_template
import sqlalchemy.orm
from cockroachdb.sqlalchemy import run_transaction
sessionmaker = sqlalchemy.orm.sessionmaker(db.engine)

app = Flask(__name__)
app.config.from_pyfile('hello.cfg')
db = SQLAlchemy(app)

class Todo(db.Model):
    __tablename__ = 'todos'
    id = db.Column('vcount', db.Integer)

    def __init__(self):
        self.id = 0

@app.route("/")
def main():
    def show_all():
        def callback(session):
            return render_template(
                'main.html',
            vcount=session.query(Todo))
        return run_transaction(sessionmaker, callback)
        

if __name__ == '__main__':
    app.run()
