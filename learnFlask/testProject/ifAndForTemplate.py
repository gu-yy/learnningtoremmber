from flask import Flask,render_template

app=Flask(__name__)

@app.route('/')
def hello():
    context={
        'name':'gyy22',
        'users0':[],
        'users':['user1','user2','user3'],
        'message':{
            'name':'gyy',
            'sex':'male',
            'age':18
        },
        'books':{
            'book1':{
                'name':'斗破苍穹',
                'comment':'垃圾',
                'content':'屎'
            },
            'book2':{
                'name':'武动乾坤',
                'comment':'贼垃圾',
                'content':'一堆屎'
            },
            'book3':{
                'name':'大主宰',
                'comment':'真的垃圾',
                'content':'全是屎'
            },
            'book4':{
                'name':'唐家三少',
                'comment':'写的啥',
                'content':'这三本书好像不是唐家三少写的？'
            }
        }
    }
    return render_template('ifAndForIndex.html',**context)

if __name__ == "__main__":
    app.run(debug=True)