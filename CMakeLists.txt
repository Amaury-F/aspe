cmake_minimum_required(VERSION 3.8)
project(jeu2d)

set(CMAKE_CXX_STANDARD 17)
set(LIBS sfml-window sfml-graphics sfml-system)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(jeu2d ${SOURCES})

target_link_libraries(jeu2d ${LIBS})