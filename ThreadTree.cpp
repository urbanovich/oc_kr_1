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
        
    pthread_create(&(*nodes)->th, NULL, ThreadTree::createThreadTree, (void*)nodes);
    pthread_join((*nodes)->th, NULL);
//    pthread_kill((*nodes)->th, SIGUSR1);
//    pthread_exit(NULL);
}

void *ThreadTree::createThreadTree(void *node) {
    
    Node **nodes = (Node**)node;
        
    if ((*nodes) == NULL) {
        return (void*)NULL;
    }
        
    std::cout << "pthread: " << (*nodes)->id << std::endl;
     
    pthread_t th;
        
    if ((*nodes)->right != NULL) {
        pthread_create(&(*nodes)->th, NULL, ThreadTree::createThreadTree, (void *)&(*nodes)->right);
        pthread_join((*nodes)->th, NULL);
//        pthread_kill(th, SIGUSR1);
    }
    
    if ((*nodes)->left != NULL) {
        pthread_create(&(*nodes)->th, NULL, ThreadTree::createThreadTree, (void *)&(*nodes)->left);
        pthread_join((*nodes)->th, NULL);
//        pthread_kill(th, SIGUSR1);
    }
    
//    while(true) {
//        
//    }
//    pthread_exit(NULL);
}

void ThreadTree::sendSignal(Node** nodes) {
            
    if ((*nodes) == NULL) {
        return;
    }
    
    std::cout << "id: " << (*nodes)->id << std::endl;
    std::cout << "pthread: " << (*nodes)->th << std::endl;
    
    if ((*nodes)->type > 0) {
//        pthread_kill((*nodes)->th, (*nodes)->type);
        pthread_kill((*nodes)->th, SIGUSR1);
    }
         
    if ((*nodes)->right != NULL) {
        ThreadTree::sendSignal(&(*nodes)->right);
    }
    
    if ((*nodes)->left != NULL) {
        ThreadTree::sendSignal(&(*nodes)->left);
    }
    
}