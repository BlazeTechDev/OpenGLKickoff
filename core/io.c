//
// Created by Osprey on 10/17/2024.
//

#include <stdio.h>
#include "io.h"

const char* kck_read_file_local(const char* local_path)
{
    FILE* file = fopen(local_path, "r");
    char string[1000];
    fgets(string, 1000, file);
    return &string;
}