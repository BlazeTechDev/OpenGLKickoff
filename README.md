# OpenGL Kickoff

## Purpose

oftentimes I have a great idea for a new coding project in opengl. I enthusiastically open my ide and begin, once again, creating an opengl renderer, only to loose interest after getting the matrix transformations completed. My solution to this problem was to have an opengl renderer ready to go so that I can "kick start" my projects.

## Features

currently this library is very bare bones but over time I plan to add any features I feel would be helpful to start off with completed in opengl.

- basic indexed rendering
- basic shader compilation
- shader uniforms:
  - float
  - int
  - vec2
  - vec3
  - vec4
  - mat4
- basic windowing
- basic graphics types:
  - kck_vao
  - kck_vertex_buffer
  - kck_index_buffer
  - kck_shader
  - kck_shader_program

## To-Do
- make program memory safe
- use frequently to find bugs and needed features
- include the ability to use glm instead of cglm

> [!WARNING]
> as of right now this library has absolutely ABISMAL memory management. Use at your own risk. feel free to add your own memory management as well and contribute your changes:)
