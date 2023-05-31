#ifndef _HASH_H_foxintango
#define _HASH_H_foxintango
#include "define.h"
namespaceBegin(foxintango)
EXTERN_C_BEGIN

Index  hash_in_range(const char* seed, const Index& begin, const Index& end) {
    return begin;
}

Index  hash_in_range(const long unsigned int& seed, const Index& begin, const Index& end) {
    return begin;
}
EXTERN_C_END

/**
template<typename T>
Index  hash_in_range(const T& seed,const Index& begin,const Index& end){
    return begin;
}
*/

namespaceEnd

#endif