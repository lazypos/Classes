//
//  testsence.h
//  redten
//
//  Created by zcw on 15-3-27.
//
//

#ifndef redten_testsence_h
#define redten_testsence_h

#include "cocos2d.h"
USING_NS_CC;

class testsence : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(testsence);
    
   //bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
   bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    // 加入桌子调度
    void    statSchedule(float dt);
    // 网络连接调度
    void    connectSchedule(float dt);
    
    bool    blogin = false;
    bool    badddesk = false;
    // 重新加入桌子
    void    reFindDesk();
};

#endif
