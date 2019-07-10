function inherits(Child,Parent){
    var F=function(){};
    F.prototype=Parent.prototype;
    Child.prototype=new F();
    Child.prototype.constructor=Child;
}

function Student(props){
    this.name=props.name||'Unnamed';
}
Student.prototype.hello=function(){
    return this.name;
}
function PrimaryStudent(props){
    Student.call(this,props);
    this.grade=props.grade||1;
}

inherits(PrimaryStudent,Student);   
PrimaryStudent.prototype.getGrade=function(){
    return this.grade;
}

var gyy=new PrimaryStudent({
    name:'gyy',
    grade:13
})
console.log(gyy.hello());
console.log(gyy.getGrade());
