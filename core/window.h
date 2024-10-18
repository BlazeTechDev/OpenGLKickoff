//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#endif //WINDOW_H

typedef struct kck_window
{
    GLFWwindow* glfwWindow;
    char* title;
    int width, height;
} kck_window;

kck_window kck_create_window(char* title, int width, int height);