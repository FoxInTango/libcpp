#ifndef _LIBCPP_MEMBER_H_
#define _LIBCPP_MEMBER_H_
#include "define.h"
namespaceBegin(foxintango)
template <typename T>
class Member{
public:
    T t;
public:
    Member(){}
    Member(const T& t) { this->t = t;}
public:
    Member& operator =(const T& t){ this->t = t; return *this; }
public:
    operator T() { return this->t; }
};
namespaceEnd
#endif