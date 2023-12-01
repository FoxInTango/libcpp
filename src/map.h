#ifndef _MAP_H_foxintango
#define _MAP_H_foxintango

#include "tree.h"
#include "container.h"
#include "hash.h"
#include "struct.h"
#include "object.h"
#include "define.h"

/** TODO
 *  交 并 补 差
 */

namespaceBegin(foxintango)

typedef int MapType;

const MapType MAP_TYPE_HASH = 1;
const MapType MAP_TYPE_AVL = 2;
const MapType MAP_TYPE_RB = 3;

#define MAP_TYPE_DEFAULT MAP_TYPE_HASH

/**
 Map -- Hash ----- hash_fn | hash_internal_index
              |---
     -- AVL  ----- 
     -- RB   -----
 */
template <typename Key,typename Value>
class Map :public Object{
public:
Value V_NULL;
KVPair<Key,Value> P_NULL;
protected:
    MapType type;
    map_internal<Key,Value>* internal_map;
public:
    Map(){
        this->internal_map = new map_hash<Key,Value>();
        this->type = MAP_TYPE_DEFAULT;
    }
    Map(const MapType& type){
        switch(this->type){
        case MAP_TYPE_HASH:{
            this->internal_map = new map_hash<Key,Value>();
            this->type = MAP_TYPE_HASH;
        }break;
        case MAP_TYPE_AVL:{this->internal_map = 0;}break;
        case MAP_TYPE_RB:{this->internal_map = 0;}break;
        default:{
            this->internal_map = new map_hash<Key, Value>();
            this->type = MAP_TYPE_HASH;
        }break;
        }
    }
    Map(const Map& map){
        this->clean();
        this->internal_map = map.internal_map->clone();
    }
    ~Map() {
        switch (this->type) {
        case MAP_TYPE_HASH: {
            if(this->internal_map) delete (map_hash<Key, Value>*)this->internal_map;
        }break;
        case MAP_TYPE_AVL: {this->internal_map = 0; }break;
        case MAP_TYPE_RB: {this->internal_map = 0; }break;
        default: {}break;
        }
    }
public:
    virtual Error insert(const Key& key, const Value& value) { return this->internal_map ? this->internal_map->insert(key,value) : Error(1); }
    virtual Error insert(const KVPair<Key, Value>& pair) { return this->internal_map ? this->internal_map->insert(pair) : Error(1); }
    virtual Error remove(const Key& key) { return this->internal_map ? this->internal_map->remove(key) : Error(1); }
    //virtual Error remove(const Value& value) { return this->internal_map ? this->internal_map->remove(value) : Error(1); }
    virtual Error remove(const KVPair<Key, Value>& pair) { return this->internal_map ? this->internal_map->remove(pair) : Error(1); }


    Error swap(const Key& l, const Key& r) { return this->internal_map ? this->internal_map->swap(l,r) : Error(1); }
    Size count(const Key& key) { return this->internal_map ? this->internal_map->count(key) : 0; }
    Value& at(const Key& key) { return this->internal_map ? this->internal_map->at(key) : this->V_NULL;}

    Size size() { return this->internal_map ? this->internal_map->size() : 0; }
    Size size() const { return this->internal_map ? this->internal_map->size() : 0; }
    Error clean() { return this->internal_map ? this->internal_map->clean() : Error(1);}
public:
    Map& operator = (const Map& map){
        this->clean();
        this->internal_map = map.internal_map->clone();
        return *this;
    }

    Value& operator[](const Key& key) { return this->at(key); }
};
namespaceEnd
#endif
