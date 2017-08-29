# cpp-asteroids

Project built for Mac / osx.

To build for other platforms, replace SFML/protobuf libraries in makefile.

## Dependencies
Uses SFML 2.4.2: https://www.sfml-dev.org/download/sfml/2.4.2/
Uses Google Protocol Buffers: https://developers.google.com/protocol-buffers/

## Build
To build application:
`make`

To build and test:
`make test`
`./test`

## Play the game
Run:
`./run`

Connect to a running game server:
`./run [ip-address]`

For example, `./run 127.0.0.1` or `./run 192.168.0.6`