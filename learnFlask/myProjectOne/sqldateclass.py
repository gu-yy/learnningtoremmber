from sqlalchemy import create_engine,Column,Integer,Float,Boolean,DECIMAL,Enum,Date,DateTime,Time,String,Text
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.dialects.mysql import LONGTEXT
#这个主要用来与数据库交互，包括增删查改
from sqlalchemy.orm import sessionmaker       
#这个只有python3中才有
import enum  
from datetime import date,datetime,time

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

class myEnum(enum.Enum):
    python='python'
    flask='flask'
    jinja2='jinja2'

class Gyy(Base):
    __tablename__='guyuanyi'
    id=Column(Integer,primary_key=True,autoincrement=True)
    price=Column(Float)
    isDelete=Column(Boolean)
    priceDetail=Column(DECIMAL(10,5))
    language=Column(Enum(myEnum))
    myDate=Column(Date)
    myDateTime=Column(DateTime)
    myTime=Column(Time)
    myString=Column(String(50))
    myText=Column(Text)
    myLongText=Column(LONGTEXT)

Base.metadata.drop_all()
Base.metadata.create_all()

gyy=Gyy(price=5.20,isDelete=True,priceDetail=6666.66666,language=myEnum.flask,myDate=date(2019,9,1),
myDateTime=datetime(2019,9,2,11,11,11),myTime=time(12,12,12),myString='abc',myText='def',myLongText='ijk')
session.add(gyy)
session.commit()

