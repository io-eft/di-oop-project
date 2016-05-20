#include "Item.hpp"

Item::Item(string nam, int typ)
{
    setName(nam);
    setUnTapped();
    DeactivateBonusCondition();
    setCardType(typ);
    setDeSelected();
    switch(typ)
    {
        case(KATANA): setCost(5); setAttackBonus(3); setDefenseBonus(3); setMinimumHonour(1); setEffectBonus(5); setEffectCost(6); durability = 4; setCardText("A Katana");break;
        case(SPEAR): setCost(5); setAttackBonus(2); setDefenseBonus(2); setMinimumHonour(1); setEffectBonus(4); setEffectCost(6); durability = 4; setCardText("A Spear");break;
        case(BOW): setCost(10); setAttackBonus(4); setDefenseBonus(4); setMinimumHonour(2); setEffectBonus(4); setEffectCost(10); durability = 6; setCardText("A Bow");break;
        case(NINJATO): setCost(15); setAttackBonus(6); setDefenseBonus(6); setMinimumHonour(3); setEffectBonus(6); setEffectCost(10); durability = 8; setCardText("A Ninjato");break;
        case(WAKIZASHI): setCost(20); setAttackBonus(8); setDefenseBonus(8); setMinimumHonour(6); setEffectBonus(8); setEffectCost(15); durability = 10; setCardText("A Wakizashi");break;
    }
}

void Item::setDurability(int a){durability = a;}

int Item::getDurability(){return durability;}

void Item::reduceDurability(){durability--;}

int Item::getType(){return ITEM;}

void Item::printCard()
{
    cout << "Name: " << getName() << endl;
    cout << "Type: ";
    printCardType();
    cout << "Attack Bonus: " << getAttackBonus() << endl;
    cout << "Defense Bonus: " << getDefenseBonus() << endl;
    cout << "Minimum Honour: " << getMinimumHonour() << endl;
    cout << "Effect Bonus: " << getEffectBonus() << endl;
    printCost();
    cout << "Durability: " << durability << endl;
    if(getBonusCondition()){cout << "Effect Bonus is active" << endl;}
    else{cout << "Effect Bonus is not active" << endl;}
    cout << getCardText() << endl;
    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
}

void Item::printCardType()
{
    switch(getCardType())
    {
        case(KATANA): cout << "Katana" << endl; break;
        case(SPEAR): cout << "Spear" << endl; break;
        case(BOW): cout << "Bow" << endl; break;
        case(NINJATO): cout << "Ninjato" << endl; break;
        case(WAKIZASHI): cout << "Wakizashi" << endl; break;
    }
}

void Item::printAttachedCard()
{
    cout << "Name: " << getName() << endl;
    cout << "Type: ";
    cout << "Attack Bonus: " << getAttackBonus() << endl;
    cout << "Defense Bonus: " << getDefenseBonus() << endl;
    cout << "Effect Bonus: " << getEffectBonus();
    if(!getBonusCondition())
        cout << " (Not Activated)";
    cout << endl;
    cout << "Durability: " << durability << endl;
/*    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;*/
    cout << "+" << endl;
}
