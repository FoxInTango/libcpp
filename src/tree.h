#ifndef _LIB_CPP_TREE_H_foxintango
#define _LIB_CPP_TREE_H_foxintango
#include "array.h"
#include "struct.h"
#include "error.h"
#include "member.h"
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
    Error error;
public:
    T t;// 集约化处理
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
        return this->m_subnodes && index < this->m_subnodes->count() ? this->m_subnodes[index] : 0;
    }

    tree_node* clone(){ return 0;}

    Size subcount() { return this->m_subnodes ? this->m_subnodes->count() : 0; }

    void set(const T& t){
        this->t = t;
    }
public:
    virtual tree_node* at(T& t){ return 0; }
public:
    virtual Error& insert(const T& t){ return this->error; }
    virtual Error& remove(const T& t){ return this->error; }
    virtual Error& rotate(const ROTATE_DIRECTION& direction) { return this->error; }
public:
    virtual tree_node& operator = (const T& t){
        set(t);
        return *this;
    }

    virtual bool operator == (const tree_node& n){
        return this->t == n.t ? true : false;
    }
};

template <typename T>
class b_tree_node :public tree_node<T>{
public:
    b_tree_node(){}
    ~b_tree_node(){}
public:
    tree_node<T>* super(){ return  this->m_super; }
    tree_node<T>* left() { return  this->m_subnodes && this->m_subnodes->size()     ? this->subnodeAt(0) : 0; }
    tree_node<T>* right(){ return  this->m_subnodes && this->m_subnodes->size() > 1 ? this->subnodeAt(1) : 0; }
};
/** 双子路径树
 *
 */

template <typename T>
class dual_path_tree_node :public b_tree_node<T> {
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
class avl_tree_node :public b_tree_node<T>{

};

/** 红黑树
 *  Errors : 0 操作成功
 *           
 */
//template <typename T> typedef  void (*rb_node_callback)(T& t);

template <typename T>
class rb_tree_node {
public:
    Error error;
public:
    T t;
    Bool color;
    rb_tree_node* m_super;
    rb_tree_node* m_left;
    rb_tree_node* m_right;
    typedef  void (*rb_node_callback)(T& t);
public:
    rb_tree_node(){ 
        this->m_left  = 0;
        this->m_right = 0;
        memclr(this,sizeof(rb_tree_node),0); 
    }
    rb_tree_node(const T& t) { 
        this->m_left = 0;
        this->m_right = 0;
        memclr(this, sizeof(rb_tree_node), 0); 
        this->t = t; 
    }
    ~rb_tree_node(){
        if(m_left) delete this->m_left;
        if(m_right) delete this->m_right;
    }
public:
    rb_tree_node* super() { return this->m_super; }
    rb_tree_node* left()  { return this->m_left;  }
    rb_tree_node* right() { return this->m_right; }

    rb_tree_node* clone(rb_tree_node* super = 0) { 
        rb_tree_node* n = new rb_tree_node();

        if(n) n->t = this->t;
        if(super) {
            n->m_super = super;
            if(super->t > n->t){
                super->m_left = n;
            } else {
                super->m_right = n
            }
        }

        if(this->m_left){
            this->m_left->clone(n);
        }

        if (this->m_right) {
            this->m_right->clone(n);
        }

        return n;
    }

    void foreach(rb_node_callback callback) {
        callback(this->t);
        if(this->m_left){
            this->m_left->foreach(callback);
        }
        if (this->m_right) {
            this->m_right->foreach(callback);
        }
    }

    rb_tree_node* lookup(const T& t){
        if(this->t == t) return this;

        if(this->t > t && this->m_left){
            return this->m_left->lookup(t);
        }

        if(this->t < t && this->m_right){
            return this->m_right->lookup(t);
        }

        return 0;
    }

    void set(const T& t) {
        this->t = t;
    }
public:
    Error& insert(const T& t) { 
        if(t < this->t){
            if(this->m_left){
                this->m_left->insert(t);
            } else {
                this->m_left = new rb_tree_node(t);

                if(this->m_left){
                    this->m_left->m_super = this;
                }
            }
        } else if(t > this->t){
            if (this->m_right) {
                this->m_right->insert(t);
            }
            else {
                this->m_right = new rb_tree_node(t);
                if (this->m_right) {
                    this->m_right->m_super = this;
                }
            }
        } else {
          this->t = t;
        }

        return this->error;
    }
    
    Error& remove(const T& t) { return this->error; }
    Error& rotate(const ROTATE_DIRECTION& direction) { return this->error; }
public:
    rb_tree_node& operator = (const T& t) {
        this->set(t);
        return *this;
    }

    bool operator == (const rb_tree_node& n) {
        return this->t == n.t ? true : false;
    }
    /*
    T&   operator [] (const T& t){
        if(this->t == t){
            return *this;
        }

        if(this->t > t && this->left){
            return this->left->operator[](t);
        }

        if (this->t < t && this->right) {
            return this->right->operator[](t);
        }
    }
    */
};

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