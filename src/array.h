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
class foxintangoAPI Array{
protected:
    //static T T_NULL;
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
    mem_segment<T> T_NULL;
    mem_segment<T>* elements;
    Size a_size;/** array size */
    Size s_size;/** segment size */
public:
    Array() {
        // 处理begin & end
        this->a_size   = 0;
        this->s_size   = ARRAY_DEFAULT_SIZE;
        this->elements = new mem_segment<T>(this->s_size, mem_segment_type_s);

        if(this->elements){
            this->elements->setIndex(0);
        }
    }
    /** 
     * size:segment size 
     */
    Array(const Size& size) {
        // 处理begin & end
        this->a_size = 0;
        this->s_size = size;
        this->elements = new mem_segment<T>(this->s_size, mem_segment_type_s);
        if (this->elements) {
            this->elements->setIndex(0);
        }
    }

   ~Array(){
       if(this->elements){
           mem_segment<T>* segment = this->elements;
           while(segment){
               mem_segment<T>* next = segment->behind();
               delete segment;
               segment = next;
           }
       }
    }
public:
    Size append(const T& t)  { 
        mem_segment<T>* segment = this->elements;
        while (segment = segment->behind()) {
        }

        if(segment->count() < segment->size()) {
            segment->append(t);
            return this->a_size += 1;
        }else {
            mem_segment<T>* s = new mem_segment<T>(this->s_size,mem_segment_type_s);
            if(s){
                s->setIndex(segment->index() + 1);
                s->append(t);
                segment->setBehind(static_cast<mem_segment<T>*>(s));
                return this->a_size += 1;
            }
        }
        
        return 0;
    }

    Size insert(const T& t,const Index& index)  { 
        if (index < this->a_size) {
            mem_segment<T>* segment = this->elements;
            Size  e_count = 0;
            Size  s_size  = 0;
            Index s_index = 1;
            while(segment) {
                if(index - e_count < segment->size()){
                    if(segment->e_count < segment->s_size){
                        segment->insert(t,index - e_count);
                    } else {
                        mem_segment<T>* s = new mem_segment<T>(this->s_size, mem_segment_type_s);
                        if (s) {
                            s->append(t);
                            segment->setBehind(s);// at(segment->s_size + 1).address = static_cast<Address>(s);
                            s->setIndex(segment->index() + 1);// s->at(s->s_size).index = segment->at(segment->s_size + 1).index + 1;
                        }
                    }
                }

                segment = segment->behind();
            }
        } else return this->append(t);
        return this->a_size += 1; 
    }
    Size remove(const Index& index)  { return 0; }
    Size remove(const Iterator& index) { return 0; }
    Size replace(const Index& index) { return 0; }
    Size replace(const Iterator& index) { return 0; }

    Index indexOf(T* element){
        Index index = 0;
        mem_segment<T>* segment = this->elements;
        while(segment){
            for(index = 0; index < segment->count(); index++){
                if(segment->at(index) == element) return index;
            }

            segment = segment->behind();
        }

        return UNSIGNED_LONG_MAX;
    }

    T* elementAt(const Index& index){
        Size e_count = 0;
        Size s_size = 0;
        mem_segment<T>* segment = this->elements;
        s_size = segment->s_size;
        while (segment) {
            if (e_count < index && index < s_size) return &segment->at(index - e_count);

            e_count += segment->e_count;
            s_size += segment->s_size;
            if (segment->at(index + 1).address) {
                segment = static_cast<mem_segment<T>*>(segment->behind());
                continue;
            } else break;
        }
        return 0;
    }

    mem_segment<T>* segmentAt(const Index& index){
        Size e_count = 0;
        Size s_size  = 0;
        mem_segment<T>* segment = this->elements;
        s_size = segment->size;
        while(segment){
            if(e_count < index && index < s_size) return segment;

            e_count += segment->e_count;
            s_size += segment->s_size;
            segment = segment->behind();
        }

        return segment == this->elements && index < this->elements.s_size ? this->elements : 0;
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
        if(index < this->a_size){
            mem_segment<T>* segment = this->elements;
            Index s_index = 1;
            while (segment) {
                if(index > s_index) return segment->at(index - s_index).element;

                s_index += segment->e_count;

                segment = segment->behind();
            }
        }

        return this->elements->at(0).element;
    }

    Size size() { return this->a_size;}
    Size size() const { return this->a_size; }

    Iterator& begin(){ return this->iBegin; }
    Iterator& end()  { return this->iEnd;   }
public:
    T& operator[](const Index& index){ return elements[index]; }
};

namespaceEnd

#endif // !_ARRAY_H_foxintango
