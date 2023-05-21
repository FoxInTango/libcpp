#ifndef _ARRAY_H_foxintango
#define _ARRAY_H_foxintango

#include "define.h"
namespaceBegin(foxintango)

/** TODO
 *  Fill with model from libcpp_startup(Model&) 
 */
static unsigned int ARRAY_DEFAULT_SIZE = 32;
template <class T>
class Array{
private:
    class ArrayEntity{
    protected:
        char* address;// 避免碎片化
    public:
        ArrayEntity(const T& t){
            set(t);
        }
       ~ArrayEntity(){}
    public:
        int set(const T& t){
            unsigned int t_size = sizeof(t);
            return 0;
        }
    };
public:
    class Iterator{
    public:
        Iterator& operator +  (const unsigned int& offset) {}
        Iterator& operator -  (const unsigned int& offset) {}
        Iterator& operator += (const unsigned int& offset) {}
        Iterator& operator -= (const unsigned int& offset) {}
        Iterator& operator ++ (){}
        Iterator& operator -- (){}
        T& operator *() { return T(); }
        T& operator *(const Iterator& iter){ return T();}
    };
protected:
    T* entities;
    unsigned int array_size;
    unsigned int entity_count;
public:
    Array() {
        this->entities = new T[ARRAY_DEFAULT_SIZE];
    }
    Array(const unsigned int& size){
        this->entities = new Array::ArrayEntity [size];
    }
   ~Array(){
       if(this->entities) delete this->entities;
    }
public:
    unsigned int append(const T& t)  { return 0; }
    unsigned int insert()  { return 0; }
    unsigned int remove()  { return 0; }
    unsigned int replace() { return 0; }

    int swap(const unsigned int& l,const unsigned int& r) { return 0; }

    unsigned int size() { return array_size; }
    unsigned int count() { return entity_count; }
    T& at(const unsigned int& index){}
    T* addressOf(const unsigned int& index){ return 0; }
public:
    T& operator[](const unsigned int& index){ return T();}
};

namespaceEnd

#endif // !_ARRAY_H_foxintango