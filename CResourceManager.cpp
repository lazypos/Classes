//
//  CResourceManager.cpp
//  redten
//
//  Created by zcw on 15-4-9.
//
//

#include "CResourceManager.h"

#define NUM_SIZE 39

CResourceManager::CResourceManager(){
    init();
}

void
CResourceManager::init(){
    // init 花色
    CCSpriteFrame* flowerframe = CCSpriteFrame::create("game_list_poker_flower.png", CCRect(0,0,44,42));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(flowerframe, "flower0");
    flowerframe = CCSpriteFrame::create("game_list_poker_flower.png", CCRect(44,0,44,42));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(flowerframe, "flower1");
    flowerframe = CCSpriteFrame::create("game_list_poker_flower.png", CCRect(88,0,44,42));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(flowerframe, "flower2");
    flowerframe = CCSpriteFrame::create("game_list_poker_flower.png", CCRect(132,0,44,42));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(flowerframe, "flower3");
    
    // init 点数
    CCSpriteFrame* numframe;
    char buf[32] = {0};
    for (int i=0; i<13; i++) {
        memset(buf, 0, 32);
        sprintf(buf, "rednum%02d", i);
        numframe = CCSpriteFrame::create("game_list_poker_num.png", CCRect(i*NUM_SIZE,NUM_SIZE,NUM_SIZE,NUM_SIZE));
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(numframe, buf);
        memset(buf, 0, 32);
        sprintf(buf, "blacknum%02d", i);
        numframe = CCSpriteFrame::create("game_list_poker_num.png", CCRect(i*NUM_SIZE,0,NUM_SIZE,NUM_SIZE));
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(numframe, buf);
    }
    
    // init 背景
    CCSpriteFrame* puke = CCSpriteFrame::create("game_list_poker_surface.png", CCRect(0,0,98,138));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(puke, "front");
    puke = CCSpriteFrame::create("game_list_poker_surface.png", CCRect(99,0,98,138));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(puke, "redking");
    puke = CCSpriteFrame::create("game_list_poker_surface.png", CCRect(197,0,98,138));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(puke, "blackking");
    puke = CCSpriteFrame::create("game_list_poker_surface.png", CCRect(296,0,98,138));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(puke, "back");
    
    CCSpriteFrame* button = CCSpriteFrame::create("game_bg_play_long_btn.png", CCRect(0,0,152,61));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(button, "redbutton");
    button = CCSpriteFrame::create("game_bg_play_long_btn.png", CCRect(152,0,152,61));
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(button, "greenbutton");
}