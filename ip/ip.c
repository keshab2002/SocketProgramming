#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<sys/types.h>


uint32_t ip_to_int(static char *ip){
	int a, b,c, d;
	sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
	return (a<<24)|(b<<16)|(c<<8)|d ;
}

void int_to_ip  (int32_t ip, char* buffer){
	sprintf(buffer, "%d.%d.%d.%d",(ip >> 24) & 0xFF,
            (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF,
            ip & 0xFF );
}


int main(){


	char ip_str[20];
	int cidr;

	printf("Enter ip in dotted decimal format: ");
	scanf("%s", ip_str);
	scanf("%c");
	printf("Enter subnet mask in CIDR notation: ");
	scanf("%d", &c);
	
	if(cidr < 0 || cidr > 32){
		printf("Invalid cidr");
		exit(1);
	} 

	uint32_t ip = ip_to_int(ip_str);
	uint32_t mask = (cidr == 0) ? 0 : (~0U<<(32-cidr));
	uint32_t network = ip & mask;
	uint32_t host_id = ip & ~mask;
	uint32_t first_ip = network+1;
	uint32_t usable_hosts = (cidr == 32) ? 1 : (1 << (32 - cidr)) - 2;

	char net_str[20], first_ip_str[20], host_id_str[20];

	int_to_ip(network, net_str);
	int_to_ip(first_ip, first_ip_str);
	int_to_ip(host_id, host_id_str);


	printf("\n--- Subnet Info ---\n");
    printf("Network ID : %s\n", net_str);
    printf("Host ID    : %s\n", host_id_str);
    printf("First IP   : %s\n", first_ip_str);
    printf("Usable Hosts: %u\n", usable_hosts);

	exit(0);
}
