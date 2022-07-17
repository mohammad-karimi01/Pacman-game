cmake_minimum_required(VERSION 3.16)

project(test)

set(cmake_cxx_standard 11)

include_directories(header/)

set(sources
	src/main.cpp
	src/speedy.cpp
	src/snacks_state.cpp
	src/snacks.cpp
	src/shodow.cpp
	src/power_pellets.cpp
	src/pokey.cpp
	src/pellets.cpp
	src/PacMan.cpp
	src/ghosts.cpp
	src/ghosts_state.cpp
	src/fruits.cpp
	src/frightened_ghosts.cpp
	src/bashful.cpp

)

add_executable(app ${sources})