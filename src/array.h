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
        Index index;
        T* element;
    public:
        Iterator() {
        }
        Iterator(const Index& index) {
        }
        Iterator(Array* owner, T* element) {
            this->owner = owner;
            this->element = element;
        }
        ~Iterator() {

        }
    public:
        void clean() {}
    public:
        Iterator& operator =  (const Index& index) { return *this;}
        Iterator& operator +  (const unsigned int& offset) { return *this; }
        Iterator& operator -  (const unsigned int& offset) { return *this; }
        Iterator& operator += (const unsigned int& offset) { return *this; }
        Iterator& operator -= (const unsigned int& offset) { return *this; }
        Iterator& operator ++ ()    { return *this; }
        Iterator& operator ++ (int) { return *this; }
        Iterator& operator -- ()    { return *this; }
        Iterator& operator -- (int) { return *this; }

        bool operator == (const Index& index) { return false;}
        bool operator == (const Iterator& iterator) { return false; }
        bool operator != (const Index& index) { return false; }
        bool operator != (const Iterator& iterator) { return false; }

        T& operator *() { return *element; }
        T& operator *(const Iterator& iter) { return *element; }
    };
    class Range{
    public:
       void forEach(){} 
    };
public:
    Iterator i_begin;
    Iterator i_end;
    mem_segment<T> elements;
    Size a_size;/** array size */
    Size e_count;/** element count */
public:
    Array() {
        // 处理begin & end
    }
    Array(const Size& size){
    }
   ~Array(){
    }
public:
    Size append(const T& t)  { return 0; }
    Size insert(const T& t,const Index& index)  { return 0; }
    Size remove(const Index& index)  { return 0; }
    Size remove(const Iterator& index) { return 0; }
    Size replace(const Index& index) { return 0; }
    Size replace(const Iterator& index) { return 0; }

    Error swap(const unsigned int& l, const unsigned int& r) { return 0; }
    T& at(const unsigned int& index) {}

    Size size() { return Size();}
    Size size() const { return Size(); }

    Iterator& begin(){ return this->i_begin; }
    Iterator& end()  { return this->i_end;   }
public:
    T& operator[](const Index& index){ return elements[index]; }
};

namespaceEnd

#endif // !_ARRAY_H_foxintango
