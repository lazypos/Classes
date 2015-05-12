//
//  CMessageQueue.cpp
//  redten
//
//  Created by zcw on 15-5-2.
//
//

#include "CMessageQueue.h"

void
CMessageQueue::push_message(optmsg msg){
    lock_guard<mutex> lk(_msgMutex);
    _lstMsg.push_back(msg);
}

optmsg
CMessageQueue::pop_message(){
    lock_guard<mutex> lk(_msgMutex);
    optmsg op;
    if (!_lstMsg.empty()) {
        op = _lstMsg.front();
        _lstMsg.pop_front();
    }
    return op;
}

void
CMessageQueue::push_sendmessage(optmsg msg){
    lock_guard<mutex> lk(_sendMutex);
    _sendMsg.push_back(msg);
}

optmsg
CMessageQueue::pop_sendmessage(){
    lock_guard<mutex> lk(_sendMutex);
    optmsg op;
    if (!_sendMsg.empty()) {
        op = _sendMsg.front();
        _sendMsg.pop_front();
    }
    return op;
}
