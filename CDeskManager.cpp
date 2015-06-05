//
//  CDestManager.cpp
//  redten
//
//  Created by zcw on 15-6-4.
//
//

#include "CDeskManager.h"
#include "baseFunc.h"
#include <stdlib.h>
#include <sstream>
#include "CAccountManager.h"

CDeskManager::CDeskManager(){
    //_vecPlayers.reserve(3);
}

void
CDeskManager::setPlayInfo(const string& info){
    
    map<string, string> tmp;
    DoSeparate(info, "\n", tmp);
    _deskNum = atoi(tmp["desk"].c_str());
    int pos = atoi(tmp["pos"].c_str());
    _mainpos = pos;
    
    ostringstream os;
    map<string, string>::iterator it;
    for (int i=0; i<3; ++i) {
        os.str("");
        os << "p" << i;
        addPlayer((i==pos), i, tmp);
    }
}

void
CDeskManager::addPlayer(bool main, int pos, map<string,string>&mapInfo){
    lock_guard<mutex> lk(_mutex);
    
    player_ptr ptr = player_ptr(new CPlayer);
    
    if (main) {
        ptr->isMainPlayer = main;
        ptr->sorcer = accountMgr::instance()->sorcer;
        ptr->username = accountMgr::instance()->username;
    }
    else{
        ostringstream osr;
        osr << "r" << pos;
        ostringstream osp;
        osp << "p" << pos;
        ostringstream oss;
        oss << "s" << pos;
        if (mapInfo.find(osr.str()) != mapInfo.end()) {
            ptr->isReady = (mapInfo[osr.str()] == "1");
            ptr->sorcer = atoi(mapInfo[oss.str()].c_str());
            ptr->username = mapInfo[osp.str()];
        }
    }
    _mapPlayers[pos] = ptr;
}







