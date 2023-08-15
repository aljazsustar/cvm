#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "file_reader.h"

byte* BUF;
unsigned int buf_cursor = 0;
FILE* file;

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
    
    file_info val = *res;
    free(res);

    return val;
}

void update_buffer() {
    buf_cursor = 0;
    fread(BUF, 1, BUF_SIZE, file);
}

void read_n_bytes(int n, unsigned char* dest) {

    buf_cursor += n;

    if (buf_cursor >= BUF_SIZE) {
        int remaining = BUF_SIZE - (buf_cursor - n);
        printf("Remaining: %d\n", remaining);
        memcpy(dest, &BUF[buf_cursor], remaining);
        update_buffer();
        printf("Left to copy: %d\n", n - remaining);
        printf("Buf cursor: %d\n", buf_cursor);
        memcpy(&dest[remaining],BUF, n - remaining);
        buf_cursor += n - remaining;
    } else {
        memcpy(dest, &BUF[buf_cursor], n);
    }
}