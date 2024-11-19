#include "core.h"

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>

#include "input.h"


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

kck_graphics_context kck_initialize_graphics_context() {
    kck_graphics_context context = {};
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

    context.window = kck_create_window("OpenGL Example", 640, 480);
    if (!context.window.glfwWindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(context.window.glfwWindow, kck_key_callback);
    glfwSetMouseButtonCallback(context.window.glfwWindow, kck_mouse_button_callback);
    glfwSetScrollCallback(context.window.glfwWindow, kck_mouse_scroll_callback);
    glfwSetCursorPosCallback(context.window.glfwWindow, kck_mouse_motion_callback);
    glfwSetWindowSizeCallback(context.window.glfwWindow, kck_window_resize_callback);

    glfwMakeContextCurrent(context.window.glfwWindow);

    if (!gladLoadGLLoader(glfwGetProcAddress)) {
        printf("Failed to Initialize Glad");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    return context;
}

int kck_begin_loop(kck_graphics_context* context) {
    // Clear color buffer to black
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int kck_end_loop(kck_graphics_context* context) {
    // Swap buffers
    glfwSwapBuffers(context->window.glfwWindow);
    glfwPollEvents();
}

int kck_destroy(kck_graphics_context* context) {
    glfwDestroyWindow(context->window.glfwWindow);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}