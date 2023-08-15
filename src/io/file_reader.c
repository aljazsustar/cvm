#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "file_reader.h"

byte* BUF;
unsigned int buf_cursor = 0;
FILE* file;

file_info* info;

void get_file(const char* path) {

    file = fopen(path, "rb");

    if (file == NULL) {
        perror("Error reading input file");
    }
}

file_info read_file(const char* path) {

    file_info* res = (file_info*)malloc(sizeof(file_info));

    get_file(path);
    fseek(file, 0, SEEK_END); // seek to end of file
    long size = ftell(file); // get current file pointer
    BUF = (byte*)malloc(size);
    fseek(file, 0, SEEK_SET); // seek to end of file
    fread(BUF, 1, size, file);

    res->content = BUF;
    res->size = size;
    res->path = path;
    
    info = res;
    file_info val = *res;
    free(res);

    return val;
}

void update_buffer() {
    buf_cursor = 0;
    fread(BUF, 1, BUF_SIZE, file);
}

byte* read_n_bytes(int n) {

    byte* res = (byte*)malloc(sizeof(byte));
    memcpy(&res[info->cursor], info->content, n);

    info->cursor += n;

    return res;
}