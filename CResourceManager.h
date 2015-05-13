//
//  CResourceManager.h
//  redten
//
//  Created by zcw on 15-4-9.
//
//  游戏资源管理类，用于加载和管理游戏用到的图片/声音等资源

#ifndef __redten__CResourceManager__
#define __redten__CResourceManager__

#include <stdio.h>
#include "cocos2d.h"
#include "sigleton.h"

USING_NS_CC;

class CResourceManager{
public:
    CResourceManager();
    void    init();
};

typedef mysigleton<CResourceManager> CResourceMgr;

#endif /* defined(__redten__CResourceManager__) */
