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
#include "server.h"
#include "InputParser.h"

int main(int argc, char *argv[]) 
{

  struct InputParser* P = New_InputParser(argc,argv);

  //listen on ports 5002 and 5001
  //struct Server* nServer = New_Server(5002,5001);
 

  //nServer->Run(nServer);

  return 0;
}

