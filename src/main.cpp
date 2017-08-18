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

    //Start and connect client
    Client client;

    //Start client -- this will block thread until opened window is closed
    client.run();

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_SUCCESS;
}