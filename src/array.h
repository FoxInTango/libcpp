#ifndef _ARRAY_H_foxintango
#define _ARRAY_H_foxintango

#include "define.h"
namespaceBegin(foxintango)

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
        }
    };
protected:
    T* entities;
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
public:
    Array(){
        this->entities = new T[0];
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

    T& at(const unsigned int& index){}
    T* addressOf(const unsigned int& index){}
public:
    T& operator[](const unsigned int& index){}
};

namespaceEnd

#endif // !_ARRAY_H_foxintango