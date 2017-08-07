# Paths
APP_NAME = a.out
SRC_PATH = ./src
INCLUDE_PATH = ./src/include
CC = g++
DEBUG = -g
OBJS = main.o
SFML_INCLUDE = -I$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/include
SFML_LIBS = -L$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/lib -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -c $(DEBUG) $(SFML_INCLUDE)
LFLAGS = -Wall $(DEBUG) $(SFML_LIBS)

# Link
a.out: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(APP_NAME)

# Compile
main.o: $(SRC_PATH)/main.cpp
	$(CC) $(CFLAGS) $(SRC_PATH)/main.cpp

clean:
	rm $(OBJS) $(APP_NAME)
