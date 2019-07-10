'use strict';
function abs(){
    if(arguments.length===0){
            return 0;
    }
    for(var i=0;i<arguments.length;i++){
            console.log(arguments[i]);
    }
    return 0;
}
abs();
abs(1,2);
abs(1,'ab',null);

console.log('test the variable rest');
function foo(a,b,...rest){
    console.log('a='+a+',b='+b);
    console.log('rest='+rest);
}
foo(1,2,3,4,5);
foo(1);

var Bob={
    name:'Bob',
    birth:1995,
    age:function(){
        var y=new Date().getFullYear();
        return y-this.birth;
    }
};
console.log(Bob.age);//output the function which is transfered
console.log(Bob.age());//output the age of Bob through the function age

function getAge(){
    var y=new Date().getFullYear();
        return y-this.birth;
}
var Alice={
    name:'alice',
    birth:1996,
    age:getAge
};
console.log(Alice.age());
console.log(getAge.apply(Alice,[]));
console.log(getAge.call(Alice));
