cmake_minimum_required(VERSION 3.16)

project(test)

set(cmake_cxx_standard 11)

include_directories(header/)

set(sources
	src/main.cpp
	src/Wandering.cpp
	src/Hunter.cpp
	src/Scared.cpp
	src/snacks.cpp
	src/power_pellets.cpp
	src/pellets.cpp
	src/PacMan.cpp
	src/ghosts.cpp
	src/ghosts_state.cpp
	src/fruits.cpp
)

add_executable(app ${sources})