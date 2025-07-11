#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){

	/*assign address*/

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(8001);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	

	/* creating socket */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Try to connect with server */
	int addr_len = sizeof(address);
	int result = connect(sockfd, (struct sockaddr*)&address, addr_len);
	if(result == -1){
		printf("OOPS! Client...\n");
		exit(EXIT_FAILURE);
	}


	/* write */
	char ch = 'K';
	write(sockfd, &ch , 1);

	/*read*/
	read(sockfd, &ch, 1);
	printf("Message from server: %c\n", ch);

	close(sockfd);


	exit(EXIT_SUCCESS);
}
