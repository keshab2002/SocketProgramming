#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>

int main(){

	/* Unlinking server path */
	unlink("server_socket");

	/* Initializing server address */
	struct sockaddr_un server_address, client_address;
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "server_socket");

	/* creating socket */
	int server_sockfd, client_sockfd;
	server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	/* Binding */
	int server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len );

	/*Listening*/
	listen(server_sockfd, 5);

	/* Managing clients */
	while(1){
		printf("Waiting for client...");

		/* Accepting client */
		int client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);

		/* Reading */
		char ch;
		read(client_sockfd, &ch, 1);

		/* Writing */
		ch++;
		write(client_sockfd, &ch, 1);

		close(client_sockfd);
	}

	exit(EXIT_SUCCESS);
}
