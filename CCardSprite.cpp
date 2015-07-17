//
//  CCardSprite.cpp
//  redten
//
//  Created by zcw on 15-4-9.
//
//

#include "CCardSprite.h"

CCardSprite::CCardSprite(){
    
}

CCardSprite::~CCardSprite(){
    
}

shared_ptr<CCardSprite>
CCardSprite::CreateSprite(int seq){
    //CCardSprite *card = new CCardSprite;
    card_ptr card1 = make_shared<CCardSprite>();
    CCardSprite *card = card1.get();
    if (seq == 52) {
        card->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("blackking"));
    }else if (seq == 53) {
        card->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("redking"));
    }else {
        card->initWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("front"));
        CCSize cardsize = card->getContentSize();
        char buf[32] = {0};
        int flowerNum = seq%4;
        int valueNum = seq/4;
        CCSprite * num = NULL;
        if (flowerNum == 0 || flowerNum == 2) {
            sprintf(buf, "rednum%02d", valueNum);
        }else {
            sprintf(buf, "blacknum%02d", valueNum);
        }
        num = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buf));
        num->setPosition(ccp(30,cardsize.height-30));
        card->addChild(num);
        
        memset(buf, 0, 32);
        sprintf(buf, "flower%d", flowerNum);
        CCSprite *color = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buf));
        color->setPosition(ccp(cardsize.width/2, cardsize.height/2));
        card->addChild(color);
    }
    card->setSelected(false);
    card->setSeq(seq);
    return card1;
}