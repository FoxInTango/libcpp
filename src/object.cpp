#include "object.h"
#include "string.h"
using namespace foxintango;

Object::Object(){
    this->descriptions       = 0;
    this->description_number = 0;
}

Object::~Object(){
    if(this->descriptions) delete[] this->descriptions;
}

const char* Object::error(const int& code){
    return code > -1 && code < this->description_number ? this->descriptions[code] : 0;
}