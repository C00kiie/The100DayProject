#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc, char **argv )
{
	// domain, method, path 
	if (argc < 4){
		printf("usage: %s $domain $port $method $path", argv[0]);; exit(-1);
	}

	int port_no = atoi(argv[2]);
	char* hostname = argv[1];
	char* method = argv[4]; 
	char* path = argv[3];
	char* request_fmt = "%s %s HTTP/1.0\r\n\r\n";

	
	
	
	
	// setup request
	// sockaddr_in & hostent struct
	struct sockaddr_in serv_addr;	
	struct hostent *server;
	int bytes, received, sent, total;
	char message [1024];
	char response[1024 * 100]; // 100MB buffer, I mean we all hate static allocation but this is for simplicity
	// formatting output
	sprintf(message, request_fmt, method, path); 
	
	printf("requesting %s",message);
	// setup a socket
	int socketfd = socket(AF_INET, SOCK_STREAM,0);
	if (socketfd < 0) error("Unable to init socket");

	// resolve server IP
	server = gethostbyname(hostname);
	if(server == NULL) error("Error no such host");
	
	// fill structures
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);

	// copy address from resolver to socket
	memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
	
	
	// connecting
	if (connect(socketfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
	// if connected, send our message :D

	
	    /* send the request */
    	total = strlen(message);
    	sent = 0;
    	do {
        bytes = write(socketfd,message+sent,total-sent);
        if (bytes < 0) {
	 	error("ERROR writing message to socket");
	}
	if (bytes == 0){
        	break;
	}
        sent+=bytes;
    	
	} while (sent < total);

	// now recieve the response 
	
	memset(response,0,sizeof(response));
    	total = sizeof(response)-1;
    	received = 0;
    	do {
        bytes = read(socketfd,response+received,total-received);
        if (bytes < 0)
            error("ERROR reading response from socket");
        if (bytes == 0)
            break;
        received+=bytes;
	} while (received < total);	

	if (received == total){
		error("Unable all the stuff in my 4MB Buffer");
	}

	// close socket, print response
	close(socketfd);
	printf("%s",response);
}
