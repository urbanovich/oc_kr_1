/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadTree.cpp
 * Author: setler
 * 
 * Created on May 19, 2018, 6:37 PM
 */

#include "ThreadTree.h"
#include "SignalHandler.h"

ThreadTree::ThreadTree() {
}

ThreadTree::ThreadTree(const ThreadTree& orig) {
}

ThreadTree::~ThreadTree() {
}

void ThreadTree::createThreadByTree(Node** nodes) {
    
    if ((*nodes) == NULL) {
        return;
    }
    
    std::thread th;
    
    th = std::thread(ThreadTree::createThreadTree, nodes);
    th.join();
}

void ThreadTree::createThreadTree(Node** nodes) {
    
    if (*nodes == NULL) {
        return;
    }
    
    signal(SIGUSR1, SignalHandler::handler);
    signal(SIGUSR2, SignalHandler::handler);
    
    std::cout << "thread: " << (*nodes)->id << std::endl;
    
    (*nodes)->thread_id = std::this_thread::get_id();
    std::cout << "this_thread: " << (*nodes)->thread_id << std::endl;

    std::thread th;
        
    if ((*nodes)->right != NULL) {
        th = std::thread(ThreadTree::createThreadTree, &(*nodes)->right);
        th.join();
    }
    
    if ((*nodes)->left != NULL) {
        th = std::thread(ThreadTree::createThreadTree, &(*nodes)->left);
        th.join();
    }
    
}