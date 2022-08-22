cmake_minimum_required(VERSION 3.16)

project(test)

set(cmake_cxx_standard 11)

include_directories(header/ C:/sfml/SFML-2.5.1/include)

set(sources
	src/main.cpp
	src/Map.cpp
	src/PacMan.cpp
	src/Ghosts.cpp
	src/TypesOfCollisions.cpp
)

add_executable(app ${sources})

target_link_libraries(app sfml-window sfml-system sfml-graphics)
