//
//  CConnect.h
//  redten
//
//  Created by zcw on 15-5-12.
//
// 网络通信类

#ifndef __redten__CConnect__
#define __redten__CConnect__


#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

class CConnect {
    string _servip = "127.0.0.1";
    unsigned short _servport = 51832;
    bool    bconnected = false;
    int     _fd = -1;
    
public:
    bool connect_to_server();
    bool send_to_server(const char* data, size_t len);
    bool recv_from_server(char* buf, size_t len);
    inline bool isConnected(){return bconnected;}
};

#endif /* defined(__redten__CConnect__) */
