cmake_minimum_required(VERSION 3.30)
project(HashTable)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashTable main.cpp
        HashTable.cpp
        HashTable.h)
