cmake_minimum_required(VERSION 3.20)
project(TodoApp VERSION 1)
set(CMAKE_CXX_STANDARD 20)

add_executable(todo src/main.cpp src/Task.cpp src/Todolist.cpp)
