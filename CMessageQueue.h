//
//  CMessageQueue.h
//  redten
//
//  Created by zcw on 15-5-2.
//
// 通讯类，管理俩消息队列，一个发送，一个接受

#ifndef __redten__CMessageQueue__
#define __redten__CMessageQueue__

#include <stdio.h>
#include <string>
#include <list>
#include <mutex>
#include "sigleton.h"
#include "structs.h"
using namespace std;

typedef shared_ptr<optMsg> optmsg;

class CMessageQueue {
    list<optMsg>    _lstMsg;
    list<optMsg>    _sendMsg;
    mutex           _msgMutex;
    mutex           _sendMutex;
public:
    void    push_message(optMsg msg);
    optMsg  pop_message();
    
    void    push_sendmessage(optMsg msg);
    optMsg  pop_sendmessage();
};

typedef mysigleton<CMessageQueue>  msg_queue;
#endif /* defined(__redten__CMessageQueue__) */
