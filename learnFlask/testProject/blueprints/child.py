from flask import Blueprint

childBp=Blueprint('child',__name__,subdomain='child')

@childBp.route('/')
def helloGyy():
    return 'hello gyy'