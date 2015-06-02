//
//  CAccountManager.cpp
//  redten
//
//  Created by zcw on 15-5-12.
//
//

#include "CAccountManager.h"

void
CAccountManager::set_uid(int uid){
    _uid = uid;
}

int
CAccountManager::get_uid(){
    return _uid;
}

void
CAccountManager::set_session(int session){
    _session = session;
}

int
CAccountManager::get_session(){
    return _session;
}