#include "Personality.hpp"

Personality::Personality(string nam, int typ)
{
    setName(nam);
    setUnTapped();
    isDead = false;
    setNotRevealded();
    setCardType(typ);
    setDeSelected();
    switch(typ)
    {
        case(ATTACKER): attack = 3; defense = 2; honour = 2; maxfollowers = 1; maxitems = 2; setCost(5); break;
        case(DEFENDER): attack = 2; defense = 3; honour = 2; maxfollowers = 2; maxitems = 1; setCost(5); break;
        case(SHOGUN): attack = 10; defense = 5; honour = 8; maxfollowers = 3; maxitems = 2; setCost(15); break;
        case(CHANCELLOR): attack = 5; defense = 10; honour = 8; maxfollowers = 2; maxitems = 3;setCost(15); break;
        case(CHAMPION): attack = 20; defense = 20; honour = 12; maxfollowers = 3; maxitems = 3; setCost(30); break;
    }
}

void Personality::printCard()
{
    cout << "Name: " << getName() << endl;
    cout << "Class: ";
    printCardType();
    cout << "Cost: " << getCost() << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Honour: " << honour << endl;
    cout << "Available Item slots: " << maxitems - ite.size() << endl;
    cout << "Available Follower slots: " << maxfollowers - fol.size() << endl;
    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
    if(ite.empty())
        cout << "Has no items equipted!" << endl;
    else
    {
        cout << "Has " << ite.size() << " item(s) equipted, the following:" << endl;
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            cout << i+1 << ".";
            ite.at(i)->printAttachedCard();
        }
    }
    if(fol.empty())
        cout << "Has no followers!" << endl;
    else
    {
        cout << "Has " << fol.size() << " follower(s), the following:" << endl;
        for(unsigned int i = 0; i < fol.size(); i++)
        {
            cout << i+1 << ".";
            fol.at(i)->printAttachedCard();
        }
    }
/*    if(isDead){cout << "Hero is dead!" << endl;}
    else{cout << "Hero is alive!"<< endl;}*/
}

void Personality::printArmyCard()
{
    cout << "Name: " << getName() << endl;
    cout << "Class: ";
    printCardType();
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Honour: " << honour << endl;
    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
    if(ite.empty())
        cout << "Has no items equipted!" << endl;
    else
    {
        if(ite.size() == 1)
            cout << "Has 1 item equipted, the following:" << endl;
        else
            cout << "Has " << ite.size() << " items equipted, the following:" << endl;
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            cout << i+1 << ".";
            ite.at(i)->printAttachedCard();
        }
    }
    if(fol.empty())
        cout << "Has no followers!" << endl;
    else
    {
        if(fol.size() == 1)
            cout << "Has 1 follower, the following:" << endl;
        else
            cout << "Has " << fol.size() << " followers, the following:" << endl;
        for(unsigned int i = 0; i < fol.size(); i++)
        {
            cout << i+1 << ".";
            fol.at(i)->printAttachedCard();
                        if(fol.at(i)->getIsDead()){cout << "Hero is dead!" << endl;}
                else{cout << "Hero is alive!"<< endl;}
        }
    }
    cout << "Combined Attack: " << getCombinedAttack() << endl;
    cout << "Combined Defense: " << getCombinedDefense() << endl;
    cout << endl;
}
void Personality::performSeppuku()
{
    isDead = true;
    discardProperty();
}

int Personality::getType(){return PERSONALITY;}

int Personality::numberOfFollowers(){return fol.size();}

int Personality::numberOfItems(){return ite.size();}

void Personality::printCardType()
{
    switch(getCardType())
    {
        case(ATTACKER): cout << "Attacker" << endl; break;
        case(DEFENDER): cout << "Defender" << endl; break;
        case(SHOGUN): cout << "Shogun" << endl; break;
        case(CHANCELLOR): cout << "Chancellor" << endl; break;
        case(CHAMPION): cout << "Champion" << endl; break;
    }
}

void Personality::attach(Item* i)
{
    if(ite.size() < maxitems)
        ite.push_back(i);
}

void Personality::attach(Follower* f)
{
    if(fol.size() < maxfollowers)
        fol.push_back(f);
}

