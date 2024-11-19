//
// Created by Osprey on 10/17/2024.
//

#include "window.h"

#include <stdio.h>

#include "input.h"

kck_window kck_create_window(char* title, int width, int height) {
    kck_window window = {};
    window.title = title;
    window.width = width;
    window.height = height;

    window.glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    
    return window;
}

void kck_window_resize_callback(GLFWwindow* window, int width, int height) {
    for(int i = 0; i < cvector_size(kck_window_context.open_windows); i++) {
        if(&kck_window_context.open_windows[i] != NULL && kck_window_context.open_windows[i].glfwWindow == window) {
            kck_window_context.open_windows[i].width = width;
            kck_window_context.open_windows[i].height = height;
        }
    }
}

void kck_windowing_free() {
    cvector_free(kck_window_context.open_windows);
}