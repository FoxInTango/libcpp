#ifndef _MAP_H_foxintango
#define _MAP_H_foxintango
#include "hash.h"
#include "struct.h"
#include "define.h"

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
class Map{
public:
static Value V_NULL;
static KVPair<Key,Value> PNULL;
protected:
    MapType type;
    map_internal<Key,Value>* internal_map;
public:
    class Iterator {
    public:
        Map* owner;
        Key key;
        Value value;
    public:
        Iterator() {
        }
        Iterator(const Index& index) {
        }
        Iterator(Map* owner, const Index& index = 0) {
            this->owner = owner;
        }
        ~Iterator() {

        }
    public:
        void clean() {}
    public:
        Iterator& operator = (const Index& index) { return *this; }

        Iterator& operator +  (const unsigned int& offset) { return *this; }
        Iterator& operator -  (const unsigned int& offset) { return *this; }
        Iterator& operator += (const unsigned int& offset) { return *this; }
        Iterator& operator -= (const unsigned int& offset) { return *this; }
        Iterator& operator ++ () { return *this; }
        Iterator& operator -- () { return *this; }
        Iterator& operator ++ (int) { return *this; }
        Iterator& operator -- (int) { return *this; }

        bool operator == (const Index& index) { return false; }
        bool operator == (const Iterator& iterator) { return false; }
        bool operator != (const Index& index) { return false; }
        bool operator != (const Iterator& iterator) { return false; }

        KVPair<Key,Value>& operator *() { return this->pairs[0]; }
        KVPair<Key,Value>& operator *(const Iterator& iter) { return this->pairs[0]; }
    };
public:
    Iterator begin() { return Iterator(); }
    Iterator end() { return Iterator(); }
    Iterator iteratorAt(const Key& index) { return Iterator(1); }
    Iterator iteratorAt(const Index& index) { return Iterator(1); }
public:
    Map(){
        this->internal_map = new map_hash<Key,Value>();
        this->size = 0;
        this->type = MAP_TYPE_DEFAULT;
    }
    Map(const MapType& type){
        switch(this->type){
        case MAP_TYPE_HASH:{
            this->internal_map = new map_hash<Key,Value>();
            this->size = 0;
            this->type = MAP_TYPE_HASH;
        }break;
        case MAP_TYPE_AVL:{this->internal_map = 0;}break;
        case MAP_TYPE_RB:{this->internal_map = 0;}break;
        default:{
            this->internal_map = new map_hash<Key, Value>();
            this->size = 0;
            this->type = MAP_TYPE_HASH;
        }break;
        }
    }
    Map(const Map& map){
        this->clean();
        this->internal = map.internal->clone();
    }
    ~Map() {
        switch (this->type) {
        case MAP_TYPE_HASH: {
            if(this->internal_map) delete (map_hash<Key, Value>*)this->internal_map;
        }break;
        case MAP_TYPE_AVL: {this->map = 0; }break;
        case MAP_TYPE_RB: {this->map = 0; }break;
        default: {}break;
        }
    }
public:
    virtual Error insert(const Key& key, const Value& value) { return this->internal_map ? this->internal_map->insert(key,value) : 1; }
    virtual Error insert(const KVPair<Key, Value>& pair) { return this->internal_map ? this->internal_map->insert(pair) : 1; }
    virtual Error remove(const Key& key) { return this->internal_map ? this->internal_map->remove(key) : 1; }
    virtual Error remove(const KVPair<Key, Value>& pair) { return this->internal_map ? this->internal_map->remove(pair) : 1; }

    Error swap(const Key& l, const Key& r) { return this->internal_map ? this->internal_map->swap(l,r) : 1; }
    Size count(const Key& key) { return this->internal_map ? this->internal_map->count(key) : 1; }
    Value& at(const Key& key) { return this->internal_map ? this->internal_map->at(key) : this->V_NULL;}

    Size size() { return this->internal_map ? this->internal_map->size() : 1; }
    Size size() const { return this->internal_map ? this->internal_map->size() : 1; }
    Error clean() { return this->internal_map ? this->internal_map->clean() : 1 ;}
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
