const 
    crypto=require('crypto'),
    fs=require('fs');

const hash=crypto.createHash('md5');

hash.update('hello world');
hash.update('hello nodejs');
console.log(hash.digest('hex'));

function loadKey(file){
    return fs.readFileSync(file,'utf8');
}
let
    prvKey=loadKey('./rsa-prv.pem'),
    pubKey=loadKey('./rsa-pub.pem'),
    message='hello world!';
let enc_by_prv=crypto.privateEncrypt(prvKey,Buffer.from(message,'utf8'));//encrypt by private key
console.log(enc_by_prv.toString('hex'));
let dec_by_pub=crypto.publicDecrypt(pubKey,enc_by_prv);
console.log(dec_by_pub.toString('utf8'));
let enc_by_pub=crypto.publicEncrypt(pubKey,Buffer.from(message,'utf8'));
console.log(enc_by_pub.toString('hex'));
let dec_by_prv=crypto.privateDecrypt(prvKey,enc_by_pub);
console.log(dec_by_prv.toString('utf8'));
