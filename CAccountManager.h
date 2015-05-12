//
//  CAccountManager.h
//  redten
//
//  Created by zcw on 15-5-12.
//
//  账号管理

#ifndef __redten__CAccountManager__
#define __redten__CAccountManager__

#include <stdio.h>
#include "sigleton.h"

class CAccountManager {
    int _uid = 0;   // 用户唯一ID
    int _session;   // 本次登录的认证号
    int _serverkey; // 服务器加密的密钥
    int _clientkey; // 客户端密钥
public:
    
};

#endif /* defined(__redten__CAccountManager__) */
