cmake_minimum_required(VERSION 3.20)
project(TodoApp VERSION 1)
set(CMAKE_CXX_STANDARD 20)

add_executable(todo)
target_sources(todo PRIVATE src/main.cpp src/Task.cpp src/Todolist.cpp)

#reference https://cmake.org/cmake/help/latest/guide/tutorial/Getting%20Started%20with%20CMake.html