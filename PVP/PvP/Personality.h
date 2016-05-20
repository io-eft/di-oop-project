#ifndef __PERSONALITY__H
#define __PERSONALITY__H

enum{ATTACKER=1, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};

class Personality: public BlackCard
{
    int attack;
    int defense;
    int honour;
    bool isDead;
    Follower* fol[NO_FOLLOWERS];
    Item* ite[NO_ITEMS];

    public:
    Personality(string nam, int typ);
    void printCard();
};
