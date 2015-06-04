#include "testsence.h"
#include "HelloWorldScene.h"
#include "CConnectDelegate.h"
#include "structs.h"
#include "CGameLayer.h"

CCScene* testsence::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    testsence *layer = testsence::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool testsence::init()
{
    if ( !CCLayer::init() )
        return false;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // 加入正在加入桌子的字幕
    CCLabelTTF* pLabel = CCLabelTTF::create("", "Arial", 24);
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2));
    this->addChild(pLabel, 1, 100);
    
    // 状态显示调度
    this->schedule(schedule_selector(testsence::statSchedule), 0.1f);
    // 网络连接调度
    this->schedule(schedule_selector(testsence::connectSchedule), 0.1f);
    
    return true;
}

void
testsence::statSchedule(float dt){
    static int time = 0;
    static int dot = 0;
    
    CCLabelTTF* pLabel = (CCLabelTTF*)(this->getChildByTag(100));
    if (time++ %10 == 0) {
        int dotCounts = dot++%4;
        if (dotCounts == 0) {
            if (blogin)
                pLabel->setString("正在匹配玩家");
            else
                pLabel->setString("正在登陆");
        }else if (dotCounts == 1){
            if (blogin)
                pLabel->setString("正在匹配玩家 .");
            else
                pLabel->setString("正在登陆 .");
        }else if (dotCounts == 2){
            if (blogin)
                pLabel->setString("正在匹配玩家 . .");
            else
                pLabel->setString("正在登陆 . .");
        }else if (dotCounts == 3){
            if (blogin)
                pLabel->setString("正在匹配玩家 . . .");
            else
                pLabel->setString("正在登陆 . . .");
        }
    }
    
}

void
testsence::reFindDesk(){
    badddesk = false;
}

void
testsence::connectSchedule(float dt){
    // 未登录
    if (!blogin) {
        if (conDelegete::instance()->login()) {
            blogin = true;
        }
    }
    // 已经登陆, 未匹配玩家
    else if (!badddesk){
        if (conDelegete::instance()->send_message(opt_add_desk))
        {
            int opt = 0;
            string rst;
            if (conDelegete::instance()->recv_message(opt, rst)){
                if (opt == opt_add_desk){
                    CCTransitionProgressHorizontal* reScene = CCTransitionProgressHorizontal ::create(1,CGameLayer::scene());
                    CCDirector::sharedDirector()->replaceScene(reScene);
                    badddesk = true;
                }
            }
        }
    }
}

void testsence::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

bool testsence::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCTransitionProgressHorizontal* reScene = CCTransitionProgressHorizontal ::create(1,HelloWorld::scene());
    CCDirector::sharedDirector()->replaceScene(reScene);
    return true;
}

