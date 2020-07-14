cmake_minimum_required(VERSION 3.16)
project(tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(BiTree BiTree.cpp)
add_executable(ThreadTree ThreadTree.cpp)
add_executable(BSTree BSTree.cpp)