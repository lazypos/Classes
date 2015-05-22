//
//  CConnectDelegate.h
//  redten
//
//  Created by zcw on 15-5-12.
//
// 连接代理，porxy模式

#ifndef __redten__CConnectDelegate__
#define __redten__CConnectDelegate__

#include <stdio.h>
#include "sigleton.h"
#include "CConnect.h"
#include "structs.h"
#include <memory>
#include <string>
using namespace std;

class CConnectDelegate {
    shared_ptr<CConnect> _conptr = shared_ptr<CConnect>(new CConnect);
public:
    bool    login();
    bool    send_message(int opt, const string& content);
    bool    recv_message(int& opt, string& content);
};

typedef mysigleton<CConnectDelegate> conDelegete;

#endif /* defined(__redten__CConnectDelegate__) */
