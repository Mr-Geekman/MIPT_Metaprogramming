cmake_minimum_required(VERSION 3.17)
project(1)

set(CMAKE_CXX_STANDARD 17)
option(TESTS "Build tests" ON)

#add_executable(1 main.cpp typelist.hpp)

if (TESTS)
    add_subdirectory("./tests")
endif(TESTS)
