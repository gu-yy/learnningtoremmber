function* fib(max){
    var [a,b,n]=[0,1,0];
    while(n<max){
            yield a;
            [a,b]=[b,a+b];
            n++;
    }
    return;
}
var f=fib(5);
console.log(f.next());
for(var x of f){
    console.log(x);
}
