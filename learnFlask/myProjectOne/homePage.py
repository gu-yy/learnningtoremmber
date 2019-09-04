from flask import Flask,render_template,request

app=Flask(__name__)

gyy={
    'movies':[
    {
        'name':'速度与激情',
        'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2561542272.webp',
        'score':7.5
    },
    {
        'name':'寄生虫',
        'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2561439800.jpg',
        'score':8.7
    },
    {
        'name':'极速备战',
        'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2551393832.jpg',
        'score':7.9
    },
    {
        'name':'金手套',
        'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2547964504.jpg',
        'score':6.3
    },
    {
        'name':'夜幕猎人',
        'url':'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2535436769.jpg',
        'score':6.2
    },
    {
        'name':'复仇',
        'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2565165033.jpg',
        'score':6.4
    },
],
    'tvs':[
            {
                'name':'小欢喜',
                'url':'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2564832427.jpg',
                'score':8.3
            },
            {
                'name':'致命女人',
                'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2566967861.jpg',
                'score':9.4
            },
            {
                'name':'自然而然',
                'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2564482176.jpg',
                'score':8.6
            },
            {
                'name':'十三个原因',
                'url':'https://img1.doubanio.com/view/photo/s_ratio_poster/public/p2566909007.jpg',
                'score':6.9
            },
            {
                'name':'陈情令',
                'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2563766934.jpg',
                'score':8.0
            },
            {
                'name':'轮到你了',
                'url':'https://img3.doubanio.com/view/photo/s_ratio_poster/public/p2553707144.jpg',
                'score':8.7
            },
    ]
}


@app.route('/')
def home():
    return render_template('homePage.html',**gyy)

@app.route('/list/')
def listPage():
    number=request.args.get('number')
    if int(number)==1:
        return render_template('listPage.html',number=1,**gyy)
    else:
        return render_template('listPage.html',number=2,**gyy)

if __name__ == "__main__":
    app.run(debug=True)