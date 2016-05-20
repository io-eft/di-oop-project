#include "StrongHold.hpp"

StrongHold::StrongHold()
{
    int j;
    j = (rand()%7) + 1;
    ;
    switch(j)
    {
        case(1):
        case(6):
        case(2):
        case(5): j = 5; break;
        case(4): j = 4; break;
        case(3): j = 3; break;
        case(7): j = 7; break;
    }
    hold = new Holding("Stronghold", j);
    stronghold_type = j;
    switch(j)
    {
        case(1): honour = 4; money = hold->getOriginalHarvestValue(); initialDefense = 3; text = "A plain field"; break;
        case(2): honour = 3; money = hold->getOriginalHarvestValue(); initialDefense = 3; text = "A simle mine"; break;
        case(3): honour = 3; money = hold->getOriginalHarvestValue(); initialDefense = 4; text = "A gold mine"; break;
        case(4): honour = 4; money = hold->getOriginalHarvestValue(); initialDefense = 3; text = "A crystal mine"; break;
        case(5): honour = 5; money = hold->getOriginalHarvestValue(); initialDefense = 4; text = "A rich farm"; break;
        case(6): honour = 3; money = hold->getOriginalHarvestValue(); initialDefense = 4; text = "Gift and favour"; break;
        case(7): honour = 7; money = hold->getOriginalHarvestValue(); initialDefense = 5; text = "A solid stronghold"; break;
    }
}

StrongHold::~StrongHold()
{
    //delete hold;
}

void StrongHold::setHonour(int a){honour = a;}

void StrongHold::setMoney(int a){money = a;}

void StrongHold::setInitialDefense(int a){initialDefense = a;}

void StrongHold::setText(string s){text = s;}

void StrongHold::setStrongHoldType(int a){stronghold_type = a;}

int StrongHold::getHonour(){return honour;}

int StrongHold::getMoney(){return money;}

int StrongHold::getInitialDefense(){return initialDefense;}

string StrongHold::getText(){return text;}

int StrongHold::getStrongHoldType(){return stronghold_type;}

void StrongHold::printStrongHoldType()
{
    switch(stronghold_type)
    {
        case(1): cout << "Plain" << endl; break;
        case(2): cout << "Mine" << endl; break;
        case(3): cout << "Gold Mine" << endl; break;
        case(4): cout << "Crystal Mine" << endl; break;
        case(5): cout << "Farmlands" << endl; break;
        case(6): cout << "Gifts & Favors" << endl; break;
        case(7): cout << "Atakebune" << endl; break;
    }
}

void StrongHold::printStrongHold()
{
    cout << "Type: ";
    hold->printCardType();
    cout << "Honour: " << honour << endl;
    cout << "Money: " << money << endl;
    cout << "Initial Defense: " << initialDefense << endl;
    cout << text << endl;
}

Holding* StrongHold::getStrongHold(){return hold;}
