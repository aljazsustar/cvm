#ifndef FILE_READER_H
#define FILE_READER_H

#define BUF_SIZE 100
typedef unsigned char byte;

typedef struct file_info {
    byte* content;
    char* path;
    long size;
} file_info;

void read_n_bytes(int n, unsigned char* dest);
void get_file(const char* path);
file_info read_file(const char* path);

#endif