//引入http模块
var http=require('http');
//创建服务器，参数是一个回调函数，表示如果有请求进来，要做什么
var server=http.createServer(function(req,res){
	//设置http头部，状态码是200，文件类型是html，字符集是utf8
	res.writeHead(200,{"Content-type":"text/html;charset=UTF-8"});
	res.end('hello world');
}).listen(4396,'127.0.0.1');
