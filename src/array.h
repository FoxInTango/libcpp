#ifndef _ARRAY_H_foxintango
#define _ARRAY_H_foxintango

#include "iterator.h"
#include "struct.h"
#include "define.h"
namespaceBegin(foxintango)

/** TODO
 *  Fill with model from libcpp_startup(Model&) 
 */
static unsigned int ARRAY_DEFAULT_SIZE = 32;
template <class T,Size size = ARRAY_DEFAULT_SIZE>
class Array{
public:
Iterator<T, Array> iterator;
protected:
    mem_segment<T, size, mem_segment_type_s> elements;
    Size array_size;
    Size entity_count;
public:
    Array() {
        iterator.owner = this;
    }
    Array(const Size& size){
    }
   ~Array(){
       elements.~mem_segment();
    }
public:
    unsigned int append(const T& t)  { return 0; }
    unsigned int insert()  { return 0; }
    unsigned int remove()  { return 0; }
    unsigned int replace() { return 0; }

    Iterator<T, Array> begin(){ return Iterator<T, Array>(); }
    Iterator<T, Array> end() { return Iterator<T, Array>(); }

    int swap(const unsigned int& l,const unsigned int& r) { return 0; }
    T& at(const unsigned int& index){}
    T* addressOf(const unsigned int& index){ return 0; }
public:
    T& operator[](const unsigned int& index){ return T();}
};

namespaceEnd

#endif // !_ARRAY_H_foxintango