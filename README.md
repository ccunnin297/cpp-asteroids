# cpp-asteroids

Project built for Windows and Mac / osx.

## Dependencies
Requires SFML and protobuf to be installed:

SFML 2.4.2: https://www.sfml-dev.org/download/sfml/2.4.2/

Google Protocol Buffers: https://developers.google.com/protocol-buffers/
- Note: Protobuf may need to be built from source in order to get the necessary include files and libs

## Windows

### Configuration
This project is built in Visual Studio. In order to build, dependencies must be set up in project properties.
- In C/C++, General: Replace SFML and protobuf include paths
- In Linker, General: Replace SFML and protobuf lib paths
- Make sure the protoc executable is in your path
- In config.h, change PC to 1 and Mac to 0.

### Build
Debug:
- Use standard clean, build, and debug commands in visual studio

Release
- Build command will add a 'publish' folder to the project directory with everything needed to run the application.

### Run
Run:
- Run executable in publish folder.

Run with options:
- See available options below in unix description
- Create a shortcut to the executable. In the shortcut properties, change the target to:

`"[path-to-executable]/cpp-asteroids.exe" [option]`

For example:

`"C:/publish/cpp-asteroids.exe" 192.168.0.6`

or

`"C:/Users/dev/Desktop/publish/cpp-asteroids.exe" local` 

## Mac / Linux

### Configuration
In order to build, dependencies must be set up in the makefile.

- Replace SFML_PATH and PROTO_PATH

- In config.h, change PC to 0 and Mac to 1.

### Build
To build application:

`make`

To build and test:

`make test`
`./test`

### Run
Connect to default server:

`./game.exe`

To run locally:

`./game.exe local`

Connect to specific server:

`./game.exe [ip-address]`

For example:

`./game.exe 127.0.0.1` or `./game.exe 192.168.0.6`

To host:

`./game.exe host`

To run as a background process:

`./host-daemon-linux`