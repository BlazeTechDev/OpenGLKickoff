//
// Created by Osprey on 10/17/2024.
//

#include "buffer.h"

#include <glad/glad.h>

#include "../../../AppData/Local/Programs/CLion/bin/mingw/lib/gcc/x86_64-w64-mingw32/13.1.0/include/stddef.h"

kck_vao kck_create_vao() {
    kck_vao vao = {};
    glGenVertexArrays(1, &vao.id);
    glBindVertexArray(vao.id);
    return vao;
}

int kck_bind_vao(kck_vao* vao) {
    if(vao == NULL) {
        glBindVertexArray(0);
    }
    else {
        glBindVertexArray(vao->id);
    }
}

int kck_store_buffer_in_vao(kck_vao* vao, kck_buffer* buffer, kck_buffer_type buffer_type) {
    switch (buffer_type) {
        case KCK_VERTEX_BUFFER:
            vao->vertex_buffer = buffer;
        case KCK_INDEX_BUFFER:
            vao->index_buffer = buffer;
        default:
            break;
    }
}

kck_buffer kck_create_buffer() {
    kck_buffer buffer = {};
    glGenBuffers(1, &buffer.id);
    return buffer;
}

kck_vertex_buffer kck_create_vertex_buffer(int vertex_data_size) {
    kck_vertex_buffer vBuffer = {};
    kck_buffer buffer = kck_create_buffer();
    vBuffer.buffer = buffer;
    vBuffer.vertexCount = vertex_data_size / 3;
    return vBuffer;
}

int kck_put_vertex_buffer(kck_vertex_buffer* vBuffer, float* data, int data_size) {
    glBindBuffer(GL_ARRAY_BUFFER, vBuffer->buffer.id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data_size, data, GL_STATIC_DRAW);
}

int kck_create_vertex_attrib_pointer(int location, int size, int type) {
    glVertexAttribPointer(location, size, type, GL_FALSE, size * sizeof(float), (void*)0);
    glEnableVertexAttribArray(location);
}

kck_index_buffer kck_create_index_buffer(int index_count) {
    kck_index_buffer iBuffer = {};
    kck_buffer buffer = kck_create_buffer();
    iBuffer.buffer = buffer;
    iBuffer.indexCount = index_count;
    return iBuffer;
}

int kck_put_index_buffer(kck_index_buffer* iBuffer, int* data, int data_size) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer->buffer.id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * data_size, data, GL_STATIC_DRAW);
}
