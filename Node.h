/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: setler
 *
 * Created on May 17, 2018, 3:01 PM
 */

#ifndef NODE_H
#define NODE_H

#include <thread>

class Node {
public:
    Node();
    Node(const Node& orig);
    virtual ~Node();
    
    int id = 0;
    
    int type = 0;
    
    std::thread::id thread_id;
    
    Node *left;
    Node *right;
    
private:

};

#endif /* NODE_H */

