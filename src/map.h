#ifndef _MAP_H_foxintango
#define _MAP_H_foxintango
#include "struct.h"
#include "define.h"

template <typename T>
class map_hash{
public:
    map_hash(){}
    ~map_hash(){}
};
class map_avl{

};
template <typename T>
class Map{
protected:
    void* map;
public:
    Map(){
        this->map = new map_hash<T>();
    }
    ~Map() {
        delete (map_hash<T>*)this->map;
    }
};
#endif