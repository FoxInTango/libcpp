#ifndef _MAP_INTERNAL_H_foxintango
#define _MAP_INTERNAL_H_foxintango
#include "memory.h"
#include "define.h"
namespaceBegin(foxintango)
template <typename Key, typename Value>
class KVPair {
public:
    Key   key;
    Value value;
};

/** Error Code : 
 */
template <typename Key, typename Value>
class map_internal{
protected:
    Value V_NULL;
public:
    map_internal(){
        memclr(&this->V_NULL,sizeof(this->V_NULL),255);
    }
    virtual ~map_internal(){
    }
public:
    virtual Error insert(const Key& key,const Value& value){ return 1;}
    virtual Error insert(const KVPair<Key,Value>& pair){ return 1; }
    virtual Error remove(const Key& key){ return 1; }
    virtual Error remove(const KVPair<Key, Value>& pair){ return 1; }

    virtual Value& at(const Key& key) { return this->V_NULL; }
    virtual Error swap(const Key& l, const Key& r) { return 1; }
    virtual Size count(const Key& key) { return 0; }

    virtual Size size() { return 0; }
    virtual Size size() const { return 0; }
public:
    virtual map_internal<Key,Value>* clone(){ return 0; }
    virtual Error clean(){ return 1;}
public:
    Value& null(){ return this->V_NULL; }
};
namespaceEnd
#endif