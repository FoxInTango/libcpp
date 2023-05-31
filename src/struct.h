#ifndef _LIB_CPP_STRUCT_H_foxintango
#define _LIB_CPP_STRUCT_H_foxintango
#include "memory.h"
#include "define.h"
namespaceBegin(foxintango)

/** 内存分片 : 拼接[前拼接,后拼接],截断
 */
template <typename T>
union mem_element {
T       element;
Index   index;
Address address;
};

typedef int mem_segment_type;
const int mem_segment_type_n = 0;// 独立
const int mem_segment_type_s = 1;// 单向
const int mem_segment_type_d = 2;// 双向

template <typename T, Size size, mem_segment_type t>
class mem_segment{
public:
    Size segment_size;
    Size element_count;
    mem_segment_type type;
    union mem_element<T> elements[size];/** pre nxt*/
    mem_segment(){
    }
    ~mem_segment(){
    /** delete subsegments
     */
    }

    T& at(const Size& index){ return T();}

    mem_segment* before(){ return 0;}
    mem_segment* behind(){ return 0;}

    T& operator[] (const Size& index) { return T();}
};

template <typename T, Size size>
class mem_segment<T, size, mem_segment_type_n> {
    Size segment_size;
    Size element_count;
    union mem_element<T> elements[size + mem_segment_type_n];/** pre nxt*/
    mem_segment() {
        /** clear ids
         */
    }
    ~mem_segment() {
        /** delete subsgements
         */
    }
};

template <typename T, Size size>
class mem_segment<T, size, mem_segment_type_s> {
public:
    Size segment_size;
    Size element_count;
    union mem_element<T> elements[size + mem_segment_type_s];/** pre nxt*/
    mem_segment() {
        /** clear ids
         */
    }
    ~mem_segment() {
        /** delete subsgements
         */
    }
public:
    T& operator[](const Index& index) {
        return elements[index];
    }
};

template <typename T, Size size>
class mem_segment<T, size, mem_segment_type_d> {
public:
    Size segment_size;
    Size element_count;
    union mem_element<T> elements[size + mem_segment_type_d];/** pre nxt*/
    mem_segment() {
        /** clear ids
         */
    }
    ~mem_segment() {
        /** delete subsgements
         */
    }
};

/** B-Tree
 */
template <typename T>
class tree_node_s {
    /** super
     */
    struct tree_node_s* s;
    /** left
     */
    struct tree_node_s* l;
    /** right
     */
    struct tree_node_s* r;
    T entity;
};

/** bst avl rbt
 *
 */

template <typename T>
unsigned long int tree_insert_node(struct tree_node_s<T>& t, const T& e) { return 0; }

template <typename T>
unsigned long int tree_remove_node(struct tree_node_s<T>& t, const T& e) { return 0; }

template <typename T>
T& tree_lookup_at(unsigned long int& index) { return T(); }

template <typename T>
T& tree_lookup_at(T& t) { return T(); }
namespaceEnd
#endif
