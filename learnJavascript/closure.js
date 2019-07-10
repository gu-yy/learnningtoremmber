function lazy_sum(arr){
    var sum=function(){
        return arr.reduce(function(x,y){
            return x+y;
        })
    }
    return sum;
}
var f=lazy_sum([1,2,3,4,5]);
console.log(f());

function count(){
    var arr1=[];
    for(var i=1;i<=3;i++){
        arr1.push(function(){
            return i*i;
        })
    }
    return arr1;
}
var result=count();
var f1=result[0];
var f2=result[1];
var f3=result[2];
console.log(f1());
console.log(f2());
console.log(f3());
/*
上面3个输出都是16，因为在执行语句var result=count()的时候，就已经在执行1到3的循环了，所以数组arr1中三个元素
是三个函数，并且如果执行函数返回的结果都是i*i，注意是i*i，然后当循环结束以后，已经给arr1数组赋值了，然后f1,f2,f3
又是三个函数，他们被result中的元素赋值，所以是三个函数，然后此时i的值是4，最后再调用f1(),f2(),f3()的时候，返回的结果
是i*i,也就是4*4，所以结果为16
*/

function count2(){
    var arr2=[];
    for(var j=1;j<=3;j++){
        arr2.push((function(n){
            return function(){
                return n*n;
            }
        })(j));
    }
    return arr2;
}
var result2=count2();
var f4=result2[0];
var f5=result2[1];
var f6=result2[2];
console.log(f4());
console.log(f5());
console.log(f6());
/*
在这里返回的结果是1,4,9，因为这里使用了创建匿名函数并且立即执行的语法：
    (function(x){return x*x;})(3);值得注意的是前面的function必须用括号括起来，否则会报错
    所以在后面调用的f4,f5,f6的时候，执行的就不是j*j，例如，此时返回给f4的函数就是在前面的匿名函数立即执行的时候传入了参数n,
    而n和当时的j的值绑定了。
*/
