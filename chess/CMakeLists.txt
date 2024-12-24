# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(ChessProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the build type to Debug for GDB support
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/Controller
    ${PROJECT_SOURCE_DIR}/Model/Dispatcher
    ${PROJECT_SOURCE_DIR}/Model/Handler
    ${PROJECT_SOURCE_DIR}/Model/Pieces
    ${PROJECT_SOURCE_DIR}/View
)

# Collect all source files for CLI
file(GLOB_RECURSE CONTROLLER_SOURCES
    "${PROJECT_SOURCE_DIR}/Controller/*.cpp"
)

# Collect all source files for Document
file(GLOB_RECURSE MODEL_SOURCES
    "${PROJECT_SOURCE_DIR}/Model/Dispatcher/*.cpp"
    "${PROJECT_SOURCE_DIR}/Model/Handler/*.cpp"
    "${PROJECT_SOURCE_DIR}/Model/Pieces/*.cpp"
)

# Collect all source files for Edition
file(GLOB_RECURSE VIEW_SOURCES
    "${PROJECT_SOURCE_DIR}/View/*.cpp"
)

# Combine all source files into one variable
set(ALL_SOURCES
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    ${VIEW_SOURCES}
)

# Find and include Qt
set(QT_VERSION_MAJOR 5) # Adjust this if using Qt 6
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Locate Qt installation
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5") # Add the correct path to Qt installation
set(Qt5_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# Add include directories for Qt
include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

# Add MOC files if needed
set(HEADERS
    ${PROJECT_SOURCE_DIR}/View/ViewBoard.h
    ${PROJECT_SOURCE_DIR}/View/GameWindow.h
)

# Link Qt libraries
add_executable(ChessProject
    ${ALL_SOURCES}
    ${HEADERS}
)

target_link_libraries(ChessProject
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Set debug flags for the compiler to enable GDB support
target_compile_options(ChessProject PRIVATE
    $<$<CONFIG:Debug>:-g>
)
