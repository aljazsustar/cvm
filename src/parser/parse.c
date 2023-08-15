#include <stdio.h>
#include <stdlib.h>

#include "../class_file/class_file.h"
#include "../io/file_reader.h"
#include "../util/util.h"

unsigned int parse_magic_number() {
    return bytes_to_int(read_n_bytes(4));
}

class_file parse() {
    class_file* cf = (class_file*)malloc(sizeof(class_file));
    cf->magic_number = parse_magic_number();

    class_file res = *cf;
    free(cf);
    return res;
}

