# cpp-asteroids

Project built for Windows and Mac / osx.

## Dependencies
Requires SFML and protobuf to be installed:

SFML 2.4.2: https://www.sfml-dev.org/download/sfml/2.4.2/

Google Protocol Buffers: https://developers.google.com/protocol-buffers/

## Windows

### Configuration
This project is built in Visual Studio. In order to build, dependencies must be set up in project properties.

- Note: Protobuf may need to be built from source in order to get the necessary include files and libs
- In C/C++, General: Replace SFML and protobuf include paths
- In Linker, General: Replace SFML and protobuf lib paths
- Make sure the protoc executable is in your path

In config.h, change PC to 1 and Mac to 0.

### Build
Debug:
- Use standard clean, build, and debug commands in visual studio

Release
- Build command will add a 'publish' folder to the project directory with everything needed to run the application.

### Run
Run:

Run executable in publish folder.

Connect to a running game server:

Create a shortcut to the executable. In the shortcut properties, change the target to:

`"[path-to-executable]/cpp-asteroids.exe" [ip-address]`

For example:

`"C:/publish/cpp-asteroids.exe" 192.168.0.6`


## Mac

### Configuration
In order to build, dependencies must be set up in the makefile.

- Replace SFML_PATH and PROTO_PATH

In config.h, change PC to 0 and Mac to 1.

### Build
To build application:

`make`

To build and test:

`make test`
`./test`

### Run
Run:

`./run`

Connect to a running game server:

`./run [ip-address]`

For example:

`./run 127.0.0.1` or `./run 192.168.0.6`
