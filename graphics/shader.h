//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef SHADER_H
#define SHADER_H
#include <cglm/call/ivec3.h>

#endif //SHADER_H

typedef enum kck_shader_type {
    KCK_VERTEX_SHADER,
    KCK_FRAGMENT_SHADER,
} kck_shader_type;

typedef struct kck_shader {
    unsigned int id;
    kck_shader_type type;
} kck_shader;

typedef struct kck_shader_program {
    unsigned int id;
} kck_shader_program;

kck_shader kck_create_shader(kck_shader_type shader_type);
kck_shader_program kck_create_shader_program();

int kck_load_shader(kck_shader* shader, const char* local_path);
int kck_load_shader_program(kck_shader_program* shader_program, kck_shader* vertex_shader, kck_shader* fragment_shader);

int kck_upload_shader_uniform_float(kck_shader_program* shader_program, const char* uniform_name, float value);
int kck_upload_shader_uniform_int(kck_shader_program* shader_program, const char* uniform_name, int value);
int kck_upload_shader_uniform_vec2(kck_shader_program* shader_program, const char* uniform_name, vec2* values);
int kck_upload_shader_uniform_vec3(kck_shader_program* shader_program, const char* uniform_name, vec3* values);
int kck_upload_shader_uniform_vec4(kck_shader_program* shader_program, const char* uniform_name, vec4* values);
int kck_upload_shader_uniform_mat4(kck_shader_program* shader_program, const char* uniform_name, mat4* values);