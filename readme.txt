需要对$PATH转义，就是在$前面加一个/
在之后，还要重新将普通用户加入到docker的用户组里面:
#将当前普通用户加入docker用户组
groupadd docker
gpasswd -a ${USER} docker
service docker restart
#增加组权限
chmod a+rw /var/run/docker.sock

