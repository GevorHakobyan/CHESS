# Define directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Include the directories for Controller, Model, View, and subdirectories within Model
CONTROLLER_DIR = $$SRC_DIR/Controller
MODEL_DIR = $$SRC_DIR/Model
DISPATCHER_DIR = $$MODEL_DIR/Dispatcher
HANDLER_DIR = $$MODEL_DIR/Handler
PIECES_DIR = $$MODEL_DIR/Pieces
VIEW_DIR = $$SRC_DIR/View

# Specify the source files (recursive search for .cpp)
SOURCES += $$files($$SRC_DIR/*.cpp) \
           $$files($$MODEL_DIR/*.cpp) \
           $$files($$CONTROLLER_DIR/*.cpp) \
           $$files($$DISPATCHER_DIR/**/*.cpp) \
           $$files($$HANDLER_DIR/**/*.cpp) \
           $$files($$PIECES_DIR/**/*.cpp) \
           $$files($$VIEW_DIR/*.cpp)

# Specify the header files (recursive search for .h)
HEADERS += $$files($$SRC_DIR/*.h) \
           $$files($$MODEL_DIR/*.h) \
           $$files($$CONTROLLER_DIR/*.h) \
           $$files($$DISPATCHER_DIR/**/*.h) \
           $$files($$HANDLER_DIR/**/*.h) \
           $$files($$PIECES_DIR/**/*.h) \
           $$files($$VIEW_DIR/*.h)

# Include the necessary paths for header files
INCLUDEPATH += $$CONTROLLER_DIR \
               $$MODEL_DIR \
               $$DISPATCHER_DIR \
               $$HANDLER_DIR \
               $$PIECES_DIR \
               $$VIEW_DIR \
               /usr/include/x86_64-linux-gnu/qt5 \
               /usr/include/x86_64-linux-gnu/qt5/QtCore \
               /usr/include/x86_64-linux-gnu/qt5/QtGui

# Define object directory
OBJECTS_DIR = $$OBJ_DIR

# Include the Qt5 modules
QT += core gui widgets


# Set C++ standard
QMAKE_CXXFLAGS += -std=c++20

# Output binary path
DESTDIR = $$BIN_DIR

# Define the target executable
TARGET = myprogram

# Clean the build
clean.files += $$OBJECTS_DIR/*.o
