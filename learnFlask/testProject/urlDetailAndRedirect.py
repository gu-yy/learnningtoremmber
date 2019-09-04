from flask import Flask,redirect,url_for,request

app=Flask(__name__)

@app.route('/')
def hello():
    return 'hello world'

@app.route('/login/')
def login():
    return 'login success'

@app.route('/profile/')
def profile():
    if request.args.get('name'):
        return 'profile'
    else:
        return redirect(url_for('login'))

if __name__=='__main__':
    app.run(debug=True)