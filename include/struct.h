#ifndef _LIB_CPP_STRUCT_foxintango
#define _LIB_CPP_STRUCT_foxintango
#include "define.h"


namespaceBegin(foxintango)

/** 说明
 *  正常结构体   :
 *  离散结构体组 :
 *  对齐结构体组 :
 *  结构体集合   :
 *
 * */

enum struct_range_element_spy_t {
    struct_range_element_spy_beg, // array begin
    struct_range_element_spy_end, // array end
    struct_range_element_spy_ptr
};

struct struct_range_element_spy_s {
    enum struct_range_element_spy_t type;
    union {
        void* ptr;
    } entity;
};

template <typename S>
bool struct_range_element_is_spy(S* s) {
    if(s) {
        struct_range_element_spy_s* p = (struct_range_element_spy_s*)s;
        return p->type == struct_range_element_spy_beg || p->type == struct_range_element_spy_end || p->type == struct_range_element_spy_ptr ? true : false;
    }

    return false;
}

struct struct_range_element_header_s {
    struct_range_element_header_s* prev;
    struct_range_element_header_s* next;
};
/**
template <typename S>
S* struct_array_prve(S* s,const int& size) {
    if(!s) return nullptr;

    if(s->type == struct_range_element_header_beg) return nullptr;

    return s - size;
}*/

/**
template <typename S>
S* struct_array_next(S* s,const int& size) {
    if(!s) return nullptr;

    if(s->type == struct_range_element_header_end) return nullptr;

    return s + size;
}*/

// struct_array_at
// struct_array_begin
// struct_array_end

/** 
 * @ size : sizeof(S)
 * return : entity of struct s with header as rang end.
 * NOTE   : sizeof(S) > sizeof(struct_range_element_header_s).
 * */
template <typename S>
S struct_range_element_spy_make_end(const int& size) {
    S s;
    struct_range_element_spy_s* p = (struct_range_element_spy_s*)(&s);
    p->type = struct_range_element_spy_end;
}
namespaceEnd
#endif
