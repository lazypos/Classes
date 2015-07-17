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
#include "CConnectDelegate.h"

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
    initDowninfo();
    initUpinfo();
    
    
    // 开启调度
    this->schedule(schedule_selector(CGameLayer::gameSchedule), 0.1f);
    //this->schedule(schedule_selector(CGameLayer::netSchedule), 0.1f);
    thread_ptr = shared_ptr<thread>(new thread(std::bind(&CGameLayer::netSchedule, this)));
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
    printf("main:%d, %d, %d\n", _mainplayer, _downplayer, _upplayer);
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
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel->setPosition(ccp(winSize.width/2, 25));
    this->addChild(sorcerLabel, 1, tagSorcer0);
    // 昵称
    string name = "                ";
    if (!ptr->username.empty()) {
        name = ptr->username;
    }
    CCLabelTTF *lebname = CCLabelTTF::create(name.c_str(), "font/Marker Felt.ttf", 35);
    lebname->setPosition(ccp(winSize.width/2+200, 30));
    printf("%d===", (int*)lebname);
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
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel1 = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel1->setPosition(ccp(winSize.width-100, winSize.height/2+200));
    this->addChild(sorcerLabel1, 1, tagSorcer1);
    
    string name = "                ";
    if (!ptr->username.empty()) {
        name = ptr->username;
    }
    CCLabelTTF *lebname1 = CCLabelTTF::create(name.c_str(), "font/Marker Felt.ttf", 35);
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
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel2 = CCLabelBMFont::create(buf, "fontGreen.fnt");
    sorcerLabel2->setPosition(ccp(150, winSize.height/2+200));
    this->addChild(sorcerLabel2, 1, tagSorcer2);
    
    string name = "                  ";
    if (!ptr->username.empty()) {
        name = ptr->username;
    }
    CCLabelTTF *lebname2 = CCLabelTTF::create(name.c_str(), "font/Marker Felt.ttf", 35);
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
    
    // 分数
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel = (CCLabelBMFont*)(this->getChildByTag(tagSorcer0));
    sorcerLabel->setString(buf);
    
    string name = ptr->username;
    CCLabelTTF *lebname = (CCLabelTTF*)(this->getChildByTag(tagName0));
    //printf("%s,%u", name.c_str(), (int*)lebname);
    lebname->setString(ptr->username.c_str());
    //lebname->setString("hi");
    
    // 手牌
    
}

void
CGameLayer::updateDowninfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_downplayer];
    
    // 分数
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel = (CCLabelBMFont*)(this->getChildByTag(tagSorcer1));
    sorcerLabel->setString(buf);
    
    CCLabelTTF *lebname = (CCLabelTTF*)(this->getChildByTag(tagName1));
    lebname->setString(ptr->username.c_str());
}

void
CGameLayer::updateUpinfo(){
    map<int ,player_ptr> map;
    deskMamager::instance()->getPlayerMap(map);
    player_ptr ptr = map[_upplayer];
    
    // 分数
    int sorcer = ptr->sorcer;
    char buf[20];
    memset(buf, 0, 20);
    sprintf(buf, "%05d", sorcer);
    CCLabelBMFont* sorcerLabel = (CCLabelBMFont*)(this->getChildByTag(tagSorcer2));
    sorcerLabel->setString(buf);
    
    CCLabelTTF *lebname = (CCLabelTTF*)(this->getChildByTag(tagName2));
    lebname->setString(ptr->username.c_str());
}

void
CGameLayer::gameSchedule(float dt){
    updateMaininfo();
    updateDowninfo();
    updateUpinfo();
}

void
CGameLayer::netSchedule(){
    int opt = 0;
    string rst;
    if (conDelegete::instance()->recv_message(opt, rst)){
        switch (opt) {
            case opt_play_list:
                deskMamager::instance()->updatePlayInfo(rst);
                break;
            case opt_game_start:
                deskMamager::instance()->initPlayerCards(rst);
                break;
            default:
                break;
        }
    }

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