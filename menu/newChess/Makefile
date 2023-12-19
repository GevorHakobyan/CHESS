CC = g++
CFLAGS = -g -Wall
SRC_DIR = PieceFiles
INC_DIR = PieceFiles
BUILD_DIR = build
TARGET_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.cpp)
INC = $(wildcard $(INC_DIR)/*.h)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

TARGET = myprogram

all: directories $(TARGET)

directories:
	mkdir -p $(BUILD_DIR) $(TARGET_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lncursesw

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET_DIR)

.PHONY: debug
debug: CFLAGS += -DDEBUG
debug: all
