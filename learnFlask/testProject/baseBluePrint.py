from flask import Flask,url_for

from blueprints.user import userBp
from blueprints.new import newsBp
from gyyBlue import gyyBp

app=Flask(__name__)
app.register_blueprint(userBp)
app.register_blueprint(newsBp)
app.register_blueprint(gyyBp)

@app.route('/')
def hello():
    print(url_for('new.message'))
    return 'hello world'

if __name__ == "__main__":
    app.run(debug=True)