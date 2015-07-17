//
//  CCardSprite.h
//  redten
//
//  Created by zcw on 15-4-9.
//
// 卡牌精灵类，用于生产卡牌精灵

#ifndef __redten__CCardSprite__
#define __redten__CCardSprite__

#include <cocos2d.h>
#include "CCard.h"

USING_NS_CC;

class CCardSprite
    : public CCard
    , public CCSprite
{
public:
    CCardSprite();
    ~CCardSprite();
    
    static shared_ptr<CCardSprite> CreateSprite(int seq);
    
};

typedef shared_ptr<CCardSprite>   card_ptr;


#endif /* defined(__redten__CCardSprite__) */
