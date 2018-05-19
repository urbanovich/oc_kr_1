/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadTree.h
 * Author: setler
 *
 * Created on May 19, 2018, 6:37 PM
 */

#ifndef THREADTREE_H
#define THREADTREE_H

#include "Node.h"
#include <iostream>
#include <cstddef>
#include <pthread.h>
#include <thread>

class ThreadTree {
public:
    ThreadTree();
    ThreadTree(const ThreadTree& orig);
    virtual ~ThreadTree();
    
    static void createThreadByTree(Node **nodes);
    static void createThreadTree(void *nodes);
private:

};

#endif /* THREADTREE_H */

