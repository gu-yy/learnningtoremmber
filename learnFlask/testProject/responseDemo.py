from flask import Flask,Response,jsonify

app=Flask(__name__)

class JSONResponse(Response):       #继承自Response
    @classmethod        #force_type()是一个类方法
    def force_type(cls,response,environ=None):
        if isinstance(response,dict):
            response=jsonify(response)
        #return response
        return super().force_type(response,environ)

app.response_class=JSONResponse

@app.route('/')
def hello():
    return {'a':'gyy','b':16}

if __name__ == "__main__":
    app.run(debug=True)
    