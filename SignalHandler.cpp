/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SignalHandler.cpp
 * Author: setler
 * 
 * Created on May 19, 2018, 7:17 PM
 */

#include "SignalHandler.h"

SignalHandler::SignalHandler() {
}

SignalHandler::SignalHandler(const SignalHandler& orig) {
}

SignalHandler::~SignalHandler() {
}

void SignalHandler::handler(int signal) {
    
    std::cout << "pid: " << std::this_thread::get_id() <<  " | ppid: " << getpid() << std::endl;
    
}