//
//  CCardOperatorBase.cpp
//  redten
//
//  Created by zcw on 15-4-7.
//
//

#include "CCardOperatorBase.h"

bool
CCardOperatorBase::isTypeSingal(const list<int> &lstCards){
    if (lstCards.size() == 1) {
        return true;
    }
    return false;
}

bool
CCardOperatorBase::isTypeApair(const list<int>& lstCards){
    if (lstCards.size() == 2) {
        if (lstCards.front() == lstCards.back()) {
            return true;
        }
    }
    return false;
}

bool
CCardOperatorBase::isTypeBoom(const list<int>& lstCards){
    if (isTypeNormalBoom(lstCards) || isTypeNormalBoom(lstCards)) {
        return true;
    }
    return false;
}

bool
CCardOperatorBase::isTypeStraight(const list<int>& lstCards){
    bool isStraight = false;
    do {
        if (lstCards.size() < STRAIGHT_MIN_COUNTS)
            break;
        
        // 先转化成 value
        list<int> lstCardsValue;
        for (int seq : lstCards) {
            lstCardsValue.push_back(getValue(seq));
        }
        
        lstCardsValue.sort();
        if (isKing(lstCardsValue.back()))
            break;
        
        // 如果带A, A拿掉以后必须头是2或尾是K
        bool hasA = isA(lstCardsValue.front());
        if (hasA) {
            lstCardsValue.pop_front();
            if (!isK(lstCardsValue.back())
                && !is2(lstCardsValue.front()) )
                break;
        }
        
        // 去掉A后肯定是顺
        int tmp = -1;
        bool straight = true;
        for (int v : lstCardsValue) {
            if (tmp == -1){
                tmp = v;
                continue;
            }
            if (v != tmp + 1) {
                straight = false;
                break;
            }
        }
        isStraight = straight;
        
    } while (false);
    
    return isStraight;
}

emCardType
CCardOperatorBase::getCardsType(const list<int>& lstCards)
{
    emCardType cardsType = type_unknow;
    if (isTypeSingal(lstCards))
        cardsType = type_singal;
    else if (isTypeApair(lstCards))
        cardsType = type_apair;
    else if (isTypeBoom(lstCards))
        cardsType = type_boom;
    else if (isTypeStraight(lstCards))
        cardsType = type_straight;
    
    return cardsType;
}

bool
CCardOperatorBase::isTypeSame(const list<int>& lstPer, const list<int>& lstNow){
    return (getCardsType(lstPer) == getCardsType(lstNow));
}

bool
CCardOperatorBase:: isTypeNormalBoom(const list<int>& lstCards){
    if (lstCards.size() >= BOOM_MIN_COUNTS) {
        int var = lstCards.front();
        for (int v : lstCards) {
            if (v != var) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool
CCardOperatorBase::isTypeSpecialBoom(const list<int>& lstCards){
    return true;
}

bool
CCardOperatorBase::isBiggerSingal(const list<int>& lstPer, const list<int>& lstNow){
    int valPer = getValue(lstPer.front());
    int valNow = getValue(lstNow.front());
    
    valPer = getRealValue(valPer);
    valNow = getRealValue(valNow);
    
    return (valNow > valPer);
}

bool
CCardOperatorBase::isBiggerApair(const list<int>& lstPer, const list<int>& lstNow){
    return isBiggerSingal(lstPer, lstNow);
}

bool
CCardOperatorBase::isBiggerBoom(const list<int>& lstPer, const list<int>& lstNow){
    return true;
}

bool
CCardOperatorBase::isBiggerStraight(const list<int>& lstPer, const list<int>& lstNow){
    list<int> per(lstPer);
    list<int> now(lstNow);
    
    per.pop_front();
    now.pop_front();
    
    int perVal = getValue(per.front());
    int nowVal = getValue(now.front());
    return nowVal > perVal;
}

bool
CCardOperatorBase::isBigger(const list<int>& lstPer, const list<int>& lstNow){
    bool isbigger = false;
    if (isTypeSame(lstPer, lstNow)) {
        emCardType ct = getCardsType(lstPer);
        switch (ct) {
            case type_singal:
                isbigger = isBiggerSingal(lstPer, lstNow);
                break;
            case type_apair:
                isbigger = isBiggerApair(lstPer, lstNow);
                break;
            case type_straight:
                isbigger = isBiggerStraight(lstPer, lstNow);
                break;
            case type_boom:
                isbigger = isBiggerBoom(lstPer, lstNow);
                break;
            default:
                break;
        }
    }else{
        if (isTypeBoom(lstNow))
            isbigger = true;
    }
    return isbigger;
}

int
CCardOperatorBase::getRealValue(const int val){
    return val;
}