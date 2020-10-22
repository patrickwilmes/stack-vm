cmake_minimum_required(VERSION 3.17)

project(toyvm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE src/main.cpp src/preprocessing/Preprocessing.h src/preprocessing/validation.cpp src/instructions.h)

add_executable(toyvm ${SOURCE})
