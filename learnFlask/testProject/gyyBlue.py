from flask import Blueprint

gyyBp=Blueprint('gy',__name__)

@gyyBp.route('/gyy/')
def gyy():
    return 'gyy'