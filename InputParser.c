/*
struct InputParser {
  char* topic;
  int port1;
  int port2;

};

struct InputParser* New_InputParser(int argc, char *argv[]);

 */
#include "InputParser.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"


static int CheckNextArgs(struct InputParser* P,int position, int argc, char *argv[]){
  if(argc-1 > position){
    printf(" grator than position\n");
    if( strcmp(argv[1+position],"-topic")){
      printf("return 0\n");
	return 0;
      }
  }
  printf("returning -1\n");
    return -1;
  

}


struct InputParser* New_InputParser(int argc, char *argv[]) {

  struct InputParser* retVal = malloc(sizeof(struct InputParser));

  int length = 0;
  for(int i = 1; i <argc; ++i){
    length = strlen(argv[i]);
    printf("\nLength:%d\n",length);
    puts(argv[i]);
    if(strcmp(argv[i],"topic")){
	printf("%d",CheckNextArgs(retVal,i,argc,argv));
    }
  }
  
  return retVal;

}


