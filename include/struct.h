#ifndef _LIB_CPP_STRUCT_foxintango
#define _LIB_CPP_STRUCT_foxintango
#include "define.h"


namespaceBegin(foxintango)

enum   struct_header_t {
    struct_header_beg, // array begin
    struct_header_end, // array end
    struct_header_nor  // array normal
};

struct struct_header_s {
    enum struct_header_t type;
    int size = -1;
};

template <typename S>
S* struct_array_prve(S* s,const int& size) {
    if(!s) return nullptr;

    if(s->header->type == struct_header_beg) return nullptr;

    return s - size;
}

template <typename S>
S* struct_array_next(S* s,const int& size) {
    if(!s) return nullptr;

    if(s->type == struct_header_end) return nullptr;

    return s + size;
}

// struct_array_at
// struct_array_begin
// struct_array_end
namespaceEnd
#endif
