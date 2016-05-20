#ifndef __CARD__HPP
#define __CARD__HPP
#include <iostream>

enum{PERSONALITY=1,HOLDING,FOLLOWER,ITEM};

using namespace std;

class Card
{
    string name;
    int cost;
    bool isTapped;
    int cardType;
    bool selected;

    public:
    Card();
    virtual ~Card();
    void setName(string nam);
    void setCost(int cos);
    virtual void setTapped();
    virtual void setUnTapped();
    void setCardType(int t);
    void setSelected();
    void setDeSelected();

    string getName();
    int getCost();
    bool getTapped();
    int getCardType();
    bool getSelected();
    virtual void printCard() = 0;
    virtual int getType() = 0;
    virtual void printCardType() = 0;
};

#endif


