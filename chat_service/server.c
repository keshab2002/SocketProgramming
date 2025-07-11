#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<termios.h>


int client_sockfd;

void * send_message(void * a);
void * recive_message(void * b);

int main(){

	/* Assigning address */
	struct sockaddr_in server_address, client_address;

	server_address.sin_port = htons(8005);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* Creating socket */
	int server_sockfd = socket(AF_INET, SOCK_STREAM , 0);

	/*Binding*/
	int server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

	/*Listening*/
	listen(server_sockfd, 5);

	/*Managing client*/
	int client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);

	pthread_t send, recive;

	pthread_create(&send, NULL, send_message, NULL);
	pthread_create(&recive, NULL, recive_message , NULL);

	pthread_join(send, NULL);
	pthread_join(recive, NULL);

	/*closing client socket*/
	close(client_sockfd);

	exit(EXIT_SUCCESS);
}



void * send_message(void * a){
	char str[1024];
	while(1){
		printf("Enter your message: ");
		fgets(str, sizeof(str), stdin);
		write(client_sockfd, &str, sizeof(str));
		if (strcmp(str, "bye") == 0){
			break;
		}
	}
	pthread_exit(NULL);
}


void * recive_message(void * b){
	char str[1024];
	while(1){
		read(client_sockfd, &str, sizeof(str));
		printf("Message from client: %s\n", str);
		if(strcmp(str, "bye") == 0)
			break;
	}
	pthread_exit(NULL);
}
