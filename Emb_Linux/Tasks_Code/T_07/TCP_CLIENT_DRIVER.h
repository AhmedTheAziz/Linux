#ifndef TCP_CLIENT_DRIVER_H
#define TCP_CLIENT_DRIEVER_H
extern "C"
{
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <stdio.h>
#include <unistd.h>
#include <string.h>	//strlen
#include "time.h"
}
#include <string>

class SocketFactory
{
    public:

    SocketFactory(const std::string &ipAddress_):ipAddress(ipAddress_)
    {
       
    }

    int MakeSocket(struct sockaddr_in &address)
    {
        address.sin_addr.s_addr = inet_addr(ipAddress.c_str());
        address.sin_family = AF_INET;
        address.sin_port = htons( 5000 );
        
        //Create socket
        int sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            printf("Could not create socket");
        }
        this->socket_descriptor = sock;
        return sock;
    
    }
    int MakeClient()
    {
        struct sockaddr_in server;
        auto socket =  MakeSocket(server);
        //Connect to remote server
        if (connect(socket , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            puts("connect error");
            return -1;
        }
        puts("Connected\n");
        return socket;
    } 
    ~SocketFactory()
    {
        close(socket_descriptor);
    }
    private:
    const std::string &ipAddress;
    int socket_descriptor;
}; 



#endif









