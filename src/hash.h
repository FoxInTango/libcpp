#ifndef _HASH_H_foxintango
#define _HASH_H_foxintango
#include "map_inernal.h"
#include "define.h"
namespaceBegin(foxintango)
EXTERN_C_BEGIN

inline Index  string_hash(const char* seed, const Index& begin, const Index& end) {
    return begin;
}

inline Index  number_hash(const long unsigned int& seed, const Index& begin, const Index& end) {
    return begin;
}
EXTERN_C_END

/**
template<typename T>
Index  hash_in_range(const T& seed,const Index& begin,const Index& end){
    return begin;
}
*/

typedef enum _hash_type{
}hash_type;

typedef void (*hash_fn)(void* address,const long unsigned int& size);
typedef struct _hash_s{
    void* address;
    Size size;
    union hash{
        hash_fn fn;
        hash_type type;
    };
}hash_s;

template <typename Key, typename Value>
class map_hash :public map_internal<Key,Value>{
public:
    map_hash() {}
    ~map_hash() { this->clean();}
public:
    virtual Error insert(const Key& key, const Value& value) { return 0; }
    virtual Error insert(const KVPair<Key, Value>& pair) { return 0; }
    virtual Error remove(const Key& key) { return 0; }
    virtual Error remove(const KVPair<Key, Value>& pair) { return 0; }

    virtual Value& at(const Key& key) { return this->V_NULL; }
    virtual Error swap(const Key& l, const Key& r) { return 1; }
    virtual Size count(const Key& key) { return 0; }

    virtual Size size() { return 0; }
    virtual Size size() const { return 0; }
public:
    virtual map_internal* clone() { return 0; }
    virtual Error clean() {}
};

namespaceEnd

#endif