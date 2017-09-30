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

    bool isDedicatedServer = false;
    bool isLocalServer = false;

    if (argc > 1 && argv[1]) {
        if (strncmp(argv[1], "host", 4) == 0) {
            isDedicatedServer = true;
        } else {
            ipAddress = argv[1];
        }
    } else {
        ipAddress = "127.0.0.1";
        isLocalServer = true;
    }

    //This has to be done first in order to connect sf::event loop to main thread
    sf::RenderWindow window(sf::VideoMode(GAME_BOUNDS_X, GAME_BOUNDS_Y), "cpp-asteroids");
    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(true);
    
    Server server(NETWORK_PORT);
    if (isDedicatedServer) {
        //Start server -- this will block thread until process ends
        server.start(true);
    } else if(isLocalServer) {
        server.start();
    }

    if (!isDedicatedServer) {

        //Start and connect client
        Client client;
        client.connectToServer(ipAddress, NETWORK_PORT);
        
        //Start client -- this will block thread until opened window is closed
        client.run(window);
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_SUCCESS;
}