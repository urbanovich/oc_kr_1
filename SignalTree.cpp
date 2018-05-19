/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SignalTree.cpp
 * Author: setler
 * 
 * Created on May 19, 2018, 7:31 PM
 */

#include "SignalTree.h"

SignalTree::SignalTree() {
}

SignalTree::SignalTree(const SignalTree& orig) {
}

SignalTree::~SignalTree() {
}

void SignalTree::add(int value, Node **nodes, int parent) {
    
    if (parent > 0 && (*nodes) != NULL) {
        Node *found = this->find(parent, &this->root);
        if (found != NULL) {
            (*nodes) = found;
        }
    }
    
    if ((*nodes) == NULL) {
        (*nodes) = new Node();
        (*nodes)->id = value;
        (*nodes)->left = (*nodes)->right = NULL;
        return;
    }
    
    if (this->root == NULL) {
        this->root = (*nodes);
    }

    if ((*nodes)->id < value && (*nodes)->left == NULL) {
        this->add(value, &(*nodes)->left, parent);
    } else {
        this->add(value, &(*nodes)->right, parent);
    }
}

Node * SignalTree::find(int value, Node **nodes) {
    Node *found = NULL;

    if ((*nodes) == NULL) {
        return NULL;
    }
    
    if ((*nodes)->id != value) {
        found = this->find(value, &(*nodes)->left);
        if (found != NULL) {
            return found;
        }
        found = this->find(value, &(*nodes)->right);
        if (found != NULL) {
            return found;
        }
        
        return NULL;
    } else {
        return (*nodes);
    }
}

void SignalTree::dispay(Node** nodes) {
    std::cout << (*nodes)->id << std::endl;
    
    if ((*nodes)->right != NULL) {
        std::cout << "right: ";
        this->dispay(&(*nodes)->right);
    }
    
    if ((*nodes)->left != NULL) {
        std::cout << "left: ";
        this->dispay(&(*nodes)->left);
    }
}
