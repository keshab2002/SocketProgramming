#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/un.h>
#include<sys/socket.h>


int main(){

	/* Unlinking path if linked */
	unlink("server_socket");

	/* defining server and client address */
	struct sockaddr_un server_address, client_address;
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "server_socket");

	/*Creating socket*/
	int server_sockfd, client_sockfd;
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	/* Binding socket */
	int server_len, client_len;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

	/*LListening the client*/
	listen(server_sockfd, 5);

	/* Client handeling */
	while(1){
		printf("Server Waiting for client: ");
		/* Accepting the client */
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);

		/* Reading from client: */
		char ch;
		read(client_sockfd, &ch, 1);
		ch++;

		/*Writing message to client*/
		write(client_sockfd, &ch, 1);

		/*Closing client*/
		close(client_sockfd);
	}

	exit(EXIT_SUCCESS);
}
