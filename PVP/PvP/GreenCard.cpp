#include "GreenCard.hpp"

void GreenCard::setAttackBonus(int a){attackBonus = a;}

void GreenCard::setDefenseBonus(int a){defenseBonus = a;}

void GreenCard::setMinimumHonour(int a){minimumHonour = a;}

void GreenCard::setCardText(string s){cardText = s;}

void GreenCard::activateBonusCondition(){bonusCondition = true;}

void GreenCard::DeactivateBonusCondition(){bonusCondition = false;}

void GreenCard::setEffectBonus(int a){effectBonus = a;}

void GreenCard::setEffectCost(int a){effectCost = a;}

int GreenCard::getAttackBonus(){return attackBonus;}

int GreenCard::getDefenseBonus(){return defenseBonus;}

int GreenCard::getMinimumHonour(){return minimumHonour;}

string GreenCard::getCardText(){return cardText;}

int GreenCard::getEffectBonus(){return effectBonus;}

bool GreenCard::getBonusCondition(){return bonusCondition;}

int GreenCard::getEffectCost(){return effectCost;}

void GreenCard::printCost()
{
    cout << "Cost: " << getCost() << endl;
    cout << "Cost with bonus is: " << getCost() << " + " << effectCost << " = " << getCost() + effectCost << endl;
}

bool GreenCard::purchaseBonus()
{
    unsigned int a = 0;
    string input = "";
    cout << "Would you like to enable the bonus effect? You can't do that later, it's your only chance!" << endl;
    cout << "Please enter 0 for No, 1 for Yes" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && (a == 0 || a ==1) )
        {
            if(a)
            {
                setSelected();
                return true;
            }
            else
                return false;
        }
    cout << "Wrong input, please try again!" << endl << endl;
    }
}

int GreenCard::getHandCost()
{
    if(purchaseBonus())
        return (getCost() + effectCost);
    else
        return getCost();
}
