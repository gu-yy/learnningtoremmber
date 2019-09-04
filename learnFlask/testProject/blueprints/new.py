from flask import Blueprint

newsBp=Blueprint('news',__name__,url_prefix='/news')

@newsBp.route('/message/')
def message():
    return 'I love you'