void Personality::setAttack(int a){attack = a;}

void Personality::setDefense(int a){defense = a;}

void Personality::setHonour(int a){honour = a;}

void Personality::setIsDead()
{
    isDead = true;
    discardProperty();
}

void Personality::setIsNotDead(){isDead = false;}

void Personality::setMaxFollowers(unsigned int a){maxfollowers = a;}

void Personality::setMaxItems(unsigned int a){maxitems = a;}

void Personality::setUnTapped()
{
    Card::setUnTapped();
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < fol.size(); i++)
            fol.at(i)->setUnTapped();
    }
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
            ite.at(i)->setUnTapped();
    }
}

void Personality::setTapped()
{
    Card::setTapped();
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < fol.size(); i++)
            fol.at(i)->setTapped();
    }
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
            ite.at(i)->setTapped();
    }
}

int Personality::getAttack(){return attack;}

int Personality::getDefense(){return defense;}

int Personality::getHonour(){return honour;}

bool Personality::getIsDead(){return isDead;}

unsigned int Personality::getMaxFollowers(){return maxfollowers;}

unsigned int Personality::getMaxItems(){return maxitems;}

bool Personality::hasFreeSpace()
{
    if(maxitems - ite.size() > 0 || maxfollowers - fol.size() > 0)
        return true;
    else
        return false;
}

bool Personality::hasItemSpace()
{
    if(maxitems - ite.size() > 0)
        return true;
    else
        return false;
}

bool Personality::hasFollowerSpace()
{
    if(maxfollowers - fol.size() > 0)
        return true;
    else
        return false;
}

int Personality::getItemSpace(){return maxitems - ite.size();}

int Personality::getFollowerSpace(){return maxfollowers - fol.size();}

bool Personality::canAttach(Item* i)
{
    if(hasItemSpace() && i->getMinimumHonour() <= honour)
        return true;
    else
        return false;
}

bool Personality::canAttach(Follower* f)
{
    if(hasFollowerSpace() && f->getMinimumHonour() <= honour)
        return true;
    else
        return false;
}

int Personality::getItemAmount(){return ite.size();}

int Personality::getFollowerAmount(){return fol.size();}

bool Personality::hasItems()
{
    if(!ite.empty())
        return true;
    else
        return false;
}

bool Personality::hasFollowers()
{
    if(!fol.empty())
        return true;
    else
        return false;
}

bool Personality::hasAttachments()
{
    if(!ite.empty() || !fol.empty())
        return true;
    else
        return false;
}

void Personality::discardProperty()
{
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            delete ite.at(i);
        }
        fol.clear();
    }
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            delete fol.at(i);
        }
        ite.clear();
    }
}

void Personality::detach()
{
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            if(!ite.at(i)->getDurability())
            {
                delete ite.at(i);
                ite.erase(ite.begin()+i);
                i--;
            }

        }
    }
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < fol.size(); i++)
        {
            if(!fol.at(i)->getIsDead())
            {
                delete fol.at(i);
                fol.erase(fol.begin()+i);
                i--;
            }
        }
    }
}

int Personality::getCombinedAttack()
{
    int atk = attack;
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            if(ite.at(i)->getBonusCondition())
                atk = atk + ite.at(i)->getAttackBonus() + ite.at(i)->getEffectBonus();
            else
                atk = atk + ite.at(i)->getAttackBonus();
        }
    }
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < fol.size(); i++)
        {
            if(fol.at(i)->getBonusCondition())
                atk = atk + fol.at(i)->getAttackBonus() + fol.at(i)->getEffectBonus();
            else
                atk = atk + fol.at(i)->getAttackBonus();
        }
    }
    return atk;
}

int Personality::getCombinedDefense()
{
    int def = defense;
    if(!ite.empty())
    {
        for(unsigned int i = 0; i < ite.size(); i++)
        {
            if(ite.at(i)->getBonusCondition())
                def = def + ite.at(i)->getDefenseBonus() + ite.at(i)->getEffectBonus();
            else
                def = def + ite.at(i)->getDefenseBonus();
        }
    }
    if(!fol.empty())
    {
        for(unsigned int i = 0; i < fol.size(); i++)
        {
            if(fol.at(i)->getBonusCondition())
                def = def + fol.at(i)->getDefenseBonus() + fol.at(i)->getEffectBonus();
            else
                def = def + fol.at(i)->getDefenseBonus();
        }
    }
    return def;
}

