//
//  CConnect.cpp
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#include "CConnect.h"
#include <functional>
#include <unistd.h>
#include "CMessageQueue.h"
#include "CCommendMode.h"

void
CConnect::start_connect_thread(){
    thread_ptr = shared_ptr<thread>(new thread(bind(&CConnect::connect_thread, this)));
    thread_ptr->detach();
    recv_thread_ptr = shared_ptr<thread>(new thread(bind(&CConnect::connect_thread, this)));
    recv_thread_ptr->detach();
    send_thread_ptr = shared_ptr<thread>(new thread(bind(&CConnect::connect_thread, this)));
    send_thread_ptr->detach();
}

// 连接线程，断线自动重连
void CConnect::connect_thread(){
    while (true) {
        if (!bconnected) {
            if (connect_to_server()) {
                bconnected = true;
                optMsg op;
                op.opt = opt_game_connect;
                msg_queue::instance()->push_message(op);
            }
        }
        sleep(5);
    }
}

bool
CConnect::connect_to_server(){
    return true;
}

void
CConnect::send_thread(){
    while (true) {
        optMsg op = msg_queue::instance()->pop_sendmessage();
        if (op.opt != opt_unknow) {
            string rst = comManager::instance()->dispatchCommend(op);
            if (!rst.empty()) {
                // do same things,send to server
            }
        }
        usleep(1000);
    }
}

void
CConnect::recv_thread(){
    while (true) {
        
    }
}



