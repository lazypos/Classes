//
//  CCardSprite.h
//  redten
//
//  Created by zcw on 15-4-9.
//
//

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
    
    static CCardSprite* CreateSprite(int seq);
    
};


#endif /* defined(__redten__CCardSprite__) */
