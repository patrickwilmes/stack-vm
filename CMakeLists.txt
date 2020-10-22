cmake_minimum_required(VERSION 3.17)

project(toyvm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE src/main.cpp src/preprocessing/Preprocessing.h src/preprocessing/validation.cpp src/instructions.h src/io/io.h src/io/loader.cpp src/utils.h src/preprocessing/preprocessing.cpp src/parser.h src/parser.cpp)

add_executable(toyvm ${SOURCE})
