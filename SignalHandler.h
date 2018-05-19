/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SignalHandler.h
 * Author: setler
 *
 * Created on May 19, 2018, 7:17 PM
 */

#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <iostream>
#include <thread>
#include <signal.h>
#include <unistd.h>

class SignalHandler {
public:
    SignalHandler();
    SignalHandler(const SignalHandler& orig);
    virtual ~SignalHandler();
    
    static void handler(int signal);
    
private:

};

#endif /* SIGNALHANDLER_H */

