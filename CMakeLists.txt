cmake_minimum_required(VERSION 3.16)

project(test)

set(cmake_cxx_standard 11)

include_directories(header/)

set(sources
	src/main.cpp
	src/
)

add_executable(app ${sources})