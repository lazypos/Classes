//
//  CConnectDelegate.cpp
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#include "CConnectDelegate.h"
#include "CMessageQueue.h"
#include "CAccountManager.h"
#include "baseFunc.h"
#include <stdlib.h>

bool
CConnectDelegate::login(){
    if (!_conptr->isConnected()) {
        if (!_conptr->connect_to_server())
            return false;
    }
    if (send_message(opt_login)){
        int opt = 0;
        string content;
        if (recv_message(opt, content)) {
            if (opt == opt_login) {
                // 记录下id和seesion
                map<string, string> tmpmap;
                DoSeparate(content, "\n", tmpmap);
                accountMgr::instance()->set_uid(atoi(tmpmap["uid"].c_str()));
                accountMgr::instance()->set_session(atoi(tmpmap["session"].c_str()));
                return true;
            }
        }
    }
    return false;
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
    string senddata = string((char*)&hd, sizeof(hd)) + content;
    return _conptr->send_to_server(senddata.c_str(), senddata.length());
}

bool
CConnectDelegate::recv_message(int& opt, string& content){
    _conn_header hd;
    memset(&hd, 0, sizeof(hd));
    if (_conptr->recv_from_server((char*)&hd, sizeof(hd))) {
        content.resize(hd.datalen, 0);
        opt = hd.opt;
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
