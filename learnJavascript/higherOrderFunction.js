'use stric';
function add(x,y,f){
    return f(x)+f(y);
}
console.log(add(-5,6,Math.abs));//Math,abs是求绝对的函数

function pow(x){
    return x*x;
}

//map
var arr=[1,2,3,4,5,6,7,8,9];
var result=arr.map(pow);
console.log(result);

//reduce
var arr1=[1,3,5,7,9];
var tmp=arr1.reduce(function(x,y){
    return x*y;
})
console.log(tmp);

//filter
var arr2=[1,2,3,4,5,6,7,8,9,10];
var result1=arr2.filter(function(x){
    return x%2===0;
})
console.log(result1);

//sort
var arr3=[10,20,1,1,3];
arr3.sort(function(x,y){
    if(x>y){
        return 1;
    }
    if(x<y){
        return -1;
    }
    return 0;
})
console.log(arr3);