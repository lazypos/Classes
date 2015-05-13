//
//  CCardOperatorBase
//  redten
//
//  Created by zcw on 15-4-7.
//
// 卡牌操作基础类，用户验证卡牌的基本规则

#ifndef __redten__CCardOperator__
#define __redten__CCardOperator__

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

#define BOOM_MIN_COUNTS     3
#define STRAIGHT_MIN_COUNTS 3

typedef enum _cardtype{
    type_unknow = -1,
    type_singal,     // 单张
    type_apair,      // 对子
    type_straight,   // 顺子
    type_boom,       // 炸弹
}emCardType;

class CCardOperatorBase {
public:
    inline  bool    isKing(int seq){return (seq == 52 || seq == 53);}
    inline  bool    isA(int seq){return ((seq/4) == 0);}
    inline  bool    is2(int seq){return ((seq/4) == 1);}
    inline  bool    isK(int seq){return ((seq/4) == 12);}
    
    // 获取值,0-12或King(13)
    inline int getValue(int seq){
        if (isKing(seq)) {
            return 13;
        }
        return seq/4;
    }
    
    // 获取花色,0-3♠️❤️♣️♦️或king(4)
    inline int getColor(int seq){
        if (isKing(seq)) {
            return 4;
        }
        return seq%4;
    }
    
    // 判断是不是单张
    virtual bool    isTypeSingal(const list<int>& lstCards);
    // 判断是不是对
    virtual bool    isTypeApair(const list<int>& lstCards);
    // 判断是不是炸
    virtual bool    isTypeBoom(const list<int>& lstCards);
    // 判断是不是顺子
    virtual bool    isTypeStraight(const list<int>& lstCards);
    // 获取牌的类型
    virtual emCardType  getCardsType(const list<int>& lstCards);
    // 判断类似是否一致
    virtual bool    isTypeSame(const list<int>& lstPer, const list<int>& lstNow);
    
    // 比较单张大小
    virtual bool    isBiggerSingal(const list<int>& lstPer, const list<int>& lstNow);
    // 比较对大小
    virtual bool    isBiggerApair(const list<int>& lstPer, const list<int>& lstNow);
    // 比较炸大小
    virtual bool    isBiggerBoom(const list<int>& lstPer, const list<int>& lstNow);
    // 比较顺子大小
    virtual bool    isBiggerStraight(const list<int>& lstPer, const list<int>& lstNow);
    // 比较大小
    virtual bool    isBigger(const list<int>& lstPer, const list<int>& lstNow);
    
private:
    // 判断是不是普通炸
    virtual bool    isTypeNormalBoom(const list<int>& lstCards);
    // 判断是不是特殊炸
    virtual bool    isTypeSpecialBoom(const list<int>& lstCards);
    // 转换成点数大小
    virtual int     getRealValue(const int val);
};


#endif /* defined(__redten__CCardOperatorBase__) */
