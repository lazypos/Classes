//
//  CCommendMode.h
//  redten
//
//  Created by zcw on 15-5-13.
//
//  commend模式，所有命令注册好处理函数

#ifndef __redten__CCommendMode__
#define __redten__CCommendMode__

#include <stdio.h>
#include "sigleton.h"
#include <map>
#include "structs.h"
#include <functional>
using namespace std;

typedef function<string(optMsg)> commend_cb;

class CCommendMode {
    map<game_opt, commend_cb> mapCommend;
    
public:
    void    registCommend(game_opt op, commend_cb cb);
    string  dispatchCommend(const optMsg& op);
};

typedef mysigleton<CCommendMode> comManager;

#endif /* defined(__redten__CCommendMode__) */
