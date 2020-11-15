#include <stdio.h>
#include <string.h>   //strlen
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr
#include <unistd.h>  //write
#include <netinet/in.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int socket_desc,new_socket,c;
	struct sockaddr_in server,client;
	char *message;
	int optval;
	socklen_t optlen = sizeof(optval);

	//Create socket
	socket_desc = socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1)
	{
		printf("Could not create socket");
	}

	/* Check the status for the keepalive option */
	if(getsockopt(socket_desc, SOL_SOCKET,SO_KEEPALIVE,&optval,&optlen)<0)  {
	perror("getsock opt()");
	close(socket_desc);
	exit(EXIT_FAILURE);
	}

	printf("SO_KEEPALIVE is %s/n", (optval? "ON" : "OFF"));

	/* Set the option active */
	optval = 1;
 	optlen = sizeof(optval);
	if(setsockopt(socket_desc,SOL_SOCKET,SO_KEEPALIVE,&optval,optlen)<0) {
	perror("setsockopt()");
	close(socket_desc);
	}
	return 0;
}
