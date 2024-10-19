//
// Created by Osprey on 10/17/2024.
//

#include <stdio.h>
#include "io.h"

#include <stdlib.h>
#include <string.h>

const char* kck_read_file_local(const char* local_path)
{
    FILE *fp;
    long size = 0;
    char* shaderContent;

    /* Read File to get size */
    fp = fopen(local_path, "rb");
    if(fp == NULL) {
        return "";
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp)+1;
    fclose(fp);

    /* Read File for Content */
    fp = fopen(local_path, "r");
    shaderContent = memset(malloc(size), '\0', size);
    fread(shaderContent, 1, size-1, fp);
    fclose(fp);

    return shaderContent;
}
