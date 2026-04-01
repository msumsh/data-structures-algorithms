cmake_minimum_required(VERSION 3.30)
project(QueueVector)

set(CMAKE_CXX_STANDARD 14)

add_executable(QueueVector main.cpp
        Queue.h
        QueueVector.h
        Exceptions.h)
