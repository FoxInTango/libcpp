#ifndef _MAP_H_foxintango
#define _MAP_H_foxintango
#include "struct.h"
#include "define.h"

namespaceBegin(foxintango)
template <typename Key, typename Value>
class map_hash{
public:
    map_hash(){}
    ~map_hash(){}
};
class map_avl{

};

template <typename Key, typename Value>
class KVPair{
public:
    Key   key;
    Value value;
};
template <typename Key,typename Value>
class Map{
public:
    static Value VNULL;// empty value.
protected:
    void* map;
public:
    class Iterator {
    public:
        Map* owner;
        Key key;
        Value value;
        //KVPair<Key,Value>* element;
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

        KVPair<Key,Value>& operator *() { return KVPair<Key, Value>(); }
        KVPair<Key,Value>& operator *(const Iterator& iter) { return KVPair<Key, Value>(); }
    };
public:
    Map(){
        this->map = new map_hash<Key,Value>();
    }
    ~Map() {
        delete (map_hash<Key, Value>*)this->map;
    }
public:
    Size insert(Key key,Value value){ return 0 ;}
    Size remove(const Index& index) { return 0; }
    Size remove(const Iterator& iter) { return 0; }

    Error swap(const unsigned int& l, const unsigned int& r) { return 0; }

    Size count(const Key& key) { return 0; }
    Value& at(const Key& key) { return VNULL;}
    Value& at(const Index& index) { return VNULL; }

    Iterator iteratorAt(const Key& index) { return Iterator(1); }
    Iterator iteratorAt(const Index& index) { return Iterator(1); }
    Value* addressOf(const Index& index) { return 0; }

    Size size() { return Size(); }
    Size size() const { return Size(); }

    Iterator begin() { return Iterator(); }
    Iterator end() { return Iterator(); }
public:
    Value& operator[](const Index& index) { return Value(); }
    Value& operator[](const Key& key) { return Value(); }
};
namespaceEnd
#endif