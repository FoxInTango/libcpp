#ifndef _LIBCPP_MEMBER_H_
#define _LIBCPP_MEMBER_H_
#include "define.h"
namespaceBegin(foxintango)

/** TODO 解决指针问题
 */
template <typename T>
class Member{
public:
    T t;
public:
    Member(){}
    Member(const T& t) { this->t = t;  }
    Member(const T* t) { this->t = *t; }
    Member(const Member& m) { this->t = m.t;}
public:
    typedef void (*set_callback)(T& o,const T& n);
    typedef T(*get_callback)(const T& o);
public:
    set_callback onset;
    get_callback onget;
public:
    Member& operator =(const T& t){ 
        if(this->onset) {
            this->onset(this->t,t);
        }else this->t =  t; 
        return *this; 
    }

    Member& operator =(const T* t){ 
        if (this->onset) {
            this->onset(this->t, *t);
        }
        else this->t = *t;
        return *this;
    }

    Member& operator =(const Member& m) { 
        if (this->onset) {
            this->onset(this->t, m.t);
        }
        else this->t = m.t;
        return *this;
    }
public:
    operator T()  { return  this->onget ? this->onget(this->t) : this->t; }
    operator T*() { return &this->t; }
};
namespaceEnd
#endif