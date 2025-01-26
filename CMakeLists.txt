cmake_minimum_required(VERSION 3.10)
project(engine)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

find_package(OpenGL REQUIRED)

add_executable(
    engine
    src/main.cpp 
    src/glad.c
    src/shader/shader.cpp
    )

target_link_libraries(engine glfw OpenGL::GL)

