#ifndef _HASH_H_foxintango
#define _HASH_H_foxintango
#include "define.h"
namespaceBegin(foxintango)
EXTERN_C_BEGIN

inline Index  string_hash(const char* seed, const Index& begin, const Index& end) {
    return begin;
}

inline Index  number_hash(const long unsigned int& seed, const Index& begin, const Index& end) {
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