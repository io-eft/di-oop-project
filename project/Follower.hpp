#ifndef __FOLLOWER__HPP
#define __FOLLOWER__HPP
#include "GreenCard.hpp"

enum{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};

class Personality;

class Follower: public GreenCard
{
    bool isDead;

    public:
    Follower(string nam, int typ);
    ~Follower(){}
    void setIsDead();
    void setIsNotDead();

    int getType();
    bool getIsDead();

    void printCard();
    void printCardType();
    void printAttachedCard();
};

#endif
