#pragma once

#ifndef INPUT_H
#define INPUT_H

#endif //INPUT_H

#include "GLFW/glfw3.h"
#include "../ext/c-vector/cvector.h"
#include <cglm/call/ivec3.h>

typedef struct kck_key {
    int glfw_key;
    int state;
} kck_key;

static struct kck_input_context {
    cvector_vector_type(kck_key) active_keys;
    cvector_vector_type(kck_key) active_mouse_buttons;
    vec2 mouse_position;
    vec2 mouse_position_delta;
    vec2 mouse_scroll;
    vec2 mouse_scroll_delta;
} kck_input_context;

kck_key* kck_get_key(int glfw_key);
kck_key* kck_get_button(int glfw_button);

//keys
int kck_is_key_pressed(int glfw_key);
int kck_is_key_held(int glfw_key);
int kck_is_key_down(int glfw_key);
int kck_is_key_up(int glfw_key);

//buttons
int kck_is_button_pressed(int glfw_button);
int kck_is_button_held(int glfw_button);
int kck_is_button_down(int glfw_button);
int kck_is_button_up(int glfw_button);

//glfw callbacks
void kck_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void kck_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void kck_mouse_motion_callback(GLFWwindow* window, double xpos, double ypos);
void kck_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void kck_input_free();