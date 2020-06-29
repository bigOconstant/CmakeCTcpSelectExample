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
#include <string.h>
#include "tcp_connection.h"
#include "server.h"

int max(int x, int y) 
{ 
    if (x > y) 
        return x; 
    else
        return y; 
}

 static void Run(struct Server* S){
     printf("Begin call run!\n");
     listen(S->one->file_descriptor,SOMAXCONN);
     listen(S->two->file_descriptor,SOMAXCONN);    
    
      FD_ZERO(&S->rset);

      
        // get maxfd 
        S->maxfdp1 = max(S->one->file_descriptor,S->two->file_descriptor) + 1;
      
      while(1) {
                
            FD_SET(S->one->file_descriptor,&S->rset);
            FD_SET(S->two->file_descriptor,&S->rset);
            S->nready =  select(S->maxfdp1,&S->rset,NULL,NULL,NULL);
            
            if(FD_ISSET(S->one->file_descriptor, &S->rset)) {
                            //tcp1 ready
                printf("connection on port %d\n",S->one->port);
                S->len = sizeof(S->one->cliaddr);
                S->connfd = accept(S->one->file_descriptor,(struct sockaddr*)&S->one->cliaddr, &S->len);
                if((
                    S->childpid = fork()) == 0) {
                        // fork and deal with the message in another process
                        close(S->one->file_descriptor);
                       
                        memset(&S->one->buffer[0], 0, strlen(S->one->buffer));
                        read(S->connfd,S->one->buffer,sizeof(S->one->buffer));
                        puts(S->one->buffer);
                        write(S->connfd,(const char*)S->one->message,strlen(S->one->message));
                        close(S->connfd);
                        exit(0);
                
                }
                close(S->connfd);
            }
            
             if(FD_ISSET(S->two->file_descriptor, &S->rset)) {
                            //tcp1 ready
                 printf("connection on port %d\n",S->two->port);
                S->len = sizeof(S->two->cliaddr);
                S->connfd = accept(S->two->file_descriptor,(struct sockaddr*)&S->two->cliaddr, &S->len);
                if((
                    S->childpid = fork()) == 0) {
                        // fork and deal with the message in another process
                        close(S->two->file_descriptor);
                       
                        memset(&S->two->buffer[0], 0, strlen(S->two->buffer));
                        read(S->connfd,S->two->buffer,sizeof(S->two->buffer));
                        puts(S->two->buffer);
                        write(S->connfd,(const char*)S->two->message,strlen(S->two->message));
                        close(S->connfd);
                        exit(0);
                
                }
                close(S->connfd);
            }
      }
 }
 
struct Server* New_Server(int port1, int port2){
      printf("Calling new server!\n");
        struct Server* retVal = malloc(sizeof(struct Server));
        retVal->one = New_TcpConnection(port1);
        retVal->two = New_TcpConnection(port2);
        retVal->Run = Run;
        return retVal;
    
}
