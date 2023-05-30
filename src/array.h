#ifndef _ARRAY_H_foxintango
#define _ARRAY_H_foxintango

#include "struct.h"
#include "define.h"
namespaceBegin(foxintango)

/** TODO
 *  Fill with model from libcpp_startup(Model&) 
 */
const unsigned int ARRAY_DEFAULT_SIZE = 32;

template <class T>
class Array{
public:
    class Iterator {
    public:
        Array* owner;
        T* element;
    public:
        Iterator() {
            
        }
        Iterator(Array* owner) {
            this->owner = owner;
        }
        ~Iterator() {

        }
    public:
        void clean() {}
    public:
        Iterator& operator = (const Index& index) { return *this;}

        Iterator& operator +  (const unsigned int& offset) { return *this; }
        Iterator& operator -  (const unsigned int& offset) { return *this; }
        Iterator& operator += (const unsigned int& offset) { return *this; }
        Iterator& operator -= (const unsigned int& offset) { return *this; }
        Iterator& operator ++ () { return *this; }
        Iterator& operator -- () { return *this; }

        bool operator == (const Index& index) { return false;}
        bool operator == (const Iterator& iterator) { return false; }
        T& operator *() { return T(); }
        T& operator *(const Iterator& iter) { return T(); }
    };
    class Range{
    public:
       void forEach(){} 
    };
public:
    Iterator iterator;
    mem_segment<T, ARRAY_DEFAULT_SIZE, mem_segment_type_s> elements;
    Size array_size;
    Size entity_count;
public:
    Array() {
        iterator.owner = this;
    }
    Array(const Size& size){
    }
   ~Array(){
    }
public:
    unsigned int append(const T& t)  { return 0; }
    unsigned int insert()  { return 0; }
    unsigned int remove()  { return 0; }
    unsigned int replace() { return 0; }

    Iterator begin(){ return Iterator(); }
    Iterator end() { return Iterator(); }

    int swap(const unsigned int& l,const unsigned int& r) { return 0; }
    T& at(const unsigned int& index){}
    T* addressOf(const unsigned int& index){ return 0; }
public:
    T& operator[](const unsigned int& index){ return T();}
};

namespaceEnd

#endif // !_ARRAY_H_foxintango