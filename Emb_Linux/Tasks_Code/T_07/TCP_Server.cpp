#include"TCP_SERVER_Driver.h"


int main()
{
    Server_Driver Serv_1;
    int ServerSocket =Serv_1.MakeServer();
    constexpr int addrlen =sizeof(Serv_1.Server_Address());
    constexpr int N_Users = 3;
    int client_socket;
    char Buffer[1024]={0};

    while(1)
    {
        if(listen(ServerSocket,N_Users)<0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if((client_socket==accept(ServerSocket,(struct sockaddr*)&Serv_1.Server_Address(),(socklen_t*)&addrlen)<0))
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        int value_read = read(client_socket,Buffer,1024);
        printf("%s\n",Buffer);
        // close(client_socket);

        return 0;
    }




    return 0;
}