#include "Server.h"
#include "Client.h"

#include <cstdlib>
#include <ctime>

int main() {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    //seed random number generator
    srand((unsigned)time(NULL));

    const unsigned short port = 50001;

    //Start server
    Server server(port);
    server.start();

    //Start and connect client
    Client client;
    client.connectToServer("127.0.0.1", port);

    //Start client -- this will block thread until opened window is closed
    client.run();

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}