//
// Created by Osprey on 10/17/2024.
//

#pragma once

#ifndef CORE_H
#define CORE_H

#include "window.h"

#endif //CORE_H

typedef struct {
    kckWindow window;
} kckContext;

kckContext kckInitializeGLFW();

int kckBeginLoop(kckContext* context);
int kckEndLoop(kckContext* context);
int kckDestroy(kckContext* context);