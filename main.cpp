/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: setler
 *
 * Created on May 17, 2018, 3:00 PM
 */

#include <cstdlib>
#include <iostream>

#include "Node.h"
#include "Tree.h"
#include "ThreadTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Node *node = new Node();
    Node *n;
    n = node;
    
    //create tree 1->2 2->(3,4) 4->5 3->6 6->7 7->8
    //and 
    //create signal tree 1->2 SIGUSR1 | 2->(3,4) SIGUSR2 
    // 4->5 SIGUSR1 | 3->6 SIGUSR1 | 6->7 SIGUSR1 | 7->8 SIGUSR2 | 8->1 SIGUSR2
    Tree *tree = new Tree();
    
    tree->add(1, &node, 0, SIGUSR1);
    tree->add(2, &node, 1, SIGUSR2);
    tree->add(3, &node, 2, SIGUSR1);
    tree->add(4, &node, 2, SIGUSR1);
    tree->add(6, &node, 3, SIGUSR1);
    tree->add(5, &node, 4);
    tree->add(7, &node, 6, SIGUSR2);
    tree->add(8, &node, 7, SIGUSR2);
    
    tree->dispay(&n);
    
    ThreadTree *tt = new ThreadTree();
    ThreadTree::createThreadByTree(&n);
    
//    kill(node->thread_id, SIGUSR1);
    
    return 0;
}

