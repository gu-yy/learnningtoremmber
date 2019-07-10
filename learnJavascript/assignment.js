var [x,y,z]=['g','y','y'];
console.log(x+y+z);
var [x1,[y1,z1]]=['g',['y','y']];
console.log(x1+y1+z1);
var [,,name]=['alice','bob','gyy'];
console.log(name);
var person={
    name:'gyy',
    age:18,
    gender:'male',
    passport:'U201514848',
    school:'Chengnan Middle School',
    address:{
        city:'Wuhan',
        street:'Luoyu Road No.1037',
        zipcode:1001
    }
}
var {name,age,passport}=person;
console.log(name+'\t'+age+'\t'+passport);

//exchange value
var x1=1,y1=2;
[x1,y1]=[y1,x1];
console.log(x1+'\t'+y1);

//Quickly get the domain name and the path of the currently page
//var {hostname:domain,pathname:path}=location;

function buildDate (year,month,day,hour=0,minite=0,second=0){
    return  year+'-'+month+'-'+day+' '+hour+':'+minite+':'+second;
}
var date=buildDate(2019,7,9);
console.log(date);
