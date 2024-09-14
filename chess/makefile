# Define directories
SRC_DIR := .
OBJ_DIR := obj
BIN_DIR := bin

# List directories
CONTROLLER_DIR := $(SRC_DIR)/Controller
MODEL_DIR := $(SRC_DIR)/Model
DISPATCHER_DIR := $(MODEL_DIR)/Dispatcher
HANDLER_DIR := $(MODEL_DIR)/Handler
PIECES_DIR := $(MODEL_DIR)/Pieces
VIEW_DIR := $(SRC_DIR)/View

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(CONTROLLER_DIR)/*.cpp) $(wildcard $(MODEL_DIR)/**/*.cpp) $(wildcard $(VIEW_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Output binary
TARGET := $(BIN_DIR)/myprogram

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -g -I$(CONTROLLER_DIR) -I$(MODEL_DIR) -I$(DISPATCHER_DIR) -I$(HANDLER_DIR) -I$(PIECES_DIR) -I$(VIEW_DIR)
LDFLAGS := -lncursesw

# Default target
all: $(TARGET)

# Link the binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

