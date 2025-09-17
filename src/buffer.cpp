#include "buffer.h"
using namespace foxintango;
#include <string.h>

Buffer::Buffer(){
    data   = 0;
    size   = 0;
    status = UNINITED;
}

Buffer::Buffer(size_t _size){
    data = new char[_size];

    size   = _size;
    status = data ? OK : MEM_ALLOC_FAILED;
}

Buffer::Buffer(const Buffer& buffer){
     if(buffer.data && buffer.size) {
         data = new char[buffer.size];
	 if(data) {
	     memcpy(data,buffer.data,buffer.size);
	     size   = buffer.size;
	     status = OK;
         } else {
	     size   = 0;
	     status = MEM_ALLOC_FAILED;
	 }
     }   
}

Buffer::Buffer(char* _data,size_t _size){
    size_t t_size = _size ? _size : strlen(_data);
    if(t_size) {
        data = new char[t_size];
	if(data){
            memcpy(_data,data,_size);
	    size   = _size;
	    status = OK;
        }else {
	    status = MEM_ALLOC_FAILED;
	}
    }
}

Buffer::~Buffer(){
    if(data) delete [] data;
}

size_t Buffer::getSize(){
    return size;
}

char* Buffer::getDataPointer(){
    return data;
}

Buffer::Status Buffer::setDataPointer(char* _data,size_t _size){
    if(_data){
        size_t t_size = _size ? _size : strlen(_data);
	if(!t_size) return FAKE_DATA;
	if(data) delete[] data;
        data   = _data;
	size   = _size;
	status = OK;
	return status;
    }

    return FAKE_DATA;
}

Buffer::Status Buffer::getStatus(){
    return status;
}

Buffer::Status Buffer::resize(size_t _size){
    char* t = new char[_size];
    if(!t) return MEM_ALLOC_FAILED;
    
    if(data) {
        memcpy(t,data,size);
        delete[] data;
    }

    data = t;
    size = _size;
    return OK;
}

Buffer* Buffer::clone(){
    return new Buffer(*this);
}

Buffer::Status Buffer::append(const char* _data,size_t _size){
    size_t t_size = size + _size;
    char*  t_data = new char[t_size];
    if(t_data) {
        if(data) { 
            memcpy(t_data,data,size);
            delete[] data; 
        }
	memcpy(&t_data[size],_data,_size);
	data = t_data;
	size = t_size;
	status = OK;
    } else {
        return MEM_ALLOC_FAILED;
    }

    return status;
}
