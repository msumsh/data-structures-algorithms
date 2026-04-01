cmake_minimum_required(VERSION 3.30)
project(StackList)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp
        Stack.h
        StackList.h
        Exceptions.h
        getPostfixFromInfix.h
        getPostfixFromInfix.cpp)
