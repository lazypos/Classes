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

class CConnectDelegate {
public:
    
};

typedef mysigleton<CConnectDelegate> con_proxy;

#endif /* defined(__redten__CConnectDelegate__) */
