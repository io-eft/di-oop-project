#include "Follower.hpp"

Follower::Follower(string nam, int typ)
{
    isDead = false;
    setName(nam);
    setUnTapped();
    DeactivateBonusCondition();
    setCardType(typ);
    setDeSelected();
    switch(typ)
    {
        case(0): setCost(0); setAttackBonus(2); setDefenseBonus(0); setMinimumHonour(1); setEffectBonus(1); setEffectCost(2); setCardText("A breave footsoldier");break;
        case(1): setCost(0); setAttackBonus(0); setDefenseBonus(2); setMinimumHonour(1); setEffectBonus(1); setEffectCost(2); setCardText("A deadly archer");break;
        case(2): setCost(5); setAttackBonus(3); setDefenseBonus(3); setMinimumHonour(2); setEffectBonus(2); setEffectCost(3); setCardText("A powerful sieger");break;
        case(3): setCost(3); setAttackBonus(4); setDefenseBonus(2); setMinimumHonour(3); setEffectBonus(3); setEffectCost(4); setCardText("A highly mobile unit");break;
        case(4): setCost(3); setAttackBonus(2); setDefenseBonus(4); setMinimumHonour(3); setEffectBonus(3); setEffectCost(4); setCardText("A naval unit");break;
        case(5): setCost(8); setAttackBonus(8); setDefenseBonus(8); setMinimumHonour(6); setEffectBonus(3); setEffectCost(8); setCardText("A deadly bushido warrior");break;
    }
}

void Follower::setIsDead(){isDead = true;}

void Follower::setIsNotDead(){isDead = false;}

int Follower::getType(){return FOLLOWER;}

bool Follower::getIsDead(){return isDead;}

void Follower::printCard()
{
    cout << "Name: " << getName() << endl;
    cout <<"Profession: ";
    printCardType();
    cout << "Attack Bonus: " << getAttackBonus() << endl;
    cout << "Defense Bonus: " << getDefenseBonus() << endl;
    cout << "Minimum Honour: " << getMinimumHonour() << endl;
    cout << "Effect Bonus: " << getEffectBonus() << endl;
    cout << "Effect Cost: " << getEffectCost() << endl;
    if(getBonusCondition())
        cout << "Effect Bonus is active" << endl;
    else
        cout << "Effect Bonus is not active" << endl;
    cout << getCardText() << endl;
    printCost();
    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
}

void Follower::printCardType()
{
    switch(getCardType())
    {

        case(0): cout << "Footsoldier" << endl; break;
        case(1): cout << "Archer" << endl; break;
        case(2): cout << "Sieger" << endl; break;
        case(3): cout << "Cavalry" << endl; break;
        case(4): cout << "Atakebune" << endl; break;
        case(5): cout << "Bushido" << endl; break;
    }
}

void Follower::printAttachedCard()
{
    cout << "Name: " << getName() << endl;
    cout <<"Profession: ";
    printCardType();
    cout << "Attack Bonus: " << getAttackBonus() << endl;
    cout << "Defense Bonus: " << getDefenseBonus() << endl;
    cout << "Effect Bonus: " << getEffectBonus();
    if(!getBonusCondition())
        cout << " (Not Activated)";
    cout << endl;
 /*   if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
    cout << "+" << endl;*/
}
