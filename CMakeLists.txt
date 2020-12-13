cmake_minimum_required(VERSION 3.17)

project(stack_vm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE src/main.cpp src/preprocessing/Preprocessing.h src/instructions.h src/io/io.h src/io/loader.cpp src/utils.h src/preprocessing/preprocessing.cpp src/parser.h src/parser.cpp src/executor.h src/executor.cpp)

add_executable(stack_vm ${SOURCE})
