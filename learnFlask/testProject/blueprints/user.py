from flask import Blueprint

userBp=Blueprint('user',__name__,url_prefix='/user')

@userBp.route('/profile/')
def profile():
    return '这是个人信息设置页面'

@userBp.route('/detail/')
def detail():
    return '这是详细信息页面'