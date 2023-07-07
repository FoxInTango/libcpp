#include "error.h"
#include "string.h"
using namespace foxintango;

Error::Error(){
}

Error::Error(const int& code, const char* description){
    this->code = code;

    if(!description) return ;

    Size l = string_length<char>(description);
    this->description = new char[l + 1];
    if(this->description){
        string_copy<char>(this->description,description,l);
        this->description[l] = 0;
    }
}

Error::Error(const Error& error){
    this->code = error.code;
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