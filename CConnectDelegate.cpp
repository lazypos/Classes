//
//  CConnectDelegate.cpp
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#include "CConnectDelegate.h"
#include "CMessageQueue.h"

bool
CConnectDelegate::login(){
    if (!_conptr->isConnected()) {
        _conptr->connect_to_server();
    }
    return  true;
}

bool
CConnectDelegate::send_message(int opt, const string& content){
    _conn_header hd;
    hd.opt = opt;
    hd.flag = 0x5183;
    hd.datalen = (unsigned int)content.length();
    hd.crc = hd.opt|hd.datalen;
    if (hd.datalen != 0) {
        hd.crc |= (unsigned int)content[content.length()-1];
    }
    return _conptr->send_to_server(content.c_str(), content.length());
}

bool
CConnectDelegate::recv_message(int& opt, string& content){
    _conn_header hd;
    if (_conptr->recv_from_server((char*)&hd, sizeof(hd))) {
        content.resize(hd.datalen, 0);
        if (hd.flag == 0x5183 && _conptr->recv_from_server((char*)content.c_str(), hd.datalen)){
            unsigned int tmpcrc = hd.opt|hd.datalen;
            if (hd.datalen != 0) {
                tmpcrc |= (unsigned int)content[content.length()-1];
                return (tmpcrc == hd.crc);
            }
        }
    }
    return false;
}
