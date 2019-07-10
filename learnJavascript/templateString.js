var a=['A','B','C'];
//var s=new Set(['a','b','c']);
var s=new Set(a);
var m=new Map([[1,'x'],[2,'y'],[3,'z']]);

console.log('traversing the array');
for(var x of a){
        console.log(x);
}

console.log('traversing the set');
for(var x of s){
        console.log(x);
}
console.log('traversing the map');
for(var x of m){
        console.log(x);
}
var key=1;
console.log(m.get(key));

