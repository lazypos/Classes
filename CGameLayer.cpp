//
//  CGameLayer.cpp
//  redten
//
//  Created by zcw on 15-5-19.
//
//

#include "CGameLayer.h"
#include "CResourceManager.h"
#include "CCardOperatorRedTen.h"
#include "CDeskManager.h"


bool
CGameLayer::init(){
    CResourceMgr::instance()->init();
    
    // 添加背景
    CCSprite * bg = CCSprite::create("game_bg_day.jpg");
    winSize = CCDirector::sharedDirector()->getWinSize();
    CCSize  bgSize = bg->getContentSize();
    bg->setScaleX(winSize.width/bgSize.width);
    bg->setScaleY(winSize.height/bgSize.height);
    bg->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(bg, -1);

    // 把位置设置好
    setPlayerPos();
    
    // 开启调度
    this->schedule(schedule_selector(CGameLayer::gameSchedule), 0.1f);
    this->schedule(schedule_selector(CGameLayer::netSchedule), 0.1f);
    
    return true;
}

void
CGameLayer::initGame(){
    
    
   
}

void
CGameLayer::setPlayerPos(){
    map<int, player_ptr>& tmp = deskMamager::instance()->_mapPlayers;
    for (int i=0; i<3; ++i) {
        if (tmp[i]->isMainPlayer) {
            _mainplayer = i;
            _downplayer = (i+1)%3;
            _upplayer = (i+2)%3;
        }
    }
}

void
CGameLayer::gameSchedule(float dt){
    
}

void
CGameLayer::netSchedule(float dt){
    
}

bool
CGameLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    return true;
}

void
CGameLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    
}

CCScene*
CGameLayer::scene(){
    CCScene *pScene = CCScene::create();
    CGameLayer *pGameLayer = CGameLayer::create();
    pScene->addChild(pGameLayer);
    return pScene;
}