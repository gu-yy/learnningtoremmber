var gyy={
    name:'gyy',
    age:14,
    skills:['c/c++','java','js'],
    address:{
        city:'wuhan',
        street:'luoyulu'
}
}
//var s=JSON.stringify(gyy,null,' ');
//console.log(s);
function convert(key,value){
    if(typeof value==='string'){
            return value.toUpperCase();
    }
    return value;
}
var s=JSON.stringify(gyy,convert,' ');
console.log(s);
var gy={
    name:'gyy',
    age:18,
    gender:'male',
    toJSON:function(){
            return{
                    'Name':this.name,
                    'Age':this.age,
            }
    }
}
var ss=JSON.stringify(gy,null,' ');
console.log(ss);