//Networking C code from:
// https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 32
#define PORT 1336
#define SA struct sockaddr
  
// function which handles input and output over the socket
void target_function(int sockfd)
{
    struct {
    	char buff[MAX];
    	volatile int printflag;
    } targets;


    for (;;) {
        bzero(targets.buff, MAX);
  	
	write(sockfd, "Give me deadbeef: ", 18);

        targets.printflag = 0;
        read(sockfd, targets.buff, 100);
        
        printf("From client: %s\t ", targets.buff);
        bzero(targets.buff, MAX);
  
  
        if (targets.printflag == 0xdeadbeef) {
            write(sockfd, "Thank you!\nflag{*****************}", 34);
            break;
	}
	else if (targets.printflag != 0) {
	    write(sockfd, "Buffer Overflow, but not with 0xdeadbeef", 40);
            break;	
        }
    }
}
  

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
  
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
  
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
  
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
  
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
  
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");
  
    // target function handles input and output
    target_function(connfd);
  
    // After chatting close the socket
    close(sockfd);
}
