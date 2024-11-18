#pragma once

#ifndef INPUT_H
#define INPUT_H

#endif //INPUT_H

#include "GLFW/glfw3.h"

#include "../ext/c-vector/cvector.h"

typedef struct kck_key {
    int glfw_key;
    int state;
} kck_key;

static struct kck_input_context {
    cvector_vector_type(kck_key) active_keys;
} kck_input_context;

kck_key* kck_get_key(int glfw_key);

int kck_is_key_pressed(int glfw_key);
int kck_is_key_held(int glfw_key);
int kck_is_key_down(int glfw_key);
int kck_is_key_up(int glfw_key);

void kck_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
