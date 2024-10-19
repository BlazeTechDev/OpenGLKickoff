//
// Created by Osprey on 10/18/2024.
//

#include "utils.h"

#include <glad/glad.h>

int kck_draw_indexed(kck_vao* vao) {
    glBindVertexArray(vao->id);

    glEnableVertexAttribArray(0);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
}
