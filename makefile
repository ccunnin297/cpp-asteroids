# Paths
APP_NAME = a.out
SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUDE_PATH = ./include
CC = g++
DEBUG = -g
OBJS = $(OBJ_PATH)/*.o
SFML_INCLUDE = -I$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/include
SFML_LIBS = -L$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
CFLAGS = -Wall -c $(DEBUG) $(SFML_INCLUDE) -std=c++14
LFLAGS = -Wall $(DEBUG) $(SFML_LIBS)

# Link
# a.out: $(OBJS)
# 	$(CC) $(LFLAGS) $(OBJS) -o $(APP_NAME)

# Compile
# main.o: $(SRC_PATH)/main.cpp $(SRC_PATH)/Server.h
# 	$(CC) $(CFLAGS) $(SRC_PATH)/main.cpp

# Server.o: $(SRC_PATH)/Server.cpp
# 	$(CC) $(CFLAGS) $(SRC_PATH)/Server.cpp

clean:
	rm $(OBJS) $(APP_NAME)

all: 
	$(CC) $(CFLAGS) $(SRC_PATH)/*.cpp
	mv *.o $(OBJ_PATH)
	$(CC) $(LFLAGS) $(OBJS) -o $(APP_NAME)