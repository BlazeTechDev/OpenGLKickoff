#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/core.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"
#include "graphics/utils.h"

int main(void)
{
    kck_graphics_context context = kck_initialize_context();

    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
       -0.5f, -0.5f, 0.0f,  // bottom left
       -0.5f,  0.5f, 0.0f   // top left
   };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    kck_vao vao = kck_create_vao();
    kck_vertex_buffer buffer = kck_create_vertex_buffer(12);
    kck_put_vertex_buffer(&buffer, vertices, 12);
    kck_index_buffer i_buffer = kck_create_index_buffer(6);
    kck_put_index_buffer(&i_buffer, indices, 6);
    kck_create_vertex_attrib_pointer(0, 3, GL_FLOAT);
    kck_bind_vao(0);

    kck_store_buffer_in_vao(&vao, &buffer.buffer, KCK_VERTEX_BUFFER);
    kck_store_buffer_in_vao(&vao, &i_buffer.buffer, KCK_INDEX_BUFFER);

    while (!glfwWindowShouldClose(context.window.glfwWindow)) {
        kck_begin_loop(&context);

        kck_draw_indexed(&vao);

        kck_end_loop(&context);
    }
    kck_destroy(&context);
}
