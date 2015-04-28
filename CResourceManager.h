//
//  CResourceManager.h
//  redten
//
//  Created by zcw on 15-4-9.
//
//

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
