//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#endif //WINDOW_H

typedef struct kckWindow
{
    GLFWwindow* glfwWindow;
    char* title;
    int width, height;
} kckWindow;

kckWindow createWindow(char* title, int width, int height);