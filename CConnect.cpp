//
//  CConnect.cpp
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#include "CConnect.h"
#include <unistd.h>

bool
CConnect::connect_to_server(){
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htonl(_servport);
    servaddr.sin_addr.s_addr = inet_addr(_servip.c_str());
    
    if (_fd)
    close(_fd);
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    int n = connect(_fd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (n == 0) {
        printf("connect ok\n");
        return true;
    }
    _fd = 0;
    return false;
}

bool
CConnect::send_to_server(const char* data, size_t len){
    size_t sendlen = 0;
    if (_fd) {
        while (sendlen < len) {
            int n = send(_fd, data+sendlen, len-sendlen, 0);
            if (n <= 0) {
                break;
            }
            sendlen += n;
        }
    }
    return (sendlen == len);
}

bool
CConnect::recv_from_server(char* buf, size_t len){
    size_t recvlen = 0;
    if (_fd){
        while (recvlen < len) {
            int n = recv(_fd, (void*)(buf+recvlen), len-recvlen, 0);
            if (n <=0) {
                break;
            }
            recvlen += n;
        }
    }
    return (recvlen == len);
}

