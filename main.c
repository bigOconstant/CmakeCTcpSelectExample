// Server program 
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
#include "InputParser.h"

#include "stdio.h"

int main(int argc, char *argv[]) 
{

  struct InputParser* P = New_InputParser(argc,argv);


  struct ServerObjectList list = P->scan_file();
  printf("We have our list! :%s\n",list.list[0].topic);
  printf("array size:%d\n",list.ListCount);
  
  //free(list);
  //listen on ports 5002 and 5001
   struct Server* nServer = New_Server(list);
 

  nServer->Run(nServer);
  //  free(list.list);
  return 0;
}

