#!/bin/bash
#下载nodejs8.9.0版
wget https://nodejs.org/dist/v8.9.0/node-v8.9.0-linux-x64.tar.xz 
mkdir -p /usr/local/lib/nodejs
tar -xJvf node-v8.9.0-linux-x64.tar.xz -C /usr/local/lib/nodejs
#添加环境变量
echo "export PATH=/usr/local/lib/nodejs/node-v8.9.0-linux-x64/bin:\$PATH" >> ~/.profile
#更新
source ~/.profile

node -v 
npm version
npx -v

ln -s /usr/local/lib/nodejs/node-v8.9.0-linux-x64/bin/node /usr/bin/node
ln -s /usr/local/lib/nodejs/node-v8.9.0-linux-x64/bin/npm /usr/bin/npm
ln -s /usr/local/lib/nodejs/node-v8.9.0-linux-x64/bin/npx /usr/bin/npx

#跟新npm版本
npm install npm@5.6.0 -g
