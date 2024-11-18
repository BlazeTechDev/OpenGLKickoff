cmake_minimum_required(VERSION 3.26)
project(OpenGLKickoff C)

find_package(OpenGL REQUIRED)
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/ext/cglm)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/ext/glad/include)

add_executable(OpenGLKickoff main.c
        core/input.c
        core/input.h
        core/core.c
        core/core.h
        core/window.c
        core/window.h
        ${PROJECT_SOURCE_DIR}/ext/glad/src/glad.c
        graphics/shader.c
        graphics/shader.h
        graphics/buffer.c
        graphics/buffer.h
        core/io.c
        core/io.h
        graphics/utils.c
        graphics/utils.h
        ext/c-vector/cvector.h
        ext/c-vector/cvector_utils.h
        graphics/mesh.h
        graphics/camera.h
)

file(REMOVE ${PROJECT_SOURCE_DIR}/local/)
file(COPY ${PROJECT_SOURCE_DIR}/local/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/local/)

target_link_libraries(OpenGLKickoff cglm)
target_link_libraries(OpenGLKickoff glfw)
target_link_libraries(OpenGLKickoff OpenGL::GL)