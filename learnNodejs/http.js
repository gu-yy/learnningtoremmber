var http=require('http');
var url=require('url');
//创建一个服务器
var server=http.createServer(function(req,res){
    //写一个返回头部
    res.writeHead(200,{
        'Content-Type':'text/plain;charset=UTF-8'
    })
    //写内容
    res.write('my name is gyy\n');
    res.write(url.parse(req.url).pathname+'\n');
    //写结束
    res.end('the responce from the http server'+req.url);
})


//监听端口
server.listen(4396,'127.0.0.1');