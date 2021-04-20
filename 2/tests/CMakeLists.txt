cmake_minimum_required(VERSION 3.17)
project(1-tests)

enable_testing()
find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES . src/*.cpp)

add_executable(test ${SOURCES})

target_include_directories(test PUBLIC "..")
target_include_directories(test PUBLIC "./include")

target_link_libraries(test PUBLIC GTest::GTest GTest::Main)

add_test(CommonTestsAll test)
