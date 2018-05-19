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
    
    pthread_t th;
    pthread_create(&th, NULL, ThreadTree::createThreadTree, (void*)nodes);
    printf("In main \nthread id = %d\n", th);
    pthread_join(th, NULL);
}

void ThreadTree::createThreadTree(void *nodes) {
    
//    Node *nodes = (Node *) nodes;
    
//    if (*nodes == NULL) {
//        return;
//    }
//    
//    signal(SIGUSR1, SignalHandler::handler);
//    signal(SIGUSR2, SignalHandler::handler);
//    
//    std::cout << "thread: " << (*nodes)->id << std::endl;
//    
//    pthread_t th;
//        
//    if ((*nodes)->right != NULL) {
//        pthread_create(&th, NULL, ThreadTree::createThreadTree, (void *)(*nodes)->right);
//        printf("In main \nthread id = %d\n", th); 
//        pthread_join(th, NULL);
//    }
//    
//    if ((*nodes)->left != NULL) {
//        pthread_create(&th, NULL, ThreadTree::createThreadTree, (void *)(*nodes)->left);
//        printf("In main \nthread id = %d\n", th); 
//        pthread_join(th, NULL);
//    }
    
}