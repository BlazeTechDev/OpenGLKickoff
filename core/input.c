#include "input.h"

#include <stdio.h>

#include "../ext/c-vector/cvector_utils.h"

kck_key* kck_get_key(int glfw_key) {
    for(size_t i = 0; i < cvector_size(kck_input_context.active_keys); i++) {
        if(kck_input_context.active_keys[i].glfw_key == glfw_key) {
            return &kck_input_context.active_keys[i];
        }
    }

    return NULL;
}

int kck_is_key_pressed(int glfw_key) {
    if(kck_get_key(glfw_key) == NULL) return 0;
    return kck_get_key(glfw_key)->state == GLFW_PRESS ? 1 : 0;
}

int kck_is_key_held(int glfw_key) {
    if(kck_get_key(glfw_key) == NULL) return 0;
    return kck_get_key(glfw_key)->state == GLFW_REPEAT ? 1 : 0;
}

int kck_is_key_down(int glfw_key) {
    if(kck_get_key(glfw_key) == NULL) return 0;
    return kck_get_key(glfw_key)->state == GLFW_PRESS || GLFW_REPEAT ? 1 : 0;
}

int kck_is_key_up(int glfw_key) {
    if(kck_get_key(glfw_key) == NULL) return 0;
    return kck_get_key(glfw_key)->state == GLFW_RELEASE ? 1 : 0;
}

void kck_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    int contains_key = 0;
    kck_key* current_key_ptr;
    for(int i = 0; i < cvector_size(kck_input_context.active_keys); i++) {
        if(kck_input_context.active_keys[i].glfw_key == key) {
            contains_key = 1;
            current_key_ptr = &kck_input_context.active_keys[i];
        }
    }
    if(!contains_key) {
        kck_key current_key = {};
        current_key.glfw_key = key;
        current_key.state = action;
        cvector_push_back(kck_input_context.active_keys, current_key);
    }
    else {
        current_key_ptr->glfw_key = key;
        current_key_ptr->state = action;
    }
}
