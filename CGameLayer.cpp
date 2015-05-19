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