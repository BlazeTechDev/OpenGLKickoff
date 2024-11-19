//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#endif //WINDOW_H

#include "../ext/c-vector/cvector.h"

typedef struct kck_window
{
    GLFWwindow* glfwWindow;
    char* title;
    int width, height;
} kck_window;

static struct kck_window_context {
    cvector_vector_type(kck_window) open_windows;
} kck_window_context;

kck_window kck_create_window(char* title, int width, int height);

void kck_window_resize_callback(GLFWwindow* window, int width, int height);

void kck_windowing_free();