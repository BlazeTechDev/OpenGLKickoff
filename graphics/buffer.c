//
// Created by Osprey on 10/17/2024.
//

#include "buffer.h"

#include <glad/glad.h>

kck_vao kck_create_vao() {
    kck_vao vao = {};
    glGenVertexArrays(1, &vao.id);
    glBindVertexArray(vao.id);
    return vao;
}

kck_buffer kck_create_buffer() {
    kck_buffer buffer = {};
    glGenBuffers(1, &buffer.id);
    return buffer;
}

kck_vertex_buffer kck_create_vertex_buffer(int vertexCount) {
    kck_vertex_buffer vBuffer = {};
    kck_buffer buffer = kck_create_buffer();
    vBuffer.buffer = buffer;
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

kck_index_buffer kck_create_index_buffer(int indexCount) {
    kck_index_buffer iBuffer = {};
    kck_buffer buffer = kck_create_buffer();
    iBuffer.buffer = buffer;
    return iBuffer;
}

int kck_put_index_buffer(kck_index_buffer* iBuffer, int* data) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer->buffer.id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}
