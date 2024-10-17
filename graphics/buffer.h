//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef BUFFER_H
#define BUFFER_H

#endif //BUFFER_H

typedef struct kckBuffer {
    __uint128_t id;
    __uint128_t size;
} kck_buffer;

typedef struct kckVertexBuffer {
    kck_buffer buffer;
    int vertexCount;
} kckVertexBuffer;

typedef struct kckIndexBuffer {
    kck_buffer buffer;
    int indexCount;
} kckIndexBuffer;