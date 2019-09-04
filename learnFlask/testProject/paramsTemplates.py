from flask import Flask,render_template

app=Flask(__name__)

city={
    'name':'WuHan',
    'street':'LuoYu Road',
    'person':{
        'username':'gyy',
        'age':18
    }
}

@app.route('/')
def hello():
    return render_template('paramsIndex.html',**city)

if __name__ == "__main__":
    app.run(debug=True)