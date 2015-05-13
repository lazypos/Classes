//
//  CCommendMode.cpp
//  redten
//
//  Created by zcw on 15-5-13.
//
//

#include "CCommendMode.h"

// 注册操作函数
void
CCommendMode::registCommend(game_opt op, commend_cb cb){
    mapCommend[op] = cb;
}

// 根据操作类型处理数据，得到处理结果
string
CCommendMode::dispatchCommend(const optMsg& op){
    string result;
    map<game_opt, commend_cb>::iterator it = mapCommend.find(op.opt);
    if (it != mapCommend.end()) {
        result = it->second(op);
    }
    return result;
}
