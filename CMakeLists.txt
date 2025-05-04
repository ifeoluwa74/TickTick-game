cmake_minimum_required(VERSION 3.10)

project(TickTick VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the path to the SFM-2.4.1 folder
set(SFM_DIR "C:/Users/iifeoluwa/Downloads/TickTick/SFM-2.4.1")

# Include the headers from SFM-2.4.1
include_directories(${SFM_DIR}/include)

# Link the library from SFM-2.4.1 (adjust the library name if needed)
target_link_libraries(${PROJECT_NAME} ${SFM_DIR}/lib/sfm.lib)

# Add the source files for the TickTick project
set(SOURCE_FILES
    src/main.cpp
    src/TickTick.cpp
    src/Task.cpp
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Ensure the target links to the SFM library
target_link_libraries(${PROJECT_NAME} sfm)