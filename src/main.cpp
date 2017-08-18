#include "Server.h"
#include "Client.h"

#include "GameValues.h"

#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    //seed random number generator
    srand((unsigned)time(NULL));

    sf::IpAddress ipAddress;
    Server* server;
    if (argc > 1 && argv[1]) {
        ipAddress = argv[1];
    } else {
        //Start the server
        server = new Server(NETWORK_PORT);
        server->start();

        ipAddress = "127.0.0.1";
    }

    //Start and connect client
    Client client;
    client.connectToServer(ipAddress, NETWORK_PORT);

    //Start client -- this will block thread until opened window is closed
    client.run();

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_SUCCESS;
}