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
inline Address memcln(const Address& source,const Size& length,const Address& target = 0){
    return 0;
}

inline void memclr(const Address target, const Size& length,const char& value = 0) {
    if(target) {
        for(Index i = 0;i < length;i ++) {
           ((char*)target)[i] = value;
        }
    }
}

/** implementation of new & delete
 */
#ifdef PLATFORM_BARE 
/* NOTE : ARCH 
 **/
#endif

#ifdef PLATFORM_LINUX
#ifdef PLATFORM_LINUX_API

#endif

#ifdef PLATFORM_LINUX_KPI

#endif
#endif

#ifdef PLATFORM_DARWIN
#ifdef PLATFORM_DARWIN_API

#endif

#ifdef PLATFORM_DARWIN_KPI

#endif
#endif //PLATFORM_DARWIN

#ifdef PLATFORM_WIN
#ifdef PLATFORM_WIN32_API

#endif

#ifdef PLATFORM_WIN32_KPI

#endif
#endif // PLATFORM_WIN
namespaceEnd
EXTERN_C_END
#endif
