var a=['a','b','c'];
var s=new Set(['a','b','c']);
var m=new Map([[1,'x'],[2,'y'],[3,'z']]);
console.log('traversing the array with all information');
a.forEach(function(element,index,array){
    //element:指向当前元素的值
    //index:指向当前索引
    //array:指向array对象本身
    console.log('value='+element+',index='+index+',object='+array);
})
console.log('traversing the set with all information');
s.forEach(function(element,sameElement,set){
    //element和sameElement都是Set中保存的key，因为Set只有key没有value
    //set:指向set对象本身
    console.log('key='+element+',object'+set);
})
console.log('traversing the map with all information');
m.forEach(function(value,key,map){
    //value:指向当前键的值
    //key:指向当前的键
    //map:指向map对象本身
    console.log('value='+value+',key='+key+',map'+map);
})
//当不需要某些参数的时候，也可以省略那些参数
console.log('traversing the map with key and value');
m.forEach(function(value,key){
    //只获取element
    console.log('value='+value+',key='+key);
})
