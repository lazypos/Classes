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
#include "CCardSprite.h"

CDeskManager::CDeskManager(){
    //_vecPlayers.reserve(3);
}

void
CDeskManager::init(){
    for (int i=0; i<54; i++) {
        card_ptr cpt = CCardSprite::CreateSprite(i);
        _vecCards.push_back(cpt);
    }
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
CDeskManager::updatePlayInfo(const string& info){
    map<string, string> tmp;
    DoSeparate(info, "\n", tmp);
    ostringstream os;
    map<string, string>::iterator it;
    for (int i=0; i<3; ++i) {
        os.str("");
        os << "p" << i;
        updatePlayer(i, tmp);
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
        //printf("%s, %s", ptr->username.c_str(), accountMgr::instance()->username.c_str());
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
            //printf("%s, %d, %d", ptr->username.c_str(), ptr->sorcer, pos);
        }
    }
    //_mapPlayers[pos] = ptr;
    _mapPlayers.insert(make_pair(pos, ptr));
}

void
CDeskManager::updatePlayer(int pos, map<string,string>&mapInfo){
    player_ptr ptr = _mapPlayers[pos];
    ptr->ischanged = true;
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
        //printf("%s, %d, %d", ptr->username.c_str(), ptr->sorcer, pos);
    }

}

void
CDeskManager::getPlayerMap(map<int ,player_ptr>& map){
    lock_guard<mutex> lk(_mutex);
    map = _mapPlayers;
}

void
CDeskManager::initPlayerCards(const string& info){
    map<string, string> tmp;
    DoSeparate(info, "\n", tmp);
    int z = atoi(tmp["z"].c_str());
    player_ptr ptr = _mapPlayers[z];
    ptr->isActive = true;
    ptr->time = 30;
    ptr->ischanged = true;
    
    player_ptr mptr = _mapPlayers[_mainpos];
    mptr->ischanged = true;
    list<string> lstcards;
    stringToList(lstcards, tmp["c"].c_str(), ",");
    
    for (string c : lstcards) {
        int n = atoi(c.c_str());
        card_ptr cpt = _vecCards[n];
        
        mptr->lstCards.push_back(cpt);
    }
    
}



