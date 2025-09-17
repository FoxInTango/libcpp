#ifndef _LIBCPP_EVENT_H_
#define _LIBCPP_EVENT_H_
#include "buffer.h"
#include "define.h"
namespaceBegin(foxintango)
EXTERN_C_BEGIN
class foxintangoAPI Event{
public:
    Buffer buffer;
public:
    Event();
    virtual ~Event();
 
};

class foxintangoAPI EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();
public:
    virtual int handleEvent(Event* e);
};

EXTERN_C_END
namespaceEnd
#endif
