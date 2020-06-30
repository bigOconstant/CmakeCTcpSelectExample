struct InputParser {
  char* topic;
  int port1;
  int port2;
  
  int (*CheckNextArgs)( struct  InputParser* P,int position,int argc, char *argv[]);

};

struct InputParser* New_InputParser(int argc, char *argv[]);
