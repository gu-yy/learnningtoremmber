var Student={
    name:'  Robot',
    height:1.2,
    run:function(){
            console.log(this.name+' is running...');
    }
}
function createStudent(name){
    var s=Object.create(Student);//基于Student原型创建一个新对象
    s.name=name;//初始化新对象
    return s;
}
var me=createStudent('gyy');
me.run();


function Student1(props) {
    this.name = props.name || '匿名'; // 默认值为'匿名'
    this.grade = props.grade || 1; // 默认值为1
}

Student1.prototype.hello = function () {
    console.log('Hello, ' + this.name + '!')
};

function createStudent1(props) {
    return new Student1(props || {})
}
var xiaoming=createStudent1({name:'xiaoming'});
xiaoming.hello();

//var tmp={name:'gyy'};
var tmp='gyy';
console.log(tmp||{});