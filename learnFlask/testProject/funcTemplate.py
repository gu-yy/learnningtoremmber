from flask import Flask,render_template,url_for

app=Flask(__name__)

@app.route('/')
def hello():
    return render_template('funcIndex.html')

@app.route('/login/<int:num>/')
def login(num):
    return 'hello gyy'+str(num)

if __name__ == "__main__":
    app.run(debug=True)