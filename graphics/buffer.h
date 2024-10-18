//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef BUFFER_H
#define BUFFER_H

#endif //BUFFER_H

typedef struct kck_vao {
    unsigned int id;
} kck_vao;

typedef struct kck_buffer {
    unsigned int id;
    unsigned int size;
} kck_buffer;

typedef struct kck_vertex_buffer {
    kck_buffer buffer;
    int vertexCount;
} kck_vertex_buffer;

typedef struct kck_index_buffer {
    kck_buffer buffer;
    int indexCount;
} kck_index_buffer;

kck_vao kck_create_vao();

kck_buffer kck_create_buffer();

kck_vertex_buffer kck_create_vertex_buffer(int vertexCount);
int kck_put_vertex_buffer(kck_vertex_buffer* buffer, float* data, int data_size);
int kck_create_vertex_attrib_pointer(int location, int size, int type);

kck_index_buffer kck_create_index_buffer(int indexCount);
int kck_put_index_buffer(kck_index_buffer* buffer, int* data, int data_size);