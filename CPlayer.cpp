//
//  CPlayer.cpp
//  redten
//
//  Created by zcw on 15-4-20.
//
//

#include "CPlayer.h"

list<card_ptr>& CPlayer::getCards(){
    return lstCards;
}

void
CPlayer::clearCards(){
    lstCards.clear();
}

void
CPlayer::getSelectedCards(list<card_ptr>& lstSelected){
    for (const card_ptr& ptr : lstCards) {
        if (ptr->isSelected()) {
            lstSelected.push_back(ptr);
        }
    }
}

void
CPlayer::delSelectedCards(const list<int>& seq){
    for (list<card_ptr>::iterator iter = lstCards.begin();
         iter != lstCards.end();) {
        if ((*iter)->isSelected()) {
            iter = lstCards.erase(iter);
            if (iter == lstCards.end()) {
                break;
            }
        }
        else
            iter++;
    }
}
