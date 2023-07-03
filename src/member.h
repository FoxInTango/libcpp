#ifndef _LIBCPP_MEMBER_H_
#define _LIBCPP_MEMBER_H_
#include "define.h"
namespaceBegin(foxintango)
template <typename T,typename H>
class Member{ 
public:
    T t;
    H h;
public:
    Member(H h){}
    Member(const T& t) { this->t = t;}
public:
    Member& operator =(const T& t){ this->t = t; return *this; }
public:
    operator T() { return this->t; }
};
namespaceEnd
#endif