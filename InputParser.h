#include <stdio.h>

struct InputParser {
  char* topic;
  char* kafka_password;
  char* kafka_username;
  int passwordset;
  int usernameset;
  int (*CheckNextArgs)( struct  InputParser* P,int position,int argc, char *argv[]);
  struct ServerObjectList (*scan_file)();

};

struct InputParser* New_InputParser(int argc, char *argv[]);
