/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: setler
 * 
 * Created on May 17, 2018, 3:01 PM
 */

#include "Tree.h"

Tree::Tree() {
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
}

void Tree::add(int value, Node **nodes, int parent, int type) {
    
    if (parent > 0 && (*nodes) != NULL) {
        Node *found = this->find(parent, &this->root);
        if (found != NULL) {
            (*nodes) = found;
        }
    }
    
    if ((*nodes) == NULL) {
        (*nodes) = new Node();
        (*nodes)->id = value;
        (*nodes)->type = type;
        (*nodes)->left = (*nodes)->right = NULL;
        return;
    }
    
    if (this->root == NULL) {
        this->root = (*nodes);
    }

    if ((*nodes)->id < value && (*nodes)->left == NULL) {
        this->add(value, &(*nodes)->left, parent, type);
    } else {
        this->add(value, &(*nodes)->right, parent, type);
    }
}

Node * Tree::find(int value, Node **nodes) {
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

void Tree::dispay(Node** nodes) {
    std::cout << "id: " << (*nodes)->id << std::endl;
    
    if ((*nodes)->right != NULL) {
        std::cout << "right: ";
        this->dispay(&(*nodes)->right);
    }
    
    if ((*nodes)->left != NULL) {
        std::cout << "left: ";
        this->dispay(&(*nodes)->left);
    }
}
