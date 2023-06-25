#include "error.h"
using namespace foxintango;

Error::Error(){
}

Error::Error(const int& code, const char* description){

}

Error::Error(const Error& error){

}

Error::~Error(){

    if(this->description) delete this->description;
}


Error& Error::operator  = (const Error& error){
    return *this;
}
Error& Error::operator += (const char* description){
    return *this;
}

Error::operator int(){
    return this->code;
}