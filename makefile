# Paths
APP_NAME = game.exe
INCLUDE_PATH = ./include
SRC_PATH = ./src
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_PATH = ./build/obj
OBJ_FILES = $(addprefix $(OBJ_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
GEN_PATH = ./build/gen

DEPS = $(CPP_FILES:.cpp=.d)

# g++
CC = g++
DEBUG = -g

# Includes
GENERIC_INCLUDE = -I$(INCLUDE_PATH)

SFML_INCLUDE = -I$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/include
SFML_LIBS = -L$(INCLUDE_PATH)/SFML-2.4.2-osx-clang/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

PROTO_BIN = $(INCLUDE_PATH)/protoc-3.3.0-osx-x86_64/bin
PROTO_INCLUDE = -I$(INCLUDE_PATH)/protoc-3.3.0-osx-x86_64/include
PROTO_LIBS = -L$(INCLUDE_PATH)/protoc-3.3.0-osx-x86_64/bin -lprotobuf
PROTOS = $(wildcard $(SRC_PATH)/*.proto)
PROTO_H_PATH = $(addprefix $(GEN_PATH)/,$(notdir $(PROTOS:.proto=.pb.cc)))
PROTO_CC_PATH = $(addprefix $(GEN_PATH)/,$(notdir $(PROTOS:.proto=.pb.h)))
PROTO_GENS = $(PROTO_H_PATH) $(PROTO_CC_PATH)
PROTO_OBJS = $(addprefix $(OBJ_PATH)/,$(notdir $(PROTOS:.proto=.pb.o)))

CFLAGS = -Wall -c $(DEBUG) $(GENERIC_INCLUDE) $(SFML_INCLUDE) $(PROTO_INCLUDE) -std=c++14
LFLAGS = -Wall $(DEBUG) $(SFML_LIBS) $(PROTO_LIBS)

# $(APP_NAME): $(OBJ_FILES)
# $(OBJ_FILES): $(DEPS)
# $(DEPS): $(PROTO_OBJS)

# Don't delete intermediate protobuf generated classes
.PRECIOUS: $(PROTO_GENS)

# Compile
$(GEN_PATH)/%.pb.cc: $(SRC_PATH)/%.proto
	$(PROTO_BIN)/protoc --proto_path=$(SRC_PATH) --cpp_out=$(GEN_PATH) $<

$(OBJ_PATH)/%.pb.o: $(GEN_PATH)/%.pb.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(PROTO_GENS)
	$(CC) $(CFLAGS) -I$(GEN_PATH) -c -o $@ $<

# Link
$(APP_NAME): $(OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $(PROTO_OBJS) $^

all: $(APP_NAME)
clean:
	rm -rf $(APP_NAME) $(OBJ_FILES) $(PROTO_GENS)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif