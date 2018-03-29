cmake_minimum_required(VERSION 3.8)
project(jeu2d)

set(CMAKE_CXX_STANDARD 11)
set(LIBS sfml-window sfml-graphics sfml-system)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(jeu2d ${SOURCES} src/graphics/SpriteFactory.h src/graphics/SpriteFactory.cpp)

target_link_libraries(jeu2d ${LIBS})