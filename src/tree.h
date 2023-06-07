#ifndef _LIB_CPP_TREE_H_foxintango
#define _LIB_CPP_TREE_H_foxintango
#include "struct.h"
#include "memory.h"
#include "define.h"

namespaceBegin(foxintango)
template <typename T>
class tree_node{
    mem_segment<tree_node*>* subnodes;
};

template <typename T>
class avl_tree{};
template <typename T>
class rb_tree {};
namespaceEnd
#endif