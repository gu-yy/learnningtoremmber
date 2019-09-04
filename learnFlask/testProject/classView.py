from flask import Flask,views,render_template,jsonify,request
from functools import wraps
app=Flask(__name__)

class ListView(views.View):
    def dispatch_request(self):
        return 'list view'

#当有几个url需要返回json数据，那么可以使用jsonify实现
#实现过程如下：
#首先在父类里面实现了两个方法getData()和dispatch_request()，但是父类的getData()方法会抛出异常
#然后在子类里面实现了与父类的同名方法getData()
#通过app.add_url_rule('/json/',view_func=ListData.as_view('json'))绑定url与类视图，当访问/json/这个url时，就会调用子类ListData中的dispatch_request()方法
#但是子类没有实现这个方法，所以会调用父类dispatch_request这个方法，在父类这个方法中，又会调用getData这个方法，由于这个方法子类实现了，
#所以会调用子类的getData这个方法，最后通过jsonify将字典类型的数据转化为json数据
class JSONView(views.View):
    def getData(self):
        raise NotImplementedError       #抛出异常没有实现功能的源码的错误

    def dispatch_request(self):
        return jsonify(self.getData())

class ListData(JSONView):
    def getData(self):
        return {'username':'gyy','age':18}

app.add_url_rule('/json/',view_func=ListData.as_view('json'))
app.add_url_rule('/list/',endpoint='list',view_func=ListView.as_view('list'))

class ADSView(views.View):
    #将子类共用的数据存放到基类中，在init方法中初始化，这样的话这个公共数据只需要在父类中定义一次就可以了
    def __init__(self):
        #super().__init__()
        self.context={
            'ads':'aaaaaabbbbbbbbbbbbbbbbbb'
        }

class Login(ADSView):
    def dispatch_request(self):
        return render_template('loginClass.html',**self.context)

class Regist(ADSView):
    def dispatch_request(self):
        return render_template('registClass.html',**self.context)

app.add_url_rule('/login/',view_func=Login.as_view('login'))
app.add_url_rule('/regist/',view_func=Regist.as_view('regist'))


class Method(views.MethodView):
    def __render(self,error=None):
        return render_template('method.html',error=error)

    def get(self):
        return self.__render()

    def post(self):
        methodName=request.form.get('methodName')
        methodPassword=request.form.get('methodPassword')
        if methodName=='gyy' and methodPassword=='123456':
            return '登录成功'
        else:
            return self.__render(error='账户或者密码错误')
    
app.add_url_rule('/method/',view_func=Method.as_view('method'))


#是视图函数和类视图使用装饰器
#定义装饰器
def myDecorator(func):
    @wraps(func)
    def wrapper(*args,**kwargs):
        #传入wrapName=gyy才执行视图函数或者类视图
        wrapName=request.args.get('wrapName')
        if wrapName=='gyy':
            return func(*args,**kwargs)
        else:
            return '请先登录'
    return wrapper

#视图函数使用装饰器必须先用app.route再用自定义的装饰器
@app.route('/wrap/')
@myDecorator
def myWrap():
    return '登录成功'

class UseDecorator(views.View):
    decorators=[myDecorator]    #在这个中列表中写入需要添加的装饰器名称
    def dispatch_request(self):
        return '登录成功'

app.add_url_rule('/classwrap/',view_func=UseDecorator.as_view('classwrap'))

@app.route('/')
def hello():
    return 'hello world'

if __name__ == "__main__":
    app.run(debug=True)