#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>

int main(){

	/* Creating the socket */
	int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	/* Address */
	struct sockaddr_un address;
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_path");

	/*Connect*/
	int addr_len = sizeof(address);
	int result = connect(sockfd, (struct sockaddr*)&address, addr_len);
	if(result == -1){
		printf("OOPS! CLient...");
		exit(EXIT_FAILURE);
	}

	/*write and read */
	char ch = 'K';
	write(sockfd, &ch, 1);
	read(sockfd,&ch, 1);
	printf("Recived character from server: %c\n", ch);

	close(sockfd);
	

	exit(EXIT_SUCCESS);
}
