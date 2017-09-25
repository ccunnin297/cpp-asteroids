# Paths
APP_NAME = game.exe
INCLUDE_PATH = ./include
SRC_PATH = ./src
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_PATH = ./build/obj
OBJ_FILES = $(addprefix $(OBJ_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
GEN_PATH = ./build/gen

TEST_NAME = test.exe
TEST_PATH = ./tests
TEST_CPP_FILES = $(wildcard $(TEST_PATH)/*.cpp)
TEST_OBJ_FILES = $(addprefix $(OBJ_PATH)/,$(notdir $(TEST_CPP_FILES:.cpp=.test.o)))

DEPS = $(CPP_FILES:.cpp=.d)

# C++ Compiler
CC = g++
DEBUG = -g

# Includes
GENERIC_INCLUDE = -I$(INCLUDE_PATH)

SFML_PATH = $(INCLUDE_PATH)/SFML-2.4.2-osx-clang
SFML_INCLUDE = -I$(SFML_PATH)/include
SFML_LIBS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

PROTO_PATH = $(INCLUDE_PATH)/protoc-3.4.0-osx-x86_64
PROTO_BIN = $(PROTO_PATH)/bin
PROTO_INCLUDE = -I$(PROTO_PATH)/include
PROTO_LIBS = -L$(PROTO_PATH)/bin -lprotobuf
PROTOS = $(wildcard $(SRC_PATH)/*.proto)
PROTO_H_PATH = $(addprefix $(GEN_PATH)/,$(notdir $(PROTOS:.proto=.pb.cc)))
PROTO_CC_PATH = $(addprefix $(GEN_PATH)/,$(notdir $(PROTOS:.proto=.pb.h)))
PROTO_GENS = $(PROTO_H_PATH) $(PROTO_CC_PATH)
PROTO_OBJS = $(addprefix $(OBJ_PATH)/,$(notdir $(PROTOS:.proto=.pb.o)))

CATCH_PATH = $(INCLUDE_PATH)/catch
CATCH_INCLUDE = -I$(CATCH_PATH)

CFLAGS = -Wall -c $(DEBUG) $(GENERIC_INCLUDE) $(SFML_INCLUDE) $(PROTO_INCLUDE) $(CATCH_INCLUDE) -std=c++14
LFLAGS = -Wall $(DEBUG) $(SFML_LIBS) $(PROTO_LIBS)

TEST_LFLAGS = $(LFLAGS) $(TEST_LIBS)

# Don't delete intermediate protobuf generated classes
.PRECIOUS: $(PROTO_GENS)

# Compile
$(GEN_PATH)/%.pb.cc: $(SRC_PATH)/%.proto
	mkdir -p $(GEN_PATH)
	$(PROTO_BIN)/protoc --proto_path=$(SRC_PATH) --cpp_out=$(GEN_PATH) $<

$(OBJ_PATH)/%.pb.o: $(GEN_PATH)/%.pb.cc
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJ_PATH)/%.test.o: $(TEST_PATH)/%.cpp $(PROTO_GENS) $(PROTO_OBJS)
	$(CC) $(CFLAGS) -I$(GEN_PATH) -I$(SRC_PATH) -c -o $@ $<	

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(PROTO_GENS) $(PROTO_OBJS)
	$(CC) $(CFLAGS) -I$(GEN_PATH) -c -o $@ $<

# Link
$(APP_NAME): $(OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $(PROTO_OBJS) $^

$(TEST_NAME): $(filter-out $(OBJ_PATH)/main.o, $(OBJ_FILES)) $(TEST_OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $(PROTO_OBJS) $^

all: $(APP_NAME) $(TEST_NAME)
test: $(TEST_NAME)
clean:
	rm -rf $(APP_NAME) $(TEST_NAME) $(OBJ_FILES) $(PROTO_OBJS) $(PROTO_GENS)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif