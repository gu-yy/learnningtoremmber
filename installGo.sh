#!/bin/bash
#首先去https://golang.google.cn/dl/下载Go源码到当前目录，例如下载的是go1.11.11.linux-amd64.tar.gz
#解压到/usr/local目录下，解压后的目录为go
tar -C /usr/local -xzf go1.11.11.linux-amd64.tar.gz
#导入环境变量
echo "export PATH=\$PATH:/usr/local/go/bin" >> /etc/profile
echo "export GOPATH=/opt/gopath" >> /etc/profile
#使环境变量生效
source /etc/profile
echo $PATH
go version

