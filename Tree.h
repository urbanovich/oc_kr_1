/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: setler
 *
 * Created on May 17, 2018, 3:01 PM
 */

#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <iostream>

#include "Node.h"

class Tree {
public:
    Tree();
    Tree(const Tree& orig);
    virtual ~Tree();
    
    Node *root = NULL;
    
    void add(int value, Node **nodes, int parent = NULL, int type = 0);
    void dispay(Node **nodes);
    
    Node * find(int value, Node **nodes);
    
private:

};

#endif /* TREE_H */

