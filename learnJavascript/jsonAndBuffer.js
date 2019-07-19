var gyy={
    name:'gy',
    age:18,
    address:{
        city:'wuhan',
        street:'luoyulu'
    }
};

var s0=JSON.stringify(gyy);
console.log(s0);
var s1=Buffer.from(s0);
var s2=JSON.parse(s1);
console.log(s2);

var issuer='gyy';
var paperNumber=10;
var result=[issuer,paperNumber].map(part=>JSON.stringify(part)).join(',');
console.log(result);
var result2=result.split(',');
console.log(result2);