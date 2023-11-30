#ifndef _LIBCPP_MEMBER_H_
#define _LIBCPP_MEMBER_H_
#include "define.h"
namespaceBegin(foxintango)

/** TODO 解决指针问题
 *  尝试动态成员名，采取继承方式添加成员
 */
template <typename T,const char* name>
class Member{
public:
    T t;
    T name;
public:
    Member(){ this->onset = 0; this->onget = 0;}
    Member(const T& t) { this->onset = 0; this->onget = 0; this->t = t;  }
    Member(const T* t) { this->onset = 0; this->onget = 0; this->t = *t; }
    Member(const Member& m) { this->onset = 0; this->onget = 0; this->t = m.t;}
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