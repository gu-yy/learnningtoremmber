//请求Node.js自带的http模块，将它赋值给变量http
var http=require('http');

//调用http模块的方法createServer，这个方法会返回一个对象，然后调用返回对象的listen方法，listen方法的参数是监听的端口号
http.createServer(function(request,response){
	//createServer方法通过request和response参数来接收和响应数据
	//返回值首先是http的头部，例如版本，状态码404或者200等
	//然后是内容类型
	response.writeHead(200,{'Content-Type':'text/plain'});

	//发送响应数据
	response.end('hello world\n');
}).listen(4396)

console.log('Server running at http://127.0.0.1:4396/');
