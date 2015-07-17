//
//  CDestManager.h
//  redten
//
//  Created by zcw on 15-6-4.
//
//

#ifndef __redten__CDestManager__
#define __redten__CDestManager__

#include <stdio.h>
#include <mutex>
#include <map>
#include <vector>
#include "sigleton.h"
#include "CPlayer.h"

class CDeskManager{
public:
    int                     _deskNum = 0; // 桌子号
    map<int ,player_ptr>    _mapPlayers;  // 列表
    int                     _mainpos;
    mutex                   _mutex;
    
    vector<card_ptr>        _vecCards;
    
    CDeskManager();
    void  init();
    void setPlayInfo(const string& info);
    void updatePlayInfo(const string& info);
    void addPlayer(bool main, int pos, map<string,string>&mapInfo);
    void updatePlayer(int pos, map<string,string>&mapInfo);
    void getPlayerMap(map<int ,player_ptr>& map);
    void initPlayerCards(const string& info);
};

typedef mysigleton<CDeskManager> deskMamager;

#endif /* defined(__redten__CDestManager__) */
