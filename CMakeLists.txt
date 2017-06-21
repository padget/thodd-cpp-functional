cmake_minimum_required(VERSION 3.8)
project(thodd-cpp-functional)

set(FUNCTIONAL_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(HEADER_DIR ${CATCH_DIR}/include)

set(CMAKE_CXX_FLAGS "-std=c++1z ${CMAKE_CXX_FLAGS}")


include_directories(${HEADER_DIR})

add_executable(thodd)

install(DIRECTORY "include/" DESTINATION "build/include/thodd")

