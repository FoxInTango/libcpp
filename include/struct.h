#ifndef _LIB_CPP_STRUCT_foxintango
#define _LIB_CPP_STRUCT_foxintango
#include "define.h"

enum   struct_header_t {
    struct_header_end,
    struct_header_normal
};

struct struct_header_s {
    enum struct_header_t type;
};
#endif
