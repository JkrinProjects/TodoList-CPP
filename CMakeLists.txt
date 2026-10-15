#references
# https://cmake.org/cmake/help/latest/guide/tutorial/Getting%20Started%20with%20CMake.html    //Cmake
#Google Tests  https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.20)
project(TodoApp VERSION 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#build the todo list
add_executable(todo)
target_sources(todo PRIVATE 
    src/main.cpp 
    src/Task.cpp 
    src/TodoList.cpp 
    src/TodoListController.cpp
    src/TodoListUI.cpp)

#tests

#<text> = Subsection name from documentation
#<Set up a project>
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#<Create and run a library>
enable_testing()
add_executable(TodoListUnitTests
    tests/TaskTests.cpp
    tests/TodoListTests.cpp
    tests/TodoListControllerTests.cpp

    src/Task.cpp
    src/TodoList.cpp
    src/TodoListController.cpp
)
#location of header files
target_include_directories(TodoListUnitTests PRIVATE src)

#link Gtest suite to todolist tests
target_link_libraries(
  TodoListUnitTests
  GTest::gtest_main
)
#enable CMake’s test runner to discover the tests included in the binary, using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(TodoListUnitTests)