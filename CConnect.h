//
//  CConnect.h
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#ifndef __redten__CConnect__
#define __redten__CConnect__


#include <stdio.h>
#include <thread>
#include <string>
#include <sys/socket.h>
using namespace std;

class CConnect {
    shared_ptr<thread> thread_ptr;
    shared_ptr<thread> recv_thread_ptr;
    shared_ptr<thread> send_thread_ptr;
    string _servip = "172.16.1.110";
    unsigned short _servport = 8886;
    bool    bconnected = false;
    
protected:
    void connect_thread();
    void send_thread();
    void recv_thread();
    bool connect_to_server();
    
public:
    void start_connect_thread();
};

#endif /* defined(__redten__CConnect__) */
