//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef BUFFER_H
#define BUFFER_H

#endif //BUFFER_H

typedef struct kck_buffer {
    unsigned int id;
    unsigned int size;
} kck_buffer;

typedef enum kck_buffer_type {
    KCK_VERTEX_BUFFER,
    KCK_INDEX_BUFFER,
} kck_buffer_type;

typedef struct kck_vertex_buffer {
    kck_buffer buffer;
    int vertexCount;
} kck_vertex_buffer;

typedef struct kck_index_buffer {
    kck_buffer buffer;
    int indexCount;
} kck_index_buffer;

typedef struct kck_vao {
    unsigned int id;
    kck_buffer* vertex_buffer;
    kck_buffer* index_buffer;
} kck_vao;

kck_vao kck_create_vao();
int kck_bind_vao(kck_vao* vao);

int kck_store_buffer_in_vao(kck_vao* vao, kck_buffer* buffer, kck_buffer_type buffer_type);

kck_buffer kck_create_buffer();

kck_vertex_buffer kck_create_vertex_buffer(int vertexCount);
int kck_put_vertex_buffer(kck_vertex_buffer* buffer, float* data, int data_size);
int kck_create_vertex_attrib_pointer(int location, int size, int type);

kck_index_buffer kck_create_index_buffer(int indexCount);
int kck_put_index_buffer(kck_index_buffer* buffer, int* data, int data_size);