//
//  CAccountManager.h
//  redten
//
//  Created by zcw on 15-5-12.
//
//  账号管理类，用户管理用户的重要基本信息

#ifndef __redten__CAccountManager__
#define __redten__CAccountManager__

#include <stdio.h>
#include <string>
#include "sigleton.h"
using namespace std;
//typedef enum _play_stat{
//    stat_nologin = -1, // 未登录
//    stat_
//}play_stat;

class CAccountManager {
    int _uid = 0;   // 用户唯一ID
    int _session;   // 本次登录的认证号
    int _serverkey; // 服务器加密的密钥
    int _clientkey; // 客户端密钥
    
    //play_stat   _stat; // 当前状态
public:
    void    set_uid(int uid);
    int     get_uid();
    
    void    set_session(int session);
    int     get_session();
    
    string  username;
    int     sorcer = 0;
};

typedef mysigleton<CAccountManager> accountMgr;

#endif /* defined(__redten__CAccountManager__) */
