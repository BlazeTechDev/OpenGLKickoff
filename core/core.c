//
// Created by Osprey on 10/17/2024.
//

#include "core.h"

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

kckContext kckInitializeGLFW() {
    kckContext context = {};
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    // cout << "default shader lang: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

    // select opengl version
    // int major, minor, rev;
    // glfwGetVersion(&major, &minor, &rev);
    // cout << "glfw major.minor " << major << "." << minor << "." << rev << endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    context.window = createWindow("OpenGL Example", 640, 480);
    if (!context.window.glfwWindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(context.window.glfwWindow);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader(glfwGetProcAddress))
    {
        printf("Failed to Initialize Glad");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    return context;
}

int kckBeginLoop(kckContext* context) {
    // Clear color buffer to black
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int kckEndLoop(kckContext* context) {
    // Swap buffers
    glfwSwapBuffers( context->window.glfwWindow);
    glfwPollEvents();
}

int kckDestroy(kckContext* context) {
    glfwDestroyWindow(context->window.glfwWindow);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}