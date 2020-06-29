
struct Tcp_connection{
    int file_descriptor;
    struct sockaddr_in server_address;
    struct sockaddr_in cliaddr;
    int MAXLINESIZE;
    char* message;
    char* buffer;
    int port;
    
};

struct Tcp_connection* New_TcpConnection(int port);
