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

kck_key* kck_get_button(int glfw_button) {
    for(size_t i = 0; i < cvector_size(kck_input_context.active_mouse_buttons); i++) {
        if(kck_input_context.active_mouse_buttons[i].glfw_key == glfw_button) {
            return &kck_input_context.active_mouse_buttons[i];
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

int kck_is_button_pressed(int glfw_button) {
    if(kck_get_button(glfw_button) == NULL) return 0;
    return kck_get_button(glfw_button)->state == GLFW_PRESS ? 1 : 0;
}

int kck_is_button_held(int glfw_button) {
    if(kck_get_button(glfw_button) == NULL) return 0;
    return kck_get_button(glfw_button)->state == GLFW_REPEAT ? 1 : 0;
}

int kck_is_button_down(int glfw_button) {
    if(kck_get_button(glfw_button) == NULL) return 0;
    return kck_get_button(glfw_button)->state == GLFW_PRESS || GLFW_REPEAT ? 1 : 0;
}

int kck_is_button_up(int glfw_button) {
    if(kck_get_button(glfw_button) == NULL) return 0;
    return kck_get_button(glfw_button)->state == GLFW_RELEASE ? 1 : 0;
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

void kck_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    int contains_button = 0;
    kck_key* current_button_ptr;
    for(int i = 0; i < cvector_size(kck_input_context.active_mouse_buttons); i++) {
        if(kck_input_context.active_mouse_buttons[i].glfw_key == button) {
            contains_button = 1;
            current_button_ptr = &kck_input_context.active_mouse_buttons[i];
        }
    }
    if(!contains_button) {
        kck_key current_key = {};
        current_key.glfw_key = button;
        current_key.state = action;
        cvector_push_back(kck_input_context.active_mouse_buttons, current_key);
    }
    else {
        current_button_ptr->glfw_key = button;
        current_button_ptr->state = action;
    }
}

void kck_mouse_motion_callback(GLFWwindow* window, double xpos, double ypos) {
    printf("%f\n", xpos);
    kck_input_context.mouse_position_delta[0] = (float)xpos - kck_input_context.mouse_position[0];
    kck_input_context.mouse_position_delta[1] = (float)ypos - kck_input_context.mouse_position[1];
    kck_input_context.mouse_position[0] = (float)xpos;
    kck_input_context.mouse_position[1] = (float)ypos;
}

void kck_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    kck_input_context.mouse_scroll_delta[0] = (float)xoffset - kck_input_context.mouse_scroll[0];
    kck_input_context.mouse_scroll_delta[1] = (float)yoffset - kck_input_context.mouse_scroll[1];
    kck_input_context.mouse_scroll[0] = (float)xoffset;
    kck_input_context.mouse_scroll[1] = (float)yoffset;
}

void kck_input_free() {
    for(int i = 0; i < cvector_size(kck_input_context.active_keys); i++) {
        cvector_free(kck_input_context.active_keys);
    }
    for(int i = 0; i < cvector_size(kck_input_context.active_mouse_buttons); i++) {
        cvector_free(kck_input_context.active_mouse_buttons);
    }
}