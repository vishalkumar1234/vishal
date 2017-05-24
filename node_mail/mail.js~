var nodemailer = require('nodemailer');
var smtpTransport = require('nodemailer-smtp-transport');
//Fill out SMTP credentials
var transport = nodemailer.createTransport(smtpTransport({
service: 'Gmail',
host : 'smtp.gmail.com',
secureConnection: true,
port : 465,
auth:{
user : "shetyv@gmail.com", //username
pass : "vishalkumar9155221587" //password
}
}));
//
var msg = {
transport : transport,
text : "hi ankita how are you from Node.js" , //Message
from : "<shetyv@gmail.com>", //From
subject : "Node Mail Testing" //Subject
};
// List of Receivers
var maillist = [
'<vishalsistec0187@gmail.com>,<ankitakumariverma30@gmail.com>'
]
transport.verify(function(error, success) { //Verify the conncetion
if (error) {
console.log(error);
}
else {
console.log('Server is ready to take our messages');
maillist.forEach(function(to,i){
msg.to = to;
transport.sendMail(msg,function(err){ //Mail
if(err){
console.log("not send");
return;
}
console.log('Send to ' + to);
});
});
}
});

