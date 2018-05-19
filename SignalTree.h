/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SignalTree.h
 * Author: setler
 *
 * Created on May 19, 2018, 7:31 PM
 */

#ifndef SIGNALTREE_H
#define SIGNALTREE_H

#include <cstddef>
#include <iostream>

#include "Node.h"

class SignalTree {
public:
    SignalTree();
    SignalTree(const SignalTree& orig);
    virtual ~SignalTree();
    
    Node *root = NULL;
    
    void add(int value, Node **nodes, int parent = NULL);
    void dispay(Node **nodes);
    
    Node * find(int value, Node **nodes);
    
private:

};

#endif /* SIGNALTREE_H */

