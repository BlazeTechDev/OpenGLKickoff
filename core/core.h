//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef CORE_H
#define CORE_H

#include "window.h"

#endif //CORE_H

typedef struct kck_graphics_context{
    kck_window window;
} kck_graphics_context;

kck_graphics_context kck_initialize_graphics_context();

int kck_begin_loop(kck_graphics_context* context);
int kck_end_loop(kck_graphics_context* context);
int kck_destroy(kck_graphics_context* context);
