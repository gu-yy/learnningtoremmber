function Cat(name) {
    this.name=name;
    this.say=function(){
        return 'Hello, '+this.name+'!';
    }
        //
    }
    /*
    Cat.prototype.say=function(){
      //console.log('Hello, '+this.name+'!');
      return 'Hello, '+this.name+'!';
    }*/
var kitty=new Cat('Kitty');
var doramon=new Cat('aaaaa');
//console.log(kitty&&kitty.name);
//console.log(kitty.say&&typeof kitty.say);
console.log(kitty.say());
console.log(doramon.say());
console.log(kitty.say===doramon.say);
//console.log(kitty.say);
//console.log(doramon.say);    
//console.log(kitty.say===doramon.say);
//console.log(kitty && kitty.name === 'Kitty'&& kitty.say && typeof kitty.say === 'function' && kitty.say() === 'Hello, Kitty!' );


function testaa(gyy){
    return gyy||'abc';
}
var tmp='hh'||'a';
console.log(testaa(tmp));

//console.log('window inner size: ' + window.innerWidth + ' x ' + window.innerHeight);