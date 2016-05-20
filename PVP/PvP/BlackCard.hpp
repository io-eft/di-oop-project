#ifndef __BLACKCARD__HPP
#define __BLACKCARD__HPP
#include "Card.hpp"

class BlackCard: public Card
{
    bool isRevealed;

    public:
    ~BlackCard(){}
    void setRevealed();
    void setNotRevealded();

    bool getRevealed();
    int getType() = 0;
};

#endif
