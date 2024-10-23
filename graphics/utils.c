//
// Created by Osprey on 10/18/2024.
//

#include "utils.h"

#include <glad/glad.h>

int kck_draw_indexed(kck_vao* vao, kck_shader_program* program) {
    glBindVertexArray(vao->id);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
