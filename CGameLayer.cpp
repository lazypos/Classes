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
#include "structs.h"

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
    // 将玩家初始化到界面
    initMaininfo();
    
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
    map<int ,player_ptr> tmp;
    deskMamager::instance()->getPlayerMap(tmp);
    
    for (int i=0; i<3; ++i) {
        if (tmp[i]->isMainPlayer) {
            _mainplayer = i;
            _downplayer = (i+1)%3;
            _upplayer = (i+2)%3;
        }
    }
}

void
CGameLayer::initMaininfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_mainplayer];
    
    // 头像
    CCSprite *sorcerPic = CCSprite::create("game_icon_treasure.png");
    sorcerPic->setPosition(ccp(winSize.width/2-100, 25));
    this->addChild(sorcerPic);
    // 分数
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%d", sorcer);
    CCLabelBMFont* sorcerLabel = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel->setPosition(ccp(winSize.width/2, 25));
    this->addChild(sorcerLabel, 1, tagSorcer0);
    // 昵称
    CCLabelTTF *lebname = CCLabelTTF::create(ptr->username.c_str(), "font/Marker Felt.ttf", 35);
    lebname->setPosition(ccp(winSize.width/2+200, 30));
    this->addChild(lebname, 1, tagName0);
}

void
CGameLayer::initDowninfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_downplayer];
    
    CCSprite *sorcerPic1 = CCSprite::create("game_icon_treasure.png");
    sorcerPic1->setPosition(ccp(winSize.width-200, winSize.height/2+200));
    this->addChild(sorcerPic1);
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%d", sorcer);
    CCLabelBMFont* sorcerLabel1 = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel1->setPosition(ccp(winSize.width-100, winSize.height/2+200));
    this->addChild(sorcerLabel1, 1, tagSorcer1);
    
    CCLabelTTF *lebname1 = CCLabelTTF::create(ptr->username.c_str(), "font/Marker Felt.ttf", 35);
    lebname1->setPosition(ccp(winSize.width-100, winSize.height/2+150));
    this->addChild(lebname1, 1, tagName1);
    CCLabelBMFont* cardsNum1 = CCLabelBMFont::create("0", "fontVipLevel.fnt");
    cardsNum1->setPosition(ccp(winSize.width-50, winSize.height/2+100));
    this->addChild(cardsNum1, 1, tagCards1);
}

void
CGameLayer::initUpinfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_upplayer];
    
    CCSprite *sorcerPic2 = CCSprite::create("game_icon_treasure.png");
    sorcerPic2->setPosition(ccp(50, winSize.height/2+200));
    this->addChild(sorcerPic2);
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%d", sorcer);
    CCLabelBMFont* sorcerLabel2 = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel2->setPosition(ccp(150, winSize.height/2+200));
    this->addChild(sorcerLabel2, 1, tagSorcer2);
    
    CCLabelTTF *lebname2 = CCLabelTTF::create(ptr->username.c_str(), "font/Marker Felt.ttf", 35);
    lebname2->setPosition(ccp(100, winSize.height/2+150));
    this->addChild(lebname2, 1, tagName2);
    CCLabelBMFont* cardsNum2 = CCLabelBMFont::create("0", "fontVipLevel.fnt");
    cardsNum2->setPosition(ccp(50, winSize.height/2+100));
    this->addChild(cardsNum2, 1, tagCards2);
}

void
CGameLayer::updateMaininfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_mainplayer];
}

void
CGameLayer::updateDowninfo(){
    
}

void
CGameLayer::updateUpinfo(){
    
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