cmake_minimum_required(VERSION 3.10)
project(FileHandlerLib)

add_library(FileHandlerLib STATIC src/FileHandler.cpp)

target_include_directories(FileHandlerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test test_library.cpp)

target_link_libraries(test PRIVATE FileHandlerLib)
