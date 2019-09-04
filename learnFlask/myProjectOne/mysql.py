#from sqlalchemy import create_engine
# from flask_sqlalchemy import SQLAlchemy
from sqlalchemy import create_engine,Column,Integer,String
from sqlalchemy.ext.declarative import declarative_base

HOSTNAME="127.0.0.1"
PORT="3306"
DATABASE="gyy"
USERNAME="root"
PASSWORD="98782343"
DB_URI="mysql+pymysql://{username}:{password}@{host}:{port}/{database}?charset=utf8".format(username=USERNAME,
password=PASSWORD,host=HOSTNAME,port=PORT,database=DATABASE)


engine=create_engine(DB_URI)
# conn=engine.connect() 
# 创建一个sqlalchemy的基类，根据前面创建的数据库殷勤来创建基类
Base=declarative_base(engine)   
# create table person(id int primary key autoincrement,name varchar(50),age int)         其中autoincrement表示自增长
# 1、创建一个ORM模型，这个ORM模型必须继承自sqlalchemy给我们提供的基类
class Person(Base):
    __tablename__='person'          #创建的表的名字
# 2、在这个ORM模型中创建一些属性，来跟表中的字段进行一一映射。这些属性必须是sqlalchemy提供给我们的数据类型
    id=Column(Integer,primary_key=True,autoincrement=True)
    name=Column(String(50))
    age=Column(Integer)
# 3、将创建号的ORM模型映射到数据库中
Base.metadata.create_all()          #将所有Base的子类的ORM模型映射到创建Base基类的数据库引擎对应的数据库中
