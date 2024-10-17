#include <GLFW/glfw3.h>

#include "core/core.h"

int main(void)
{
    kckContext context = kckInitializeGLFW();
    while (!glfwWindowShouldClose(context.window.glfwWindow)) {
        kckBeginLoop(&context);

        //custome code here

        kckEndLoop(&context);
    }
    kckDestroy(&context);
}