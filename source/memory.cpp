#include "../include/memory.h"
using namespace foxintango;
#include <stdlib.h>

void* memnew(const unsigned int& size) {
    return malloc(size);
}

void  memdel(void* p) {
    free(p);
}
