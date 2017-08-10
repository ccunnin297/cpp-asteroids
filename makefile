# Paths
APP_NAME = a.out
INCLUDE_PATH = ./include
SRC_PATH = ./src
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_PATH = ./obj
OBJ_FILES = $(addprefix $(OBJ_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
CC = g++
DEBUG = -g
GENERIC_INCLUDE = -I$(INCLUDE_PATH)
SFML_INCLUDE = -I$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/include
SFML_LIBS = -L$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
CFLAGS = -Wall -c $(DEBUG) $(GENERIC_INCLUDE) $(SFML_INCLUDE) -std=c++14
LFLAGS = -Wall $(DEBUG) $(SFML_LIBS)

# Link
$(APP_NAME): $(OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(APP_NAME)