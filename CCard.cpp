//
//  CCard.cpp
//  redten
//
//  Created by zcw on 15-4-9.
//
//

#include "CCard.h"
CCard::CCard()
: _cardSeq(-1), _bSelected(false){
    
}

CCard::~CCard(){
}

void    CCard::setSeq(int seq){
    std::lock_guard<std::mutex> lk(_mutex);
    _cardSeq = seq;
}

void    CCard::setSelected(bool bStatus){
    std::lock_guard<std::mutex> lk(_mutex);
    _bSelected = bStatus;
}

bool   CCard::isSelected(){
    std::lock_guard<std::mutex> lk(_mutex);
    return _bSelected;
}

int    CCard::getSeq(){
    std::lock_guard<std::mutex> lk(_mutex);
    return _cardSeq;
}
