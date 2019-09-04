from sqlalchemy import create_engine,Integer,Float,String,Column,Text,and_,or_
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

HOSTNAME='127.0.0.1'
PORT="3306"
DATABASE="gyy"
USERNAME="root"
PASSWORD="98782343"
DB_URI="mysql+pymysql://{username}:{password}@{host}:{port}/{database}?charset=utf8".format(username=USERNAME,
password=PASSWORD,host=HOSTNAME,port=PORT,database=DATABASE)

engine=create_engine(DB_URI)
Base=declarative_base(engine)
session=sessionmaker(engine)()

class Article(Base):
    __tablename__='article'
    id=Column(Integer,primary_key=True,autoincrement=True)
    title=Column(String(50),nullable=False)
    price=Column(Float,nullable=False)
    content=Column(Text)

    def __repr__(self):
        return '%d+%s+%d' % (self.id,self.title,self.price)

# 这种filter查询方式直接使用类中的属性，所以适合更加复杂的查询
# session.query(Article).filter(Article.id==1)
# 这种filter查询通过传入一个关键字参数，虽然形式简单，但是不适合用作复杂的查询
# session.query(Article).filter_by(id=1)
# 记住，后面不加first()或者all()，那么最后打印出来的就是sql语句
# equal
article=session.query(Article).filter(Article.id==2).all()
print(article)
# not equal
articles=session.query(Article).filter(Article.id!=1).first()
print(articles)
# like          sql中%表示匹配所有的字符串
#  ilike和like功能一样，但是ilike不区分大小写
articles=session.query(Article).filter(Article.title.like('tit%')).all()
print(articles)
# in,在这里使用in_的原因是python中有关键字in，_不加在in前面是因为加在前面就变成私有方法了，注意in_()的参数是一个列表哦～～～
articles=session.query(Article).filter(Article.id.in_([2,7])).all()
print(articles)
# not in，在前面加一个~，就表示not，另一种方法就是notin_()
articles=session.query(Article).filter(~Article.id.in_([2,7])).all()
print(articles)
articles=session.query(Article).filter(Article.id.notin_([2,7])).all()
print(articles)
# is null
articles=session.query(Article).filter(Article.content==None).all()
print(articles)
#is not null 
articles=session.query(Article).filter(Article.content!=None).all()
print(articles)
# and，第一种方式直接使用逗号将条件隔开，第二种方法是使用from sqlalchemy import and_ 
articles=session.query(Article).filter(Article.content=='gyyyy',Article.title=='abc').all()
print(articles)
articles=session.query(Article).filter(and_(Article.content=='gyyyy',Article.title=='abc')).all()
print(articles)
# or_就必须使用函数or_()了
articles=session.query(Article).filter(or_(Article.content=='gyyyy',Article.title=='abc')).all()
print(articles)