#ifndef _ITERATOR_H_foxintango
#define _ITERATOR_H_foxintango
#include "struct.h"
#include "define.h"
namespaceBegin(foxintango)
template <typename T,class Owner>
class Iterator {
public:
    Owner* owner;
public:
    Iterator(Owner* owner){
        this->owner = owner;
    }
public:
    void clean(){}
public:
    Iterator& operator = (const Index& index){}

    Iterator& operator +  (const unsigned int& offset) {}
    Iterator& operator -  (const unsigned int& offset) {}
    Iterator& operator += (const unsigned int& offset) {}
    Iterator& operator -= (const unsigned int& offset) {}
    Iterator& operator ++ () {}
    Iterator& operator -- () {}

    bool operator == (const Index& index) {}
    bool operator == (const Iterator& iterator) { }
    T& operator *() { return T(); }
    T& operator *(const Iterator& iter) { return T(); }
};
namespaceEnd
#endif