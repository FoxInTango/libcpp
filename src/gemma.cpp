#include "gemma.h"
#include "string.h"
using namespace foxintango;

Gemma::Gemma(){
    this->descriptions       = 0;
    this->description_number = 0;
}

Gemma::~Gemma(){
    if(this->descriptions) delete[] this->descriptions;
}

const char* Gemma::error(const int& code){
    return code > -1 && code < this->description_number ? this->descriptions[code] : 0;
}