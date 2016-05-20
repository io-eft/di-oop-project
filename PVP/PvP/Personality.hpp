#ifndef __PERSONALITY__HPP
#define __PERSONALITY__HPP
#include "BlackCard.hpp"
#include "Item.hpp"
#include "Follower.hpp"
#include <vector>

enum{ATTACKER=1, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};

class Personality;

class Personality: public BlackCard
{
    int attack;
    int defense;
    int honour;
    bool isDead;
    unsigned int maxfollowers;
    unsigned int maxitems;
    vector<Follower*> fol;
    vector<Item*> ite;

    public:
    Personality(string nam, int typ);
    ~Personality(){}

    void setAttack(int a);
    void setDefense(int a);
    void setHonour(int a);
    void setIsDead();
    void setIsNotDead();
    void setMaxFollowers(unsigned int a);
    void setMaxItems(unsigned int a);
    void setTapped();
    void setUnTapped();

    int getAttack();
    int getDefense();
    int getHonour();
    bool getIsDead();
    int getType();
    unsigned int getMaxFollowers();
    unsigned int getMaxItems();

    int getCombinedAttack();
    int getCombinedDefense();

    void printCardType();
    void printCard();
    void printArmyCard();

    int numberOfFollowers();
    int numberOfItems();
    void attach(Item* i);
    void attach(Follower* f);
    bool hasFreeSpace();
    bool hasItemSpace();
    bool hasFollowerSpace();
    int getItemSpace();
    int getItemAmount();
    int getFollowerSpace();
    int getFollowerAmount();
    bool hasItems();
    bool hasFollowers();
    bool hasAttachments();

    bool canAttach(Item* i);
    bool canAttach(Follower* f);
    void detach();
    void offensiveAftermath();
    int pickOffensiveFollower();
    int pickDefensiveFollower();
    int pickOffensiveItem();
    int pickDefensiveItem();

    void performSeppuku();
    void discardProperty();
};

#endif
