
struct ServerObject {
  char* topic;
  char* host;
  int port;
};

struct ServerObjectList {
  struct ServerObject *list;
  
  int ListCount;

};
