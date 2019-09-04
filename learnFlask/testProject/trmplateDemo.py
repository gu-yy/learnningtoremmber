from flask import Flask,render_template

app=Flask(__name__)     #还有默认参数template_folder=''rmplates'，默认在这个目录下面查找模板文件，可以修改这个参数

@app.route('/')
def hello():
    return render_template('index.html')

if __name__ == "__main__":
    app.run(debug=True)