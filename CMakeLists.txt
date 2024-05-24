cmake_minimum_required(VERSION 3.27)
project(Arcanoid)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arcanoid main.cpp
        libs/ShapeCircle.h
        libs/Shape.h
        libs/ShapeRectangle.h
        libs/PaddleUsage.cpp
        libs/PaddleUsage.h
        libs/BallUsage.cpp
        libs/BallUsage.h
        libs/BrickUsage.cpp
        libs/BrickUsage.h
        libs/Collision.cpp
        libs/Collision.h
        libs/Bonuses.cpp
        libs/Bonuses.h
        libs/BottomUsage.cpp
        libs/BottomUsage.h
        libs/GameFinal.cpp
        libs/GameFinal.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Project 3/SFML/include/SFML)
target_link_libraries(Arcanoid sfml-system sfml-window sfml-graphics sfml-audio)
