//
//  CCard.h
//  redten
//
//  Created by zcw on 15-4-9.
//
//

#ifndef __redten__CCard__
#define __redten__CCard__
#include <memory>
#include <mutex>
using namespace std;

class CCard
{
    std::mutex  _mutex;

protected:
    int     _cardSeq;
    bool    _bSelected;

public:
    CCard();
    virtual ~CCard();
    
    void    setSeq(int seq);
    int     getSeq();
    void    setSelected(bool bStatus);
    bool    isSelected();
};

typedef shared_ptr<CCard>   card_ptr;

#endif /* defined(__redten__CCard__) */
