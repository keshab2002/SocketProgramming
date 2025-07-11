#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<termios.h>
#include<pthread.h>


int sockfd;

void * send_message(void *a);
void * recive_message(void *b);

int main(){

	/*address*/
	struct sockaddr_in address;
	address.sin_port = htons(8010);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("107.0.0.1");

	/*socket*/
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/*connect*/
	int addr_len = sizeof(address);
	int result = connect(sockfd, (struct sockaddr*)&address, addr_len);
	if(result == -1){
		printf("Failure...");
		exit(EXIT_FAILURE);
	}


	/*chat handeling*/
	pthread_t send, recive;

	pthread_create(&send, NULL, &send_message, NULL);
	pthread_create(&recive, NULL, &recive_message, NULL);

	pthread_join(send, NULL);
	pthread_join(recive, NULL);

	close(sockfd);

	exit(EXIT_FAILURE);
}

void * send_message(void *a){


}


void * recive_message(void *b){

}
