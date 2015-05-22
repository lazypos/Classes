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
    
public:
    static CCScene* scene();

};

#endif /* defined(__redten__CGameLayer__) */
