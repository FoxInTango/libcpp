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
        Array* target;
        Index index;
        T* element;
    public:
        Iterator() {
            this->target = target;
            this->element = element;
            this->index = UNSIGNED_LONG_MAX;
        }
        Iterator(Array* target,const Index& index) {
            if(!target) return;

            this->target  = target;
            this->index   = index;
            this->element = target->elementAt(index);
        }
        Iterator(Array* target, T* element) {
            if(!target || !element) return ;
            this->target  = target;
            this->element = element;
            this->index   = target->indexOf(element);
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

        operator T(){ return *element; }
    };
    class Range{
    public:
        Array* target;
        Index begin;
        Index end;
    public:
       void forEach(){} 
    };
public:
    Iterator i_begin;
    Iterator i_end;
    mem_segment_s<T> elements;
    Size a_size;/** array size */
    Size e_count;/** element count */
public:
    Array() {
        // 处理begin & end
    }
    Array(const Size& size,const Size& segment_size = 0) {
        // 处理begin & end
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

    Index indexOf(T* element){
        Index index = 0;
        mem_segment_s<T>* segment = &this->elements;
        while(segment){
            for(index = 0; index < segment->count(); index++){
                if(segment[index].element == element) return index;
            }

            if(segment[index + 1].address){
                segment = static_cast<mem_segment_s<T>*>(segment[index + 1].address);
                continue;
            }
        }

        return UNSIGNED_LONG_MAX;
    }

    T* elementAt(const Index& index){
        mem_segment_s<T>* segment = &this->elements;
        while (segment) {
            if( index > segment[segment->index] * segment->size && index < segment[segment->index] * segment->size + segment->size){
                return segment[index - segment[segment->index] * segment->size].element;
            }

            if (segment[index + 1].address) {
                segment = static_cast<mem_segment_s<T>*>(segment[index + 1].address);
                continue;
            }
        }

        return 0;
    }

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
