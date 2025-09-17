#ifndef _LIBCPP_BUFFER_H_
#define _LIBCPP_BUFFER_H_
#include "define.h"
#include <cstddef>
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class foxintangoAPI Buffer{
public:
    enum Status{
    UNINITED,
    OK,
    FAKE_DATA,
    MEM_ALLOC_FAILED
    };
protected:
    char*  data;
    size_t size;
    Status status;
public:
    Buffer();
    Buffer(size_t size);
    Buffer(const Buffer& buffer);
    Buffer(char* data,size_t size = 0);
    virtual ~Buffer();
public:
    size_t getSize();
    char*  getDataPointer();
    Status setDataPointer(char* data,size_t size = 0);
    Status getStatus();
public:
    Status resize(size_t size);
    Buffer* clone();
    Status append(const char* const data,size_t size = 0);
};
namespaceEnd
EXTERN_C_END
#endif
