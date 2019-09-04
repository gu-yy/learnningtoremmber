from flask import Flask,render_template
#导入时间模块
from datetime import datetime   

app=Flask(__name__)

@app.route('/')
def hello():
    return 'hello gyy'

@app.route('/default/')     #default过滤器
def fliterDefault():
    context={
        'name':'gyy',
        'signature':'我是顾大哥',
        'escapestring':'<script>alert("hello")</script>',
        'seq':['a','b','c'],
        'mystring':'abcaabbcc',
        'createTime':datetime(2018,8,21,15,2,0)
    }
    return render_template('filterIndex.html',num=-1,**context)

@app.template_filter('myFilter')
def myFilter(value):
    return value.replace('a','')

@app.template_filter('myTimer')
def myTimer(time):
    '''
        1分钟之内就是刚刚
        1小时内就是多少分钟之前
        1天之内就是多少小时之前
        1个月就是多少天之前
        大于一个月就打印真正之间
    '''
    #判断参数time是不是时间格式
    if isinstance(time,datetime):
        #获取系统当前时间
        now=datetime.now()
        #将当前时间减去创建时间，并且计算他们之间相差的秒数
        timeInterval=(now-time).total_seconds()
        if timeInterval<60:
            return "刚刚"
        elif timeInterval >=60 and timeInterval<60*60:
            minutes=timeInterval//60
            return "%s分钟前" % int(minutes)
        elif timeInterval>=60*60 and timeInterval<60*60*24:
            hours=timeInterval//(60*60)
            return "%s小时前" % int(hours)
        elif timeInterval>=60*60*24 and timeInterval<60*60*24*30:
            days=timeInterval//(60*60*24)
            return "%s天前" % int(days)
        else:
            #将datetime类型的时间按照%Y/%m/%d  %H:%M:%S格式化
            return time.strftime("%Y/%m/%d  %H:%M:%S")
    else:
        return time

if __name__ == "__main__":
    app.run(debug=True)