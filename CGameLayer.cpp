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

    
    return true;
}

void
CGameLayer::initGame(){
    
}

bool
CGameLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    
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