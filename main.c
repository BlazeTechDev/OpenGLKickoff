#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/core.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"

int main(void)
{
    kck_graphics_context context = kck_initialize_context();

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    kck_vao vao = kck_create_vao();
    kck_vertex_buffer buffer = kck_create_vertex_buffer(9);
    kck_put_vertex_buffer(&buffer, vertices, 9);
    kck_create_vertex_attrib_pointer(0, 3, GL_FLOAT);

    while (!glfwWindowShouldClose(context.window.glfwWindow)) {
        kck_begin_loop(&context);

        glBindVertexArray(vao.id);

        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glDisableVertexAttribArray(0);

        kck_end_loop(&context);
    }
    kck_destroy(&context);
}
