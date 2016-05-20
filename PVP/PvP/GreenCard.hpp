#ifndef __GREENCARD__HPP
#define __GREENCARD__HPP
#include "Card.hpp"
#include <sstream>

class GreenCard: public Card
{
    int attackBonus;
    int defenseBonus;
    int minimumHonour;
    string cardText;
    int effectBonus;
    int effectCost;
    bool bonusCondition;

    public:
    ~GreenCard(){}
    void setAttackBonus(int a);
    void setDefenseBonus(int a);
    void setMinimumHonour(int a);
    void setCardText(string s);
    void activateBonusCondition();
    void DeactivateBonusCondition();
    void setEffectBonus(int a);
    void setEffectCost(int a);

    int getAttackBonus();
    int getDefenseBonus();
    int getMinimumHonour();
    string getCardText();
    int getEffectBonus();
    int getEffectCost();
    bool getBonusCondition();

    void printCost();
    bool purchaseBonus();
    int getHandCost();
    int getType() = 0;
    virtual void printAttachedCard() = 0;
};
#endif

