from flask import Flask

app=Flask(__name__)

@app.route('/')
def helloWorld():
    return "hello world"

@app.route('/g/<params>/')
# url中最后一个斜杠最好加上，因为当不加这个斜杠的时候，在浏览器中手动传入了斜杠会报错
# 当加上斜杠以后，如果在浏览器中手动传入斜杠直接可以运行，当忘记手动传入斜杠，浏览器会自动帮助加上斜杠
# url中有多少参数，那么下面这函数的参数列表中就必须传入这些参数
def paramsFunc(params):
    return params

@app.route('/u/<uuid:userID>')
def user(userID):
    return userID
#此时urlPath可以取params1和params2中任意一个
@app.route('/<any(params1,params2):urlPath>/<int:id>')
def anyUrl(urlPath,id):
    return urlPath+str(id)

import uuid
print(uuid.uuid4()) #返回一个uuid

if __name__=='__main__':
    app.run(debug=True)
