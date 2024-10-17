cmake_minimum_required(VERSION 3.29)
project(OpenGLKickoff C)

find_package(OpenGL REQUIRED)
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/glfw-3.4)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/ext/glad/include)

add_executable(OpenGLKickoff main.c
        core/window.c
        core/window.h
        core/core.c
        core/core.h
        core/input.c
        core/input.h
        ${PROJECT_SOURCE_DIR}/ext/glad/src/glad.c
        graphics/shader.c
        graphics/shader.h
        graphics/buffer.c
        graphics/buffer.h)

target_link_libraries(OpenGLKickoff glfw)
target_link_libraries(OpenGLKickoff OpenGL::GL)