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

    //This has to be done first in order to connect sf::event loop to main thread
    sf::RenderWindow window(sf::VideoMode(GAME_BOUNDS_X, GAME_BOUNDS_Y), "cpp-asteroids");

    sf::IpAddress ipAddress;

    Server server(NETWORK_PORT);
    if (argc > 1 && argv[1]) {
        ipAddress = argv[1];
    } else {
        //Start the server
        server.start();
        ipAddress = "127.0.0.1";
    }

    //Start and connect client
    Client client;
    client.connectToServer(ipAddress, NETWORK_PORT);
    client.run(window);

    //Start client -- this will block thread until opened window is closed
    

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_SUCCESS;
}