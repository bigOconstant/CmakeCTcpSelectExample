#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 
#include <errno.h> 
#include <netinet/in.h> 
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <strings.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>

#include "tcp_connection.h"

struct Tcp_connection* New_TcpConnection(int port){
    printf("Creating new tcpConnection!\n");
    
        struct Tcp_connection* retVal = malloc(sizeof(struct Tcp_connection));
        retVal->port = port;
        bzero(&retVal->server_address,sizeof(retVal->server_address));
        retVal->server_address.sin_family = AF_INET;
        retVal->server_address.sin_addr.s_addr = htonl(INADDR_ANY);
        retVal->server_address.sin_port = htons(port);
        retVal->MAXLINESIZE = 1024;
        retVal->buffer = (char*) malloc(retVal->MAXLINESIZE * sizeof(char));
        char* message = "Hello Client!\n";
        retVal->message = message;
        
        retVal->file_descriptor =   socket(AF_INET,SOCK_STREAM,0);
        
        int bindworked = bind(retVal->file_descriptor,(struct sockaddr*)&retVal->server_address,sizeof(retVal->server_address));
        printf("binding worked!\n");
        if(bindworked){
            printf("tcp connection port:%d not free\n",port);
            exit(1);
        }
        
        return retVal;
    
}