void Personality::offensiveAftermath()
{
    if(!getIsDead())
    {
        honour--;
        if(honour == 0)
            performSeppuku();
        for(unsigned int i = 0; i < ite.size(); i++)
            ite.at(i)->reduceDurability();
        detach();
    }
}

int Personality::pickOffensiveFollower()
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    for(unsigned int i = 0; i < fol.size(); i++)
        if(!fol.at(i)->getIsDead())
        {
            cout << "Follower: " << i+1 << endl;
            fol.at(i)->printAttachedCard();
            cout << endl;
        }
    cout << "Please pick the number you wish to discard:" << endl;
    cout << "(Use 0 to cancel and return to previous menu.)" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= fol.size())
        {
            if(a)
            {
                if(!fol.at(a-1)->getIsDead())
                    break;
            }
            else
                break;
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
    if(a)
    {
        fol.at(a-1)->setIsDead();
        if(fol.at(a-1)->getBonusCondition())
            amount = fol.at(a-1)->getAttackBonus() + fol.at(a-1)->getEffectBonus();
        else
            amount = fol.at(a-1)->getAttackBonus();
    }
    detach();
    return amount;
}

int Personality::pickOffensiveItem()
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    for(unsigned int i = 0; i < ite.size(); i++)
        if(!ite.at(i)->getDurability())
        {
            cout << "Item: " << i+1 << endl;
            ite.at(i)->printAttachedCard();
            cout << endl;
        }
    cout << "Please pick the number you wish to discard:" << endl;
    cout << "(Use 0 to cancel and return to previous menu.)" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= ite.size())
        {
            if(a)
            {
                if(!ite.at(a-1)->getDurability())
                    break;
            }
            else
                break;
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
    if(a)
    {
        ite.at(a-1)->setDurability(0);
        if(fol.at(a-1)->getBonusCondition())
            amount = ite.at(a-1)->getAttackBonus() + ite.at(a-1)->getEffectBonus();
        else
            amount = ite.at(a-1)->getAttackBonus();
    }
    detach();
    return amount;
}

int Personality::pickDefensiveFollower()
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    for(unsigned int i = 0; i < fol.size(); i++)
        if(!fol.at(i)->getIsDead())
        {
            cout << "Follower: " << i+1 << endl;
            fol.at(i)->printAttachedCard();
            cout << endl;
        }
    cout << "Please pick the number you wish to discard:" << endl;
    cout << "(Use 0 to cancel and return to previous menu.)" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= fol.size())
        {
            if(a)
            {
                if(!fol.at(a-1)->getIsDead())
                    break;
            }
            else
                break;
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
    if(a)
    {
        fol.at(a-1)->setIsDead();
        if(fol.at(a-1)->getBonusCondition())
            amount = fol.at(a-1)->getDefenseBonus() + fol.at(a-1)->getEffectBonus();
        else
            amount = fol.at(a-1)->getDefenseBonus();
    }
    detach();
    return amount;
}

int Personality::pickDefensiveItem()
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    for(unsigned int i = 0; i < ite.size(); i++)
        if(!ite.at(i)->getDurability())
        {
            cout << "Item: " << i+1 << endl;
            ite.at(i)->printAttachedCard();
            cout << endl;
        }
    cout << "Please pick the number you wish to discard:" << endl;
    cout << "(Use 0 to cancel and return to previous menu.)" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= ite.size())
        {
            if(a)
            {
                if(!ite.at(a-1)->getDurability())
                    break;
            }
            else
                break;
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
    if(a)
    {
        ite.at(a-1)->setDurability(0);
        if(fol.at(a-1)->getBonusCondition())
            amount = ite.at(a-1)->getDefenseBonus() + ite.at(a-1)->getEffectBonus();
        else
            amount = ite.at(a-1)->getDefenseBonus();
    }
    detach();
    return amount;
}
