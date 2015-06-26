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
#include <thread>

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
    
    // 界面调度
    void    gameSchedule(float dt);
    
    // 网络调度
    void    netSchedule();

#define stat_not_start 10
#define stat_started   11
    
    int     _game_stat = 0;
    int     _upplayer = 0;
    int     _downplayer = 0;
    int     _mainplayer = 0;
    
    void    setPlayerPos();
    void    initMaininfo();
    void    initDowninfo();
    void    initUpinfo();
    void    updateMaininfo();
    void    updateDowninfo();
    void    updateUpinfo();
    
public:
    static CCScene* scene();
    shared_ptr<thread> thread_ptr;
};

#endif /* defined(__redten__CGameLayer__) */
