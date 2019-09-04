from sqlalchemy import create_engine,Column,Integer,Float,String,func
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
import random

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
# 类中的__repr__方法可以定制模型查询的返回结果，对于使用%模式匹配，如下必须使用小括号将后面的参数括起来哟，不然会报错
    def __repr__(self):
        return '%d+%s+%d' % (self.id,self.title,self.price)

# Base.metadata.drop_all()
# Base.metadata.create_all()

# for x in range(6):
#     article=Article(title='title%s' % x,price=random.randint(50,100))
#     session.add(article)

# session.commit()

# 查找整张表中的内容==模型查找
articles=session.query(Article).all()
for article in articles:
    print(article)
# 对于只查询表中的某些属性，返回的是对应的属性元组，(id,title)
partArticles=session.query(Article.id,Article.title).all()
for partArticle in partArticles:
    print(partArticle)

# 聚合函数
# func.count:行的统计量
queryCount=session.query(func.count(Article.id)).all()
print(queryCount)
queryCount=session.query(Article.id).first()
print(queryCount)
queryCount=session.query(func.count(Article.id)).first()
print(queryCount)
# func.avg:求平均值
queryAvg=session.query(func.avg(Article.price)).first()
print(queryAvg)
queryAvg=session.query(func.avg(Article.id)).first()
print(queryAvg)
# func.max,func.min,func.sum
# 求最大值，最小值，求和
queryMax=session.query(func.max(Article.price)).first()
print(queryMax)
queryMin=session.query(func.min(Article.price)).first()
print(queryMin)
querySum=session.query(func.sum(Article.price)).first()
print(querySum)
