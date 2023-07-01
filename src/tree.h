#ifndef _LIB_CPP_TREE_H_foxintango
#define _LIB_CPP_TREE_H_foxintango
#include "array.h"
#include "struct.h"
#include "memory.h"
#include "define.h"

namespaceBegin(foxintango)

typedef enum _ROTATE_DIRECTION{
    RD_LEFT,
    RD_RIGHT
}ROTATE_DIRECTION;

template <typename T>
class tree_node{
public:
    T* t;// 集约化处理
    tree_node* m_super;
    mem_segment<tree_node*>* m_subnodes;
public:
    tree_node(){
        this->t = 0;
        this->m_super = 0;
        this->m_subnodes = 0;
    }

    virtual ~tree_node(){ if(this->m_subnodes) delete this->m_subnodes; }
public:
    tree_node* super() { return this->m_super; }
    tree_node* subnodeAt(const Index& index){
        return this->m_subnodes && index < this->m_subnodes->count() ? return this->m_subnodes[index] : 0;
    }

    tree_node* clone(){ return 0;}

    Size subcount() { return this->m_subnodes ? this->m_subnodes->count() : 0; }

    Error rotate(const ROTATE_DIRECTION& direction){ return 0; }
public:
    virtual tree_node* at(T& t){ return 0; }
};



template <typename T>
class b_tree_node :public tree_node{
public:
    b_tree_node(){}
    ~b_tree_node(){}
public:
    tree_node* super(){}
    tree_node* left(){}
    tree_node* right(){}
};
/** 双子路径树
 *
 */

template <typename T>
class dual_path_tree_node :public b_tree_node {
public:
    Index m_path_code;
    dual_path_tree_node* m_sibling;
public:
    dual_path_tree_node() {
        this->m_sibling = 0;
    }

    ~dual_path_tree_node(){
    }
};

template <typename T>
class avl_tree_node :public b_tree_node{

};
template <typename T>
class rb_tree_node :public b_tree_node {};

/** B-Tree
 */
template <typename T>
class tree_node_s {
    /** super
     */
    struct tree_node_s* s;
    /** left
     */
    struct tree_node_s* l;
    /** right
     */
    struct tree_node_s* r;
    T entity;
};

/** bst avl rbt
 *    了解替罪羊树
 */

namespaceEnd
#endif