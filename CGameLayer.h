//
//  CGameLayer.h
//  redten
//
//  Created by zcw on 15-5-19.
//
//  游戏层

#ifndef __redten__CGameLayer__
#define __redten__CGameLayer__

#include <stdio.h>
#include "cocos2d.h"

#include <vector>
#include "CPlayer.h"
USING_NS_CC;

class CGameLayer : public CCLayer {
    
    CCSize  winSize;
    
    bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    
    // 出牌
    void onGreenClicked(CCObject* pSender);
    // 不出
    void onRedClicked(CCObject* pSender);
    
    CREATE_FUNC(CGameLayer)
    bool    init();
    void    initGame();
    
    int                 _deskNum = 0; // 桌子号
    vector<player_ptr>  _vecPlayers;  // 列表
    
public:
    static CCScene* scene();
    
    void setPlayInfo(const string& info);
};

#endif /* defined(__redten__CGameLayer__) */
