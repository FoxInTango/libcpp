#include "object.h"
#include "string.h"
using namespace foxintango;

fox::fox(){
    this->descriptions       = 0;
    this->description_number = 0;
}

fox::~fox(){
    if(this->descriptions) delete[] this->descriptions;
}

const char* fox::error(const int& code){
    return code > -1 && code < this->description_number ? this->descriptions[code] : 0;
}