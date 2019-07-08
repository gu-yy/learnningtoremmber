#!/bin/bash

#安装docker
wget -qO- https://get.docker.com/ | sh
#启动docker后台服务
service docker start
docker --version
#将当前普通用户加入docker用户组
groupadd docker
gpasswd -a ${USER} docker
service docker restart
#增加组权限
chmod a+rw /var/run/docker.sock
#运行hello-world镜像
docker run hello-world
