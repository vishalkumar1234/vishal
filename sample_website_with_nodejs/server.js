var http = require('http');
var fs = require('fs');



http.createServer(function(request,response){
	var url = request.url;
	switch(url){

		case '/':
		  getStaticFileContent(response,'public/home.html','text//html');
		  break;


		case '/about':
		  getStaticFileContent(response,'public/about.html','text//html');
		  break;

		case '/contact':
		  getStaticFileContent(response,'public/contact.html','text//html');
		  break;


		default:
		reponse.writeHead(404,{'content-Type':'text-plain'});
		   }
}).listen(8080);
console.log('server running at http://localhost:8080');



function getStaticFileContent(response,filepath,contentType){
	 fs.readFile(filepath,function(error,data){
		if(error){
			response.writeHead(500,{'content-Type':'text-plain'});
			response.end('500'-'internal server error');
		 }
		if(data){
			response.writeHead(200,{'content-Type':'text-plain'});
			response.end(data);
		} 

	});
}




