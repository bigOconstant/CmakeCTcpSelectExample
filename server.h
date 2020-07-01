

struct Server
{
    
     int connfd;
     int nready;
     int maxfdp1;

     pid_t childpid;
     fd_set rset;
     ssize_t n;
     socklen_t len;
     const int on ;
  struct Tcp_connection* one;
  struct Tcp_connection* two;
    struct Tcp_connection* list;
    int ListCount;  
    void (*Run)(struct Server* S);

};


struct Server* New_Server(struct ServerObjectList input);

