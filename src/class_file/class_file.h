#ifndef CLASS_FILE_H
#define CLASS_FILE_H

#include "constant_pool.h"
#include "fields.h"
#include "methods.h"
#include "attributes.h"

typedef struct class_file {
    unsigned int magic_number;
    unsigned short minor_version;
    unsigned short major_version;
    unsigned short cp_count;
    constant_pool* cp;
    unsigned short access_flags;
    unsigned short this_class;
    unsigned short super_class;
    unsigned short interfaces_count;
    unsigned short* interfaces;
    unsigned short field_count;
    fields* fields;
    unsigned short methods_count;
    methods* methods;
    unsigned short attribute_count;
    attributes* attributes;
} class_file;


#endif