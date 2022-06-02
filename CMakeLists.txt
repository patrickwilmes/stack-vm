cmake_minimum_required(VERSION 3.17)

project(stack_vm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
        main.cpp
        preprocessing/preprocessing.h
        preprocessing/preprocessing.cpp
        utils.h
        instructions.h
        io/io.h
        io/loader.cpp
        parser.h
        parser.cpp
        executor.h
        executor.cpp
        )
include_directories(.)

add_executable(stack_vm ${SOURCE})
