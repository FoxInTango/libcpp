#ifndef _LIB_CPP_MEMEORY_H_foxintango
#define _LIB_CPP_MEMEORY_H_foxintango
#include "define.h"

EXTERN_C_BEGIN
namespaceBegin(foxintango)
inline void* memnew(const Size& size) {
    return new char[size];
}
inline void  memdel(const void* p) {
    delete[] (char*)p;
}

/*
inline void  memcpy(void* s,void* t,const unsigned int& size) {

}
*/
inline void memclr(const Address target, Size& length,const char& value = 0) {
    if(target) {
        for(Index i = 0;i < length;i ++) {
           ((char*)target)[i] = value;
        }
    }
}

namespaceEnd
EXTERN_C_END
#endif
