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
const int mem_segment_type_r  = 0b00000000;// 独立
const int mem_segment_type_s  = 0b00000001;// 单向
const int mem_segment_type_sb = 0b00000011;// 单向可分叉
const int mem_segment_type_d  = 0b10000001;// 双向
const int mem_segment_type_db = 0b10000011;// 双向可分叉

#define DEFAULT_MEM_SEGMENT_SIZE 1024

/** 独立
 *  
 */
template <typename T>
class mem_segment{
public:
    Size s_size;
    Size e_count;
    union mem_element<T>* elements;
public:
    mem_segment(){
        this->e_count = 0;
        if (elements = new mem_element<T>[DEFAULT_MEM_SEGMENT_SIZE]) {
            this->s_size = DEFAULT_MEM_SEGMENT_SIZE;
        }
    }
    mem_segment(Size& size) {
        this->e_count = 0;
        if (elements = new mem_element<T>[size]) {
            this->s_size = size;
        }
    }
    ~mem_segment(){
        if(elements) delete[] elements;
    }
public:
    Error append(const T& element){
        if(s_size > e_count){ elements[e_count] = element; e_count ++; return 1;}
        return 0;
    }
    /** insert
     *  向后移位
     */
    Error insert(const T& element,const Index& index){
        if(e_count < s_size){
            if(index < e_count){
                for(Index i = e_count;i > index;i --){
                    elements[i] = elements[i - 1];
                }
                elements[index] = element;
                e_count++;
                return 1;
            }
            else {
                elements[index] = element;
                e_count++;
                return 2;
            }
        }

        return 0;
    }
    /** remove
     *  向前移位
     */
    Error remove(const Index& index){
        if(index < e_count){
            for (Index i = index; i < e_count; i++) {
                elements[index] = elements[index + 1];
            }

            e_count--;

            return 1;
        }

        return 0;
    }
    Error replace(const T& element, const Index& index) {
        if(index < e_count){
            elements[index] = element;
            return 1;
        }

        return 0;
    }
public:
    Index lookup(const T& element) {
        for(Index i = 0;i < e_count;i ++){
            if(elements[i] == element) return i;
        }

        return 0xFFFFFFFF;
    }
    mem_element<T>& at(const Index& index){ return elements[index];}

    mem_segment* before(){ return 0;}
    mem_segment* behind(){ return 0;}

    mem_element<T>& operator[] (const Size& index) { return elements[index];}
public:
    Size size(){ return s_size;}
    Size count(){ return e_count;}
};

/** 单向连接
 *
 */
template <typename T>
class mem_segment_s{
public:
    Size s_size;
    Size e_count;
    Index index;
    Address next;
    union mem_element<T>* elements;/** [element][element][element][element][element][element][index][segment] */
public:
    mem_segment_s() {
        
    }
    mem_segment_s(const Size& size) {
        if (elements = new mem_element<T>[size]) {
            this->s_size = size;
            memclr(&elements[size + 2], sizeof(mem_element_s<T>) * 2);
        }
    }
    ~mem_segment_s() {
        
    }
public:
    Error append(const T& element) {
        if (s_size > e_count) { elements[e_count] = element; e_count++; return 1; }
        return 0;
    }
    /** insert
     *  向后移位
     */
    Error insert(const T& element, const Index& index) {
        if (e_count < s_size) {
            if (index < e_count) {
                for (Index i = e_count; i > index; i--) {
                    elements[i] = elements[i - 1];
                }
                elements[index] = element;
                e_count++;
                return 1;
            }
            else {
                elements[index] = element;
                e_count++;
                return 2;
            }
        }

        return 0;
    }
    /** remove
     *  向前移位
     */
    Error remove(const Index& index) {
        if (index < e_count) {
            for (Index i = index; i < e_count; i++) {
                elements[index] = elements[index + 1];
            }

            e_count--;

            return 1;
        }

        return 0;
    }
    Error replace(const T& element, const Index& index) {
        if (index < e_count) {
            elements[index] = element;
            return 1;
        }

        return 0;
    }
public:
    Index lookup(const T& element) {
        for (Index i = 0; i < e_count; i++) {
            if (elements[i] == element) return i;
        }

        return 0xFFFFFFFF;
    }

    mem_element<T>& at(const Index& index) { return elements[index]; }

    mem_segment_s* before() { return 0; }
    mem_segment_s* behind() { return 0; }

    mem_element<T>& operator[] (const Index& index) { return elements[index]; }
public:
    Size size() { return s_size; }
    Size count() { return e_count; }
};

/** 单向连接可分叉
 *
 */
template <typename T>
class mem_segment_sb {
public:
    Size s_size;
    Size e_count;
    Index index;
    Address next;
    char* branches;//[s / 8 + 1];
    union mem_element<T>* elements;/** [element][element][element][--|--][element][element][index][segment] */
public:
    mem_segment_sb() {
    }
    ~mem_segment_sb() {
    }
public:
    bool is_branch(const Index& index){
        Index i = index / 8;
        Index b = index % 8;

        char mask = 0b00000001 << b;
        return branches[i] & mask;
    }
    Size branch_count(){
        Size count = 0;

        for(Index i=0;i < e_count;i ++){
            count += is_branch(i) ? 1 : 0;
        }

        return count;
    }
public:
    Error append(const T& element) {
        if (s_size > e_count) { elements[e_count] = element; e_count++; return 1; }
        return 0;
    }
    /** insert
     *  向后移位
     */
    Error insert(const T& element, const Index& index) {
        if (e_count < s_size) {
            if (index < e_count) {
                for (Index i = e_count; i > index; i--) {
                    elements[i] = elements[i - 1];
                }
                elements[index] = element;
                e_count++;
                return 1;
            }
            else {
                elements[index] = element;
                e_count++;
                return 2;
            }
        }

        return 0;
    }
    /** remove
     *  向前移位
     */
    Error remove(const Index& index) {
        if (index < e_count) {
            for (Index i = index; i < e_count; i++) {
                elements[index] = elements[index + 1];
            }

            e_count--;

            return 1;
        }

        return 0;
    }
    Error replace(const T& element, const Index& index) {
        if (index < e_count) {
            elements[index] = element;
            return 1;
        }

        return 0;
    }
public:
    Index lookup(const T& element) {
        for (Index i = 0; i < e_count; i++) {
            if (elements[i] == element) return index;
        }

        return 0xFFFFFFFF;
    }
    mem_element<T>& at(const Index& index) { return elements[index]; }

    mem_segment_sb* before() { return 0; }
    mem_segment_sb* behind() { return 0; }

    mem_element<T>& operator[] (const Size& index) { return elements[index]; }
public:
    Size size()  { return s_size;  }
    Size count() { return e_count; }
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
