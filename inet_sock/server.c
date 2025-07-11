#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>


int main(){

	/* creating addresses */
	struct sockaddr_in server_address, client_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");


	/* Creating the socket */
	int server_sockfd , client_sockfd ;
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0 );


	/* Bind */
	int server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

	/*listening client*/
	listen(server_sockfd, 5);

	/*Client handeling*/
	while(1){
		printf("Waiting for client...");

		/*Accepting*/
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
