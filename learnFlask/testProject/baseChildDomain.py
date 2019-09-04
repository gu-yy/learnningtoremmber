from flask import Flask
from blueprints.child import childBp
app=Flask(__name__)
app.config['SERVER_NAME']='aaa.com:5000'
app.register_blueprint(childBp)
@app.route('/')
def hello():
    return 'hello'

if __name__ == "__main__":
    app.run(debug=True)