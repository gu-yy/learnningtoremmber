from flask import Flask,url_for
from werkzeug.routing import BaseConverter

app=Flask(__name__)

class ListConverter(BaseConverter):
    def to_python(self,value):  #将a+b分割为['a','b']，这个返回值会自动返回给视图函数，作为视图函数的参数
        print(value)
        return value.split('+')	

    def to_url(self,value):
        return "+".join(value)	#将['a','b']拼接为a+b，这个返回值会自动返回给url_for(),然后返回一个url


app.url_map.converters['list']=ListConverter #加入新类型
@app.route('/')
def hello():
    return url_for('myList',params=['a','b']) #直接将一个列表参数传入to_url()，然后在to_url()中，会处理为字符串作为url_for的返回值

@app.route('/list/<list:params>')
def myList(params):
    print(params)
    return str(params)



if __name__=='__main__':
    app.run(debug=True)
    