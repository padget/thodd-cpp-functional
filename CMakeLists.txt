cmake_minimum_required(VERSION 3.8)
project(thodd-cpp-functional)



set(CMAKE_CXX_FLAGS "-std=c++1z ${CMAKE_CXX_FLAGS}")


add_library(thodd INTERFACE)
target_sources(thodd INTERFACE ${PROJECT_SOURCE_DIR}/include/thodd/functional/functor.hpp)

target_include_directories(thodd INTERFACE "${PROJECT_SOURCE_DIR}/include")


target_link_libraries(thodd)

