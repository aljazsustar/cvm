#ifndef FILE_READER_H
#define FILE_READER_H

#define BUF_SIZE 100

#include "../util/util.h"

typedef struct file_info {
    byte* content;
    char* path;
    long size;
    long cursor;
} file_info;

byte* read_n_bytes(int n);
void get_file(const char* path);
file_info read_file(const char* path);

#endif