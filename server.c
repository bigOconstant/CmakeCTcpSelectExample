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
#include "ServerModel.h"
#include "server.h"
#include "rdkafka.h"
#include "KafkaMessage.h"


int SendMessage(char* brokers, char* topic, char* message);

int max(struct Tcp_connection* list,int count)
{
  int max = 0;
  for(int i = 0; i < count; ++i) {
    if(list[i].file_descriptor > max) {
      max = list[i].file_descriptor;
    }
  }
  return max;

 };

 static void Run(struct Server* S){
     printf("Begin call run!\n");
     
     
    for(int i = 0; i < S->ListCount; ++i){
	  listen(S->list[i].file_descriptor,SOMAXCONN);    
     }
      FD_ZERO(&S->rset);

      
        // get maxfd
      printf("get our max!\n");
      S->maxfdp1 = max(S->list,S->ListCount) + 1;
      printf("We got our max!:%d\n",S->maxfdp1);
      while(1) {

	for(int i = 0; i < S->ListCount; ++i){
	  FD_SET(S->list[i].file_descriptor,&S->rset);
	}

          S->nready =  select(S->maxfdp1,&S->rset,NULL,NULL,NULL);


	  for(int i = 0; i < S->ListCount; ++i){
	  
            
            if(FD_ISSET(S->list[i].file_descriptor, &S->rset)) {
                            //tcp1 ready
                printf("connection on port %d\n",S->list[i].port);
                S->len = sizeof(S->list[i].cliaddr);
                S->connfd = accept(S->list[i].file_descriptor,(struct sockaddr*)&S->list[i].cliaddr, &S->len);
                if((
                    S->childpid = fork()) == 0) {
                        // fork and deal with the message in another process
                        close(S->list[i].file_descriptor);
                       
                        memset(&S->list[i].buffer[0], 0, S->list[i].MAXLINESIZE);
                        read(S->connfd,S->list[i].buffer,S->list[i].MAXLINESIZE);
                        puts(S->list[i].buffer);
                        int retvalue = SendMessage("localhost:9092", "ingest_syslogs_netdevice", S->list[i].buffer);
                        printf("retvalue:%d\n",retvalue);
                        write(S->connfd,(const char*)S->list[i].message,strlen(S->list[i].message));
                        close(S->connfd);
                        exit(0);
                
                }
                close(S->connfd);
            }

	  }

	  //End

      }
 }
 
struct Server* New_Server(struct ServerObjectList input){
      printf("Calling new server!\n");
        struct Server* retVal = malloc(sizeof(struct Server));
	retVal->list = malloc(sizeof(struct Tcp_connection) * input.ListCount);
	retVal->ListCount = input.ListCount;
	for(int i = 0; i < input.ListCount; ++i){
	  struct Tcp_connection* cc = New_TcpConnection(input.list[i].port);
	  retVal->list[i] = *cc;
	  free(cc);
	}
	
        
        retVal->Run = Run;
        return retVal;
    
}
