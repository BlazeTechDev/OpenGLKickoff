//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef SHADER_H
#define SHADER_H

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

int kck_load_shader(kck_shader* shader, const char* local_path, kck_shader_type shader_type);
int kck_load_shader_program(kck_shader_program* shader_program, kck_shader* vertex_shader, kck_shader* fragment_shader);