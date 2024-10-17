//
// Created by Osprey on 10/17/2024.
//

#include "window.h"

#include <stdio.h>

kckWindow createWindow(char* title, int width, int height) {
    kckWindow w = {};
    w.title = title;
    w.width = width;
    w.height = height;

    w.glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    return w;
}
