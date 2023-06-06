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
Address address;
 mem_element(){
     if(sizeof(T) > sizeof(Address)) {this->element = 0; } else this->address = 0;
 }
~mem_element(){}
};

typedef int mem_segment_type;
const int mem_segment_type_r  = 0b00000000;// 独立
const int mem_segment_type_s  = 0b00000001;// 单向
const int mem_segment_type_d  = 0b10000001;// 双向


#define DEFAULT_MEM_SEGMENT_SIZE 1024

/** 独立
 *  
 */
template <typename T>
class mem_segment{
public:
    Size  s_size;  // segment size
    Size  e_count; // element count
    Index s_index; // segment index
    mem_segment_type s_type; // segment type
    union mem_element<T>* elements;
public:
    mem_segment(){
        this->e_count = 0;
        this->s_index = 0;
        this->s_type  = mem_segment_type_s;
        if (this->elements = new mem_element<T>[DEFAULT_MEM_SEGMENT_SIZE]) {
            this->s_size = DEFAULT_MEM_SEGMENT_SIZE;
        }
    }

    mem_segment(const Size& size, const mem_segment_type& type = mem_segment_type_r) {
        this->e_count = 0;
        this->s_index = 0;

        switch(type){
        case mem_segment_type_r:{
            if (this->elements = new mem_element<T>[size]) {
                this->s_size = size;
                this->s_type = mem_segment_type_r;
                memclr(this->elements, sizeof(T) * (size), 0);
            }
        }break;
        case mem_segment_type_s: {
            if (this->elements = new mem_element<T>[size + 1]) {
                this->s_size = size;
                this->s_type = mem_segment_type_s;
                memclr(this->elements, sizeof(T) * (size + 1), 0);
            }
        }break;
        case mem_segment_type_d: {
            if (this->elements = new mem_element<T>[size + 2]) {
                this->s_size = size;
                this->s_type = mem_segment_type_d;
                memclr(this->elements,sizeof(T) * (size + 2),0);
            }
        }break;
        default:break;
        }
    }
    ~mem_segment(){
        if(this->elements) delete[] this->elements;
    }
public:
    Error append(const T& element){
        if(this->elements && this->s_size > this->e_count){ this->elements[this->e_count].element = element; this->e_count ++; return 0;}
        return 1;
    }
    /** insert
     *  向后移位
     */
    Error insert(const T& element,const Index& index){
        if(this->e_count < this->s_size){
            if(index < this->e_count){
                for(Index i = e_count;i > index;i --){
                    this->elements[i] = this->elements[i - 1];
                }
                this->elements[index].element = element;
                this->e_count++;
                return 0;
            }
            else {
                this->elements[index].element = element;
                this->e_count++;
                return 0;
            }
        }

        return 1;
    }
    /** remove
     *  向前移位
     */
    Error remove(const Index& index){
        if(index < this->e_count){
            for (Index i = index; i < this->e_count; i++) {
                this->elements[index].element = this->elements[index + 1].element;
            }

            this->e_count--;

            return 0;
        }

        return 1;
    }
    Error replace(const T& element, const Index& index) {
        if(index < this->e_count){
            this->elements[index].element = element;
            return 0;
        }

        return 1;
    }
public:
    Index lookup(const T& element) {
        for(Index i = 0;i < this->e_count;i ++){
            if(this->elements[i] == element) return i;
        }

        return 0xFFFFFFFF;
    }
    mem_element<T>& at(const Index& index){ return this->elements[index];}

    void setIndex(const Index& index){
        this->s_index = index;
    }

    Index index(){
        return this->s_index;
    }

    mem_segment* before(){ 
        switch(this->s_type){
        case mem_segment_type_d:return static_cast<mem_segment*>(this->elements[this->s_size].address);
        case mem_segment_type_s:return 0;
        default:return 0;
        }
    }
    mem_segment* behind(){
        switch (this->s_type) {
        case mem_segment_type_d:return static_cast<mem_segment*>(this->elements[this->s_size + 1].address);
        case mem_segment_type_s:return static_cast<mem_segment*>(this->elements[this->s_size].address);
        default:return 0;
        }
    }

    void setBefore(const mem_segment* segment){
        if(this->s_type == mem_segment_type_d){
            this->elements[this->s_size].address = segment;
        }
    }
    void setBehind(const mem_segment* segment){
        switch(this->s_type){
        case mem_segment_type_s:{this->elements[this->s_size].address = const_cast<mem_segment<T>*>(segment);}break;
        case mem_segment_type_d:{this->elements[this->s_size + 1].address = const_cast<mem_segment<T>*>(segment);}break;
        default:break;
        }
    }

    mem_element<T>& operator[] (const Size& index) { return this->elements[index];}
public:
    Size size(){ return this->s_size;}
    Size count(){ return this->e_count;}
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
 *    了解替罪羊树
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
