//
//  CMessageQueue.cpp
//  redten
//
//  Created by zcw on 15-5-2.
//
//

#include "CMessageQueue.h"

void
CMessageQueue::push_message(optMsg msg){
    lock_guard<mutex> lk(_msgMutex);
    _lstMsg.push_back(msg);
}

optMsg
CMessageQueue::pop_message(){
    lock_guard<mutex> lk(_msgMutex);
    optMsg op;
    if (!_lstMsg.empty()) {
        op = _lstMsg.front();
        _lstMsg.pop_front();
    }
    return op;
}

void
CMessageQueue::push_sendmessage(optMsg msg){
    lock_guard<mutex> lk(_sendMutex);
    _sendMsg.push_back(msg);
}

optMsg
CMessageQueue::pop_sendmessage(){
    lock_guard<mutex> lk(_sendMutex);
    optMsg op;
    if (!_sendMsg.empty()) {
        op = _sendMsg.front();
        _sendMsg.pop_front();
    }
    return op;
}
