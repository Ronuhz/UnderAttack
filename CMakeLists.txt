cmake_minimum_required(VERSION 4.0)
project(UnderAttack)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        Entity.cpp
        Entity.h
        Player.cpp
        Player.h
        Application.cpp
        Application.h
        GameManager.cpp
        GameManager.h
        Enemy.cpp
        Enemy.h)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib )
