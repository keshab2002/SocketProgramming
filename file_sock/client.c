#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/un.h>
#include<unistd.h>
#include<sys/socket.h>

int main(){

	/* creating the socket */
	int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	/*assigning address*/
	struct sockaddr_un address;
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path , "server_socket");

	/*Connecting */
	int len = sizeof(address);
	int result = connect(sockfd, (struct sockaddr*)&address, len);
	if(result == -1){
		printf("OOPS: client");
		exit(EXIT_FAILURE);
	}

	/* Writing */
	int ch = 'A';
	write(sockfd, &ch  , 1);
	read(sockfd, &ch, 1);
	printf("%c\n", ch);
	close(sockfd);
	exit(EXIT_SUCCESS);
}

