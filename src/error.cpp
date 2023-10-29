#include "error.h"
#include "string.h"
using namespace foxintango;

Error::Error(){
    code = 0;
    description = 0;
}

Error::Error(const int& code, const char* desc){
    this->code = code;
    this->description = 0;
    if(!desc) return ;

    Size l = string_length<char>(desc);
    this->description = new char[l + 1];
    if(this->description){
        string_copy<char>(this->description, desc,l);
        this->description[l] = 0;
    }
}

Error::Error(const Error& error){
    this->code = error.code;
    this->description = 0;
    if(error.description){
        Size l = string_length<char>(description);
        this->description = new char[l + 1];
        if (this->description) {
            string_copy<char>(this->description, error.description, l);
            this->description[l] = 0;
        }
    }
}

Error::~Error(){
    if(this->description) delete this->description;
}


Error& Error::operator  = (const Error& error){
    this->code = error.code;
    this->description = 0;
    if (error.description) {
        Size l = string_length<char>(description);
        this->description = new char[l + 1];
        if (this->description) {
            string_copy<char>(this->description, error.description, l);
            this->description[l] = 0;
        }
    }
    return *this;
}

Error::operator int(){
    return this->code;
}