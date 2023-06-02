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
protected:
    static T T_NULL;
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
    Iterator iBegin;
    Iterator iEnd;
    mem_segment_s<T> elements;
    Size aSize;/** array size */
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
    Size append(const T& t)  { 
        mem_segment_s<T>* segment = &this->elements;
        while (segment) {
            if (segment->at(segment->s_size + 1).address) {
                segment = static_cast<mem_segment_s<T>*>(segment->at(segment->s_size + 1).address);
                continue;
            }else break;
        }

        if(segment->e_count < segment->s_size) {
            segment->append(t);
        }else {
            mem_segment_s<T>* s = new mem_segment_s<T>();
            if(s){
                s->append(t);
                segment->at(segment->size + 1).address = static_cast<Address>(s);
            }
        }
        return this->size += 1;
    }
    Size insert(const T& t,const Index& index)  { 
        if (index < this->size) {
            Size e_count = 0;
            Size s_size = 0;
            mem_segment_s<T>* segment = &this->elements;
            Index s_index = 1;
            while (segment) {
                if(index - e_count < segment->size){
                    if(segment->e_count < segment->s_size){
                        segment->insert(t,index - e_count);
                    } else {
                        mem_segment_s<T>* s = new mem_segment_s<T>();
                        if (s) {
                            //s->app(t);
                            segment->at(segment->size + 1).address = static_cast<Address>(s);
                            s->at(s->s_size].index = segment->at(segment->size + 1).index + 1;
                        }
                    }
                }
                if (segment->at(index + 1).address) {
                    segment = static_cast<mem_segment_s<T>*>(segment->at(index + 1).address);
                    continue;
                }
            }
        } else return this->append(t);
        return this->size += 1; 
    }
    Size remove(const Index& index)  { return 0; }
    Size remove(const Iterator& index) { return 0; }
    Size replace(const Index& index) { return 0; }
    Size replace(const Iterator& index) { return 0; }

    Index indexOf(T* element){
        Index index = 0;
        mem_segment_s<T>* segment = &this->elements;
        while(segment){
            for(index = 0; index < segment->count(); index++){
                if(segment->at(index).element == element) return index;
            }

            if(segment->at(index + 1).address){
                segment = static_cast<mem_segment_s<T>*>(segment->at(index + 1).address);
                continue;
            }
            else break;
        }

        return UNSIGNED_LONG_MAX;
    }

    T* elementAt(const Index& index){
        Size e_count = 0;
        Size s_size = 0;
        mem_segment_s<T>* segment = &this->elements;
        s_size = segment->size;
        while (segment) {
            if (e_count < index && index < s_size) return segment->at(index - e_count);

            e_count += segment->e_count;
            s_size += segment->s_size;
            if (segment->at(index + 1).address) {
                segment = static_cast<mem_segment_s<T>*>(segment->at(index + 1).address);
                continue;
            } else break;
        }

        

        return 0;
    }

    mem_segment_s<T>* segmentForIndex(const Index& index){
        Size e_count = 0;
        Size s_size  = 0;
        mem_segment_s<T>* segment = &this->elements;
        s_size = segment->size;
        while(segment){
            if(e_count < index && index < s_size) return segment;

            e_count += segment->e_count;
            s_size += segment->s_size;
            if (segment->at(index + 1).address) {
                segment = static_cast<mem_segment_s<T>*>(segment->at(index + 1).address);
                continue;
            }
            else break;
        }

        return segment == &this->elements && index < this->elements.s_size ? &this->elements : 0;
    }

    Error swap(const Index& l, const Index& r) {
        if(l < this->e_count && r < this->e_count){
            T t = this->at(l);
            this->at(l) = this->at(r);
            this->at(r) = t;

            return 1;
        }

        return 0;
    }
    T& at(const Index& index) {
        if(index < this->size){
            mem_segment_s<T>* segment = &this->elements;
            Index s_index = 1;
            while (segment) {
                if(index > s_index) return segment->at(index - s_index);

                s_index += segment->e_count;

                if (segment->at(index + 1).address) {
                    segment = static_cast<mem_segment_s<T>*>(segment->at(index + 1).address);
                    continue;
                }
            }
        }

        return this->T_NULL;
    }

    Size size() { return this->aSize;}
    Size size() const { return this->aSize; }

    Iterator& begin(){ return this->iBegin; }
    Iterator& end()  { return this->iEnd;   }
public:
    T& operator[](const Index& index){ return elements[index]; }
};

namespaceEnd

#endif // !_ARRAY_H_foxintango
