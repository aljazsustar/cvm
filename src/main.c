#include<stdio.h>
#include<stdlib.h>

#include "parser/parse.h"
#include "io/file_reader.h"

int main() {
    file_info file = read_file("java/target/Example.class");

    for(int i = 0; i < file.size; i++) {
        printf("%X ", file.content[i]);
    }

    printf("\n");
    printf("File size is %ld bytes\n", file.size);
    return 0;
}