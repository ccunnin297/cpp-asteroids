#include "Server.h"
#include "Client.h"

int main() {
    const unsigned short port = 50001;

    //Start server
    Server server(port);
    server.start();

    //Start and connect client
    Client client;
    client.connectToServer("127.0.0.1", port);

    //Start client -- this will block thread until opened window is closed
    client.run();

    return 0;
}