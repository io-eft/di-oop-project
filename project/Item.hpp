#ifndef __ITEM__HPP
#define __ITEM__HPP
#include "GreenCard.hpp"

enum{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};

class Personality;

class Item: public GreenCard
{
    int durability;

    public:
    Item(string nam, int typ);
    ~Item(){}

    void setDurability(int a);

    int getDurability();
    void reduceDurability();

    int getType();
    void printCard();
    void printCardType();
    void printAttachedCard();
};

#endif
