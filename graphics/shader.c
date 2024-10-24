//
// Created by Osprey on 10/17/2024.
//

#include "shader.h"

#include <glad/glad.h>

#include "../core/io.h"

kck_shader kck_create_shader(kck_shader_type shader_type) {
    kck_shader shader = {};
    shader.type = shader_type;
    switch (shader_type) {
        case KCK_VERTEX_SHADER:
            shader.id = glCreateShader(GL_VERTEX_SHADER);
            break;
        case KCK_FRAGMENT_SHADER:
            shader.id = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        default:
            break;
    }
    return shader;
}

kck_shader_program kck_create_shader_program() {
    kck_shader_program shader_program = {};
    shader_program.id = glCreateProgram();
    return shader_program;
}

int kck_load_shader(kck_shader* shader, const char* local_path) {
    const char* shader_source = kck_read_file_local(local_path);

    glShaderSource(shader->id, 1, &shader_source, NULL);
    glCompileShader(shader->id);

    int success;
    char infoLog[512];
    glGetShaderiv(shader->id, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shader->id, 512, NULL, infoLog);
        printf("%s\n", infoLog);
    }
}

int kck_load_shader_program(kck_shader_program* shader_program, kck_shader* vertex_shader, kck_shader* fragment_shader) {
    glAttachShader(shader_program->id, vertex_shader->id);
    glAttachShader(shader_program->id, fragment_shader->id);
    glLinkProgram(shader_program->id);

    int success;
    char infoLog[512];
    glGetProgramiv(shader_program->id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader_program->id, 512, NULL, infoLog);
        printf("%s\n", infoLog);
    }
}

int kck_use_program(kck_shader_program* shader_program) {
    glUseProgram(shader_program->id);
}

int kck_cleanup_shader_program(kck_shader_program* shader_program, kck_shader* vertex_shader, kck_shader* fragment_shader) {
    glDetachShader(shader_program->id, vertex_shader->id);
    glDetachShader(shader_program->id, fragment_shader->id);
    glDeleteShader(vertex_shader->id);
    glDeleteShader(fragment_shader->id);
    glDeleteProgram(shader_program->id);
}

int kck_upload_shader_uniform_float(kck_shader_program* shader_program, const char* uniform_name, float value) {
    int uniform_location = glGetUniformLocation(shader_program->id, uniform_name);
    glUniform1f(uniform_location, value);
}

int kck_upload_shader_uniform_int(kck_shader_program* shader_program, const char* uniform_name, int value) {
    int uniform_location = glGetUniformLocation(shader_program->id, uniform_name);
    glUniform1i(uniform_location, value);
}

int kck_upload_shader_uniform_vec2(kck_shader_program* shader_program, const char* uniform_name, vec2* value) {
    int uniform_location = glGetUniformLocation(shader_program->id, uniform_name);
    glUniform2fv(uniform_location, 1, value);
}