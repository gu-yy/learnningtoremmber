'use strict';
function foo(){
    var sum=0;
    for(var i=0;i<10;i++){
        sum+=i;
    }
    sum+=i;
    return sum;
}
function bar(){
    var sum=0;
    for(let i=0;i<10;i++){
        sum+=i;
    }
    var i=10;
    sum+=i;
    return sum;
}
console.log('var');
console.log(foo());
console.log('let');
console.log(bar());

