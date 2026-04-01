cmake_minimum_required(VERSION 3.30)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(BinarySearchTree main.cpp
        BinarySearchTree.h
        Queue.h
        QueueVector.h
        Exceptions.h
)
