cmake_minimum_required(VERSION 3.8)
project(jeu2d)

set(CMAKE_CXX_STANDARD 17)
set(LIBS sfml-window sfml-graphics sfml-system)

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h)
add_executable(jeu2d ${SOURCE_FILES})
target_link_libraries(jeu2d ${LIBS})