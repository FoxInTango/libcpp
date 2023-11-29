#include "tst.h"

#include "libcpp.h"
using namespace foxintango;
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void tree_node_callback(int& t){
    printf("tree_node_callback %d\n",t);
}

class Members{
public:
    Member<int> number;
public:
    void number_onset(const int& n){}
public:
    Members(){
        number.onset = number_onset;
    }
};
void member_tst(){

}
void libcpp_tst(){
    tree_node<int> n1, n2;

    n1 = 2;
    n2 = 3;

    rb_tree_node<int> r1, r2;
    r1 = 3;
    r2 = 4;

    if (n1 == n2) {
        printf("n1 == n2.\n");
    }
    else { printf("n1 != n2.\n"); }

    if (r1 == r2) {
        printf("r1 == r2.\n");
    }
    else { printf("r1 != r2.\n"); }

    r1.insert(20);

    if (r1.m_left) {
        printf("r1 left subnode value %d\n", r1.m_left->t);
    }

    if (r1.m_right) {
        printf("r1 right subnode value %d\n", r1.m_right->t);
    }

    for(int i = 0;i < 1000;i ++){
        r1.insert(i);
    }

    r1.foreach(tree_node_callback);

    rb_tree_node<int>* n = r1.clone();
    rb_tree_node<int>* s = n->lookup(200);

    if(s){
        printf("r1.lookup(200); %d\n", s->t);
    }
    n->foreach(tree_node_callback);
}