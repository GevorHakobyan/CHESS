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

# Source and header files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) \
        $(wildcard $(CONTROLLER_DIR)/*.cpp) \
        $(wildcard $(MODEL_DIR)/**/*.cpp) \
        $(wildcard $(VIEW_DIR)/*.cpp)

HEADERS := $(wildcard $(SRC_DIR)/*.h) \
           $(wildcard $(CONTROLLER_DIR)/*.h) \
           $(wildcard $(MODEL_DIR)/**/*.h) \
           $(wildcard $(VIEW_DIR)/*.h)

# Generate moc files
MOC_SRCS := $(HEADERS:$(SRC_DIR)/%.h=$(OBJ_DIR)/moc_%.cpp)
MOC_OBJS := $(MOC_SRCS:%.cpp=%.o)

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(MOC_OBJS)

# Output binary
TARGET := $(BIN_DIR)/myprogram

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++20 -g -fPIC -O0 \
    -I$(CONTROLLER_DIR) -I$(MODEL_DIR) -I$(DISPATCHER_DIR) -I$(HANDLER_DIR) -I$(PIECES_DIR) -I$(VIEW_DIR) \
    -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCore \
    -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets

LDFLAGS := -L/usr/lib/x86_64-linux-gnu -lQt5Widgets -lQt5Gui -lQt5Core

# Default target
all: $(TARGET)

# Link the binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate moc files
$(OBJ_DIR)/moc_%.cpp: $(SRC_DIR)/%.h
	@mkdir -p $(dir $@)
	moc $< -o $@

$(OBJ_DIR)/moc_%.o: $(OBJ_DIR)/moc_%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Debugging with gdb
debug: $(TARGET)
	@echo "Starting GDB..."
	@gdb -ex "start" $(TARGET)
	@echo "GDB started. You can now set breakpoints and debug."

.PHONY: all clean debug
