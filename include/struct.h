#ifndef _LIB_CPP_STRUCT_foxintango
#define _LIB_CPP_STRUCT_foxintango
#include "define.h"

namespaceBegin(foxintango)
/** 说明
 *  独立结构体   :
 *  离散结构体组 :
 *  对齐结构体组 :
 *  结构体集合   :
 *
 * */

/** 
 *     8  7  6  5  4  3  2  1
 *  0b X  X  X  X  X  X  X  X
 *     |              |  |  |- 是否结尾
 *     |              |  |---- 是否指向下一元素
 *     |              |-------_是否指向上一元素
 *     |---------------------- 是否开头
 *
 *     |-- |--> --|  <--| <-|->
 *
 *     NOTE : 碰撞问题
 * */
enum struct_range_element_spy_t {
    struct_range_element_spy_nul = 0b00000000,
    struct_range_element_spy_beg = 0b10000000, // array begin
    struct_range_element_spy_end = 0b00000001, // array end
    struct_range_element_spy_prv = 0b00000100, // pointer to another element
    struct_range_element_spy_nxt = 0b00000010, // link 
};

/**
struct struct_range_element_spy_lnk_s {
    void* prev;
    void* next;
};
struct struct_range_element_spy_ptr_s {
    void* next;
};

union struct_range_element_spy_entity {
    struct_range_element_spy_lnk_s lnk;
    struct_range_element_spy_ptr_s ptr;
};
*/

struct struct_range_element_spy_s {
    enum  struct_range_element_spy_t type;
    void* prev = nullptr;
    void* next = nullptr;
};

/** 判定方式
 *  
 * */
template <typename S>
bool struct_range_element_is_spy(S* s) {
    if(s) {
        struct_range_element_spy_s* p = (struct_range_element_spy_s*)s;
        return ( p->type & struct_range_element_spy_beg ) || 
               ( p->type & struct_range_element_spy_end ) || 
               ( p->type & struct_range_element_spy_prv ) || 
               ( p->type & struct_range_element_spy_nxt ) ? true : false;
    }

    return false;
}

/**
struct struct_range_element_header_s {
    struct_range_element_header_s* prev;
    struct_range_element_header_s* next;
};
*/

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

template <typename S>
void struct_range_element_spy_make(S& s,const enum struct_range_element_spy_t& t) {
    struct_range_element_spy_s* p = (struct_range_element_spy_s*)(&s);
    p->type = t;
}

template <typename S>
void struct_range_element_spy_make_beg(S& s) {
    struct_range_element_spy_s* p = (struct_range_element_spy_s*)(&s);
     p->type |= struct_range_element_spy_beg;
}
/** 
 * @ size : sizeof(S)
 * return : entity of struct s with header as rang end.
 * NOTE   : sizeof(S) > sizeof(struct_range_element_header_s).
 * */
template <typename S>
void struct_range_element_spy_make_end(S& s) {
    struct_range_element_spy_s* p = (struct_range_element_spy_s*)(&s);
    p->type |= struct_range_element_spy_end;
}

template <typename S>
unsigned int struct_range_element_count(const S& s) {
    return 0;
}

template <typename S>
int struct_range_element_append();
template <typename S>
int struct_range_element_insert();
template <typename S>
int struct_range_element_remove();
template <typename S>
S* struct_range_element_at();

int struct_range_clone(const int& beg = 0,const int& end = -1);
int struct_range_contact();
namespaceEnd
#endif
