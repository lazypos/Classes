//
//  CPlayer.h
//  redten
//
//  Created by zcw on 15-4-20.
//
// 玩家类，记录该局游戏每个玩家的信息

#ifndef __redten__CPlayer__
#define __redten__CPlayer__

#include <stdio.h>
#include <string>
#include <list>
#include "CCardSprite.h"
using namespace std;

class CPlayer{
public:
    int        seq = 0;     // 玩家序号
    float      time = 0;    // 玩家出牌剩余时间
    bool       isActive = false; // 是否是该玩家出牌
    bool       isOver = false; // 出完
    bool       isMainPlayer = false; // 是不是主玩家
    bool       isking = false; // 是不是老板
    bool       isWin = false;   // 是否赢了
    bool       isReady = false; // 是否准备好了
    int        sorcer = 0; // 分数
    string     username = ""; // 用户名
    
    list<card_ptr>  lstCards; // 手牌
    list<card_ptr>  lstFrontCards; // 门前的牌
    void    clearCards();   // 清理手牌
    
    CPlayer(){}
    ~CPlayer(){clearCards();}
    
    list<card_ptr>&  getCards(); // 获取手牌
    void             getSelectedCards(list<card_ptr>& lst); // 获取当前被选择的牌
    void             delSelectedCards(const list<int>& seq); // 删除被选择的牌
};

typedef shared_ptr<CPlayer> player_ptr;
#endif /* defined(__redten__CPlayer__) */
