#include "Holding.hpp"

Holding::Holding(string nam, int typ)
{
    setName(nam);
    setUnTapped();
    setNotRevealded();
    upperHolding = NULL;
    subHolding = NULL;
    setCardType(typ);
    setDeSelected();
    switch(typ)
    {
        case(PLAIN): harvestValue = 2; setCost(2); break;
        case(MINE): harvestValue = 3; setCost(5); break;
        case(GOLD_MINE): harvestValue = 5; setCost(7); break;
        case(CRYSTAL_MINE): harvestValue = 6; setCost(12); break;
        case(FARMS): harvestValue = 4; setCost(3); break;
        case(SOLO): harvestValue = 2; setCost(2); break;
        case(STRONGHOLD): harvestValue = 5; setCost(0); break;
    }
}

void Holding::setHarvest(int a){harvestValue = a;}

int Holding::getType(){return HOLDING;}

void Holding::attachSubHolding(Holding* hol){subHolding = hol;}

void Holding::attachUpperHolding(Holding* hol){upperHolding = hol;}

void Holding::attachChain(Holding* ho)
{
    int t = this->getCardType();
    int h = ho->getCardType();
    switch(t)
    {
        case(MINE):if(h == GOLD_MINE)
                    {
                        if(!this->hasUpperHolding() && !ho->hasSubHolding())
                        {
                            this->attachUpperHolding(ho);
                            ho->attachSubHolding(this);
                            cout << "Chain completed!" << endl << endl;
                        }
                        else
                        {
                            if(this->hasUpperHolding())
                                cout << "This property already has an Upperholding!" << endl << endl;
                            if(ho->hasSubHolding())
                                cout << "The property you try to attach already has a Subholding!" << endl << endl;
                        }
                    }
                    else
                        cout << "You cannot attach this property to a Mine!" << endl << endl;
                break;
        case(CRYSTAL_MINE): if(h == GOLD_MINE)
                            {
                                if(!this->hasSubHolding() && !ho->hasUpperHolding())
                                {
                                    this->attachSubHolding(ho);
                                    ho->attachUpperHolding(this);
                                    cout << "Chain completed!" << endl << endl;
                                }
                                else
                                {
                                    if(this->hasSubHolding())
                                        cout << "This property already has an Upperholding!" << endl << endl;
                                    if(ho->hasUpperHolding())
                                        cout << "The property you try to attach already has a Subholding!" << endl << endl;
                                }
                            }
                            else
                                cout << "You cannot attach this property to a Crystal Mine!" << endl << endl;
                        break;
        case(GOLD_MINE):if(h == CRYSTAL_MINE || h == MINE)
                        {
                            if(h == CRYSTAL_MINE)
                            {
                                if(!this->hasUpperHolding() && !ho->hasSubHolding())
                                {
                                    this->attachUpperHolding(ho);
                                    ho->attachSubHolding(this);
                                    cout << "Chain completed!" << endl << endl;
                                }
                                else
                                {
                                    if(this->hasUpperHolding())
                                        cout << "This property already has an Upperholding!" << endl << endl;
                                    if(ho->hasSubHolding())
                                        cout << "The property you try to attach already has a Subholding!" << endl << endl;
                                }
                            }
                            if(h == MINE)
                            {
                                if(!this->hasSubHolding() && !ho->hasUpperHolding())
                                {
                                    this->attachSubHolding(ho);
                                    ho->attachUpperHolding(this);
                                    cout << "Chain completed!" << endl << endl;
                                }
                                else
                                {
                                    if(this->hasSubHolding())
                                        cout << "This property already has an Upperholding!" << endl << endl;
                                    if(ho->hasUpperHolding())
                                        cout << "The property you try to attach already has a Subholding!" << endl << endl;
                                }
                            }
                        }
                        else
                            cout << "You cannot attach this property to a Gold Mine!" << endl << endl;
                    break;
        default: cout << "You cannot attach other properties to this one!" << endl;
    }
}

bool Holding::hasSubHolding()
{
    if(subHolding)
        return true;
    else
        return false;
}

bool Holding::hasUpperHolding()
{
    if(upperHolding)
        return true;
    else
        return false;
}

int Holding::getHarvest()
{
    int harvest;
    switch(getCardType())
    {
        case(PLAIN):harvest = harvestValue; break;
        case(MINE):
            if(hasUpperHolding())
                harvest = (harvestValue+2);
            else
                harvest = harvestValue;
            break;
        case(GOLD_MINE):
            if(!hasSubHolding() && !hasUpperHolding())
                harvest = harvestValue;
            if(hasSubHolding() && !hasUpperHolding())
                harvest = harvestValue+4;
            if(!hasSubHolding() && hasUpperHolding())
                harvest = harvestValue+5;
            if(hasSubHolding() && hasUpperHolding())
                harvest = (harvestValue + harvestValue*2);
            break;
        case(CRYSTAL_MINE):
            if(subHolding)
            {
                if(subHolding->hasSubHolding())
                    harvest = harvestValue + harvestValue*3;
                else
                    harvest = harvestValue + harvestValue*2;
            }
            else
                harvest = harvestValue;
            break;
        case(FARMS): harvest = harvestValue; break;
        case(SOLO): harvest = harvestValue; break;
        case(STRONGHOLD): harvest = harvestValue; break;
    }
    return harvest;
}

void Holding::printCard()
{
    cout << "Name: " << getName() << endl;
    cout << "Type: ";
    printCardType();
    cout << "Cost: " << getCost() << endl;
    cout << "Original Harvest Value: " << harvestValue << endl;
    cout << "Harvest Value: " << getHarvest() << endl;
    if(!hasSubHolding() && !hasUpperHolding())
        cout << "Not attached to other properties" << endl;
    if(!hasSubHolding() && hasUpperHolding())
    {
        if(getCardType() == MINE && upperHolding->hasUpperHolding())
            cout << "Part of a full chain" << endl;
        else
            cout << "Has Upper Holding" << endl;
    }
    if(hasSubHolding() && !hasUpperHolding())
    {
        if(getCardType() == CRYSTAL_MINE && subHolding->hasSubHolding())
            cout << "Part of a full chain" << endl;
        else
            cout << "Has Subholding" << endl;
    }
    if(hasSubHolding() && hasUpperHolding())
        cout << "Part of a full chain" << endl;
    /*if(getRevealed()){cout << "Card is revealed!" << endl;}
    else{cout << "Card is not revealed" << endl;}*/
    if(getTapped())
        cout << "Card is tapped!"<< endl;
    else
        cout << "Card is not tapped!"<< endl;
}

void Holding::printCardType()
{
    switch(getCardType())
    {
        case(PLAIN): cout << "Plain" << endl; break;
        case(MINE): cout << "Mine" << endl; break;
        case(GOLD_MINE): cout << "Gold Mine" << endl; break;
        case(CRYSTAL_MINE): cout << "Crystal Mine" << endl; break;
        case(FARMS): cout << "Farmlands" << endl; break;
        case(SOLO): cout << "Gifts & Favors" << endl; break;
        case(STRONGHOLD): cout << "Atakebune" << endl; break;
    }
}

int Holding::getOriginalHarvestValue(){return harvestValue;}

bool Holding::canBeAdded()
{
    if(getCardType() == MINE && !hasUpperHolding())
        return true;
    if(getCardType() == GOLD_MINE && (!hasUpperHolding() || !hasSubHolding()))
        return true;
    if(getCardType() == CRYSTAL_MINE && !hasSubHolding())
        return true;
    return false;
}
