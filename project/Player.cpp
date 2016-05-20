#include "Player.hpp"
#include "TypeConverter.hpp"
#include <list>
#include <vector>

using namespace std;

Player::Player(string s)
{
    name = s;
    strength = 0;
    money = strong.getMoney();
    honour = strong.getHonour();
    initialDefense = strong.getInitialDefense();
    numberOfProvinces = NUMBER_OF_PROVINCES;
    DeckBuilder mydeck;
    fateDeck = mydeck.createFateDeck();
    dynastyDeck = mydeck.createDynastyDeck();
    mydeck.deckShuffler(fateDeck);
    mydeck.deckShuffler(dynastyDeck);
    for(int i = 0; i < numberOfProvinces; i++)
    {
        provinces.push_back(dynastyDeck->front());
        dynastyDeck->pop_front();
    }
    for(int i = 0; i < STARTING_HAND_AMOUNT; i++)
    {
        hand.push_back(fateDeck->front());
        fateDeck->pop_front();
    }
    holdings.push_back(strong.getStrongHold());
}

Player::~Player()
{
    discardEverything();
    for(unsigned int i = 0; i < discardedCards.size(); i++)
    {
        delete discardedCards.at(i);
    }
}

void Player::setMoney(int a){money = a;}

void Player::setInitialDefense(int a){initialDefense = a;}

void Player::setHonour(int a){honour = a;}

void Player::setNumberOfProvinces(int a){numberOfProvinces = a;}

void Player::setStrength(int a){strength = a;}

void Player::setName(string s){name = s;}

int Player::getMoney(){return money;}

int Player::getInitialDefense(){return initialDefense;}

int Player::getHonour(){return honour;}

int Player::getNumberOfProvinces(){return numberOfProvinces;}

int Player::getStrength(){return strength;}

string Player::getName(){return name;}

int Player::getHandSize(){return hand.size();}

void Player::drawFateCard()
{
    if(fateDeck->empty())
        cout << "Fate Deck is empty!" << endl;
    else
    {
        hand.push_back(fateDeck->front());
        fateDeck->pop_front();
    }
}

void Player::drawDynastyCard()
{
    if(fateDeck->empty())
        cout << "Dynasty Deck is empty!" << endl;
    else
    {
        provinces.push_back(dynastyDeck->front());
        dynastyDeck->pop_front();
    }
}

void Player::unTapEverything()
{
    if(!provinces.empty())
    {
        for(unsigned int i = 0; i < provinces.size(); i++)
        {
            provinces.at(i)->setUnTapped();
        }
    }
    if(!hand.empty())
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            hand.at(i)->setUnTapped();
        }
    }
    if(!army.empty())
    {
        for(unsigned int i = 0; i < army.size(); i++)
        {
            army.at(i)->setUnTapped();
        }
    }
    if(!holdings.empty())
    {
        for(unsigned int i = 0; i < holdings.size(); i++)
        {
            holdings.at(i)->setUnTapped();
        }
    }
}

void Player::deSelectEverything()
{
    if(!provinces.empty())
    {
        for(unsigned int i = 0; i < provinces.size(); i++)
        {
            provinces.at(i)->setDeSelected();
        }
    }
    if(!hand.empty())
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            hand.at(i)->setDeSelected();
        }
    }
    if(!army.empty())
    {
        for(unsigned int i = 0; i < army.size(); i++)
        {
            army.at(i)->setDeSelected();
        }
    }
    if(!holdings.empty())
    {
        for(unsigned int i = 0; i < holdings.size(); i++)
        {
            holdings.at(i)->setDeSelected();
        }
    }
}

void Player::revealProvinces()
{
    if(!provinces.empty())
    {
        for(unsigned int i = 0; i < provinces.size(); i++)
        {
            provinces.at(i)->setRevealed();
        }
    }
}

void Player::printHand()
{
    if(!hand.empty())
    {
        cout << name << "'s hand is: " << endl << endl;
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            cout << "Hand: " << i+1 << endl;
            hand.at(i)->printCard();
            cout << "---" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << getName() << "'s Hand is empty" << endl << endl;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printProvinces()
{
    if(!provinces.empty())
    {
        cout << name << "'s provinces are: " << endl << endl;
        for(unsigned int i = 0; i < provinces.size(); i++)
        {
            cout << "Province: " << i+1 << endl;
            if(provinces.at(i)->getRevealed())
            {
                provinces.at(i)->printCard();
            }
            else{cout << "Province not yet revealed!" << endl;}
            cout << "---" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << getName() << " has no Provinces left!" << endl << endl;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printSelectedProvince()
{
    for(unsigned int i = 0; i < provinces.size(); i++)
    {
        if(provinces.at(i)->getSelected())
            provinces.at(i)->printCard();
    }
}

void Player::printHoldings()
{
    if(!holdings.empty())
    {
        cout << name << "'s holdings are: " << endl << endl;
        for(unsigned int i = 0; i < holdings.size(); i++)
        {
            cout << "Holding: " << i+1 << endl;
            holdings.at(i)->printCard();
            cout << "---" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << getName() << " has no Holdings!" << endl << endl;;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printArena()
{
    if(!army.empty())
    {
        cout << name << "'s army is: " << endl << endl;
        for(unsigned int i = 0; i < army.size(); i++)
        {
            cout << "Army: " << i+1 << endl;
            army.at(i)->printCard();
            cout << "---" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << getName() << " has no Army!" << endl << endl;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printPlayer()
{
    cout << "Player Name: " << name << endl;
    cout << "Amount of Money: " << money << endl;
    cout << "Honour: " << honour << endl;
    cout << "Defense: " << initialDefense << endl;
    cout << "Stronghold: ";
    strong.printStrongHoldType();
    cout << "Number of Provinces: " << numberOfProvinces << endl;
    cout << "Cards on Hand: " << hand.size() << endl;
    cout << "Army size: " << army.size() << endl;
    cout << "Number of Holdings: " << holdings.size() << endl;
    cout << "---" << endl;
    cout << endl;
}

void Player::discardSurplusFateCards()
{
    int amount =  hand.size() - MAX_HAND_AMOUNT;
    for(int i = 0; i < amount;  i++)
    {
        unsigned int a = 0;
        string input = "";
        printHand();
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Please select the number of the card you want to discard:" << endl;
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= hand.size() && a)
            {
                break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
        discardedCards.push_back(hand.at(a-1));
        hand.erase(hand.begin()+(a-1));
    }
}

int Player::getFateDeckSize(){return fateDeck->size();}

int Player::getDynastyDeckSize(){return dynastyDeck->size();}

void Player::printName(){cout << name;}

void Player::discardEverything()
{
    if(!hand.empty())
    {
        for(unsigned int i = 0; i < hand.size(); i++)
        {
            discardedCards.push_back(hand.at(i));
        }
        hand.clear();
    }
    if(!provinces.empty())
    {
        for(unsigned int i = 0; i < provinces.size(); i++)
        {
            discardedCards.push_back(provinces.at(i));
        }
        provinces.clear();
    }
    if(!holdings.empty())
    {
        for(unsigned int i = 0; i < holdings.size(); i++)
        {
            discardedCards.push_back(holdings.at(i));
        }
        holdings.clear();
    }
    if(!army.empty())
    {
        for(unsigned int i = 0; i < army.size(); i++)
        {
            army.at(i)->discardProperty();
            discardedCards.push_back(army.at(i));
        }
        army.clear();
    }
    if(!fateDeck->empty())
    {
        unsigned int j = fateDeck->size();
        for( unsigned int i = 0; i < j; i++)
        {
            discardedCards.push_back(fateDeck->front());
            fateDeck->pop_front();
        }
    }
    if(!dynastyDeck->empty())
    {
        unsigned int j = dynastyDeck->size();
        for( unsigned int i = 0; i < j; i++)
        {
            discardedCards.push_back(dynastyDeck->front());
            dynastyDeck->pop_front();
        }
    }
}

bool Player::hasArmy(){return !army.empty();}

bool Player::hasSelectedArmy(){return !selectedArmy.empty();}

void Player::replaceProvince()
{
    if(!dynastyDeck->empty())
    {
        unsigned int a = 0;
        string input = "";
        printProvinces();
        cout << "Please select the number of the province you want to replace:" << endl;
        cout << "(Use 0 to cancel and return to previous menu.)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= provinces.size())
                break;
            cout << "Wrong input, please try again!" << endl << endl;
        }
        if(a)
        {
            if(verifyPurchase())
            {
                discardedCards.push_back(provinces.at(a-1));
                provinces.erase(provinces.begin()+(a-1));
                provinces.push_back(dynastyDeck->front());
                dynastyDeck->pop_front();
                cout << "Province Replaced!" << endl << endl;
            }
            else
                cout << "Replacement canceled!" << endl << endl;
        }
        else
            cout << "Replacement canceled!" << endl << endl;
    }
    else
        cout << "Your Dynasty Deck is empty!" << endl << endl;
}

void Player::printAvailableMoney()
{
    int sum = 0;
    for(unsigned int i = 0; i < holdings.size(); i++)
    {
        if(!holdings.at(i)->getTapped())
        {
            sum += holdings.at(i)->getHarvest();
            cout << "Holding " << i+1 << ": " << holdings.at(i)->getHarvest() << endl;
        }
    }
    cout << "Total sum: " << sum << endl << endl;
}

void Player::printSelectedMoney()
{
    int sum = 0;
    for(unsigned int i = 0; i < holdings.size(); i++)
    {
        if(!holdings.at(i)->getTapped() && holdings.at(i)->getSelected())
        {
            sum += holdings.at(i)->getHarvest();
            cout << "Holding " << i+1 << ": " << holdings.at(i)->getHarvest() << endl;
        }
    }
    if(sum != 0)
        cout << "Sum of selected Holdings: " << sum << endl << endl;
    else
        cout << "No Holdings selected!" << endl << endl;
}

void Player::purchaseProvince()
{
    Personality* pers = NULL;
    Holding* hold = NULL;
    TypeConverter t;
    int amount = 0;
    int cost = 0;
    int balance = 0;
    bool turn = true;
    unsigned int a = 0;
    string input = "";
    printProvinces();
    while(turn)
    {
        cout << "Please select the number of the province you wish to purchase:" << endl;
        cout << "(Use 0 to cancel and return to previous menu)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= provinces.size())
            {
                if(a)
                {
                    if(provinces.at(a-1)->getRevealed())
                    {
                        cost = provinces.at(a-1)->getCost();
                        if(cost)
                        {
                            cout << "Card costs: " << cost << endl << endl;
                            amount = pickHoldings();
                            balance = amount - cost;
                            if(balance >= 0 && amount)
                            {
                                if(verifyPurchase())
                                {
                                    provinces.at(a-1)->setTapped();
                                    t.getCorrectType(provinces.at(a-1), &pers, &hold);
                                    if(pers!=NULL)
                                        army.push_back(pers);
                                    if(hold!=NULL)
                                    {
                                        while(checkForAvailableHoldingsToChain(hold) && hold->canBeAdded())
                                            selectHoldingToChain(hold);
                                        holdings.push_back(hold);
                                    }
                                    provinces.erase(provinces.begin()+(a-1));
                                    provinces.push_back(dynastyDeck->front());
                                    dynastyDeck->pop_front();
                                    tapSelectedHoldings();
                                    cout << "Card purchased!" << endl << endl;
                                    turn = false;
                                }
                            }
                            else
                            {
                                if(amount)
                                    cout << "Sorry, insufficient funds!" << endl << endl;
                            }
                            deSelectHoldings();
                            amount = 0;
                        }
                        else
                        {
                            if(verifyPurchase())
                            {
                                provinces.at(a-1)->setTapped();
                                t.getCorrectType(provinces.at(a-1), &pers, &hold);
                                if(pers!=NULL)
                                    army.push_back(pers);
                                if(hold!=NULL)
                                {
                                    while(checkForAvailableHoldingsToChain(hold) && hold->canBeAdded())
                                            selectHoldingToChain(hold);
                                    holdings.push_back(hold);
                                }
                                provinces.erase(provinces.begin()+(a-1));
                                provinces.push_back(dynastyDeck->front());
                                dynastyDeck->pop_front();
                                cout << "Card purchased!" << endl << endl;
                            }
                        }
                    }
                    else
                        cout << "You can only purchase revealed cards!" << endl<< endl;
                }
                else
                    turn = false;
            break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
}

int Player::pickHoldings() //final
{
    int amount = 0;
    printAvailableMoney();
    unsigned int a = 0;
    bool turn = true;
    string input = "";
    while(turn)
    {
        cout << "Please select the number of the holding you want to use:" << endl;
        cout << "(Use 0 once done selecting. You get to review your choise later.)" << endl;
        cout << "(Using 0 with no provinces selected, and confirming it will lead you to the previous menu)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= holdings.size())
            {
                if(a && !holdings.at(a-1)->getTapped() && !holdings.at(a-1)->getSelected())
                {
                    holdings.at(a-1)->setSelected();
                    pickedHoldings.push_back(holdings.at(a-1));
                    cout << "Holding Selected!" << endl << endl;
                }
                else
                {
                    if(a && holdings.at(a-1)->getTapped())
                        cout << "Holding Already Used!" << endl;
                    if(a && holdings.at(a-1)->getSelected())
                        cout << "Holding Already Selected!" << endl;
                    if(!a)
                        turn = false;
                }
            break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    printSelectedMoney();
    for(unsigned int i = 0; i < pickedHoldings.size(); i++)
    {
        amount += pickedHoldings.at(i)->getHarvest();
    }
    return amount;
}

bool Player::verifyPurchase()
{
    unsigned int a = 0;
    string input = "";
    cout << "Please comfirm your choise." << endl;
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
                return true;
            else
                return false;
        }
    cout << "Wrong input, please try again!" << endl << endl;
    }
}
/*
bool Player::confirmHoldingSelection(int& amount)
{
    printSelectedMoney();
    if(amount)cout << "Sum of money the selected property offers: " << amount << endl << endl;
    unsigned int a = 0;
    string input = "";
    cout << "Please confirm your selection:" << endl << endl;
    cout << "Please enter 0 for No, 1 for Yes" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && (a == 0 || a ==1) )
        {
            if(a && amount)
                return true;
            else
            {
                amount = 0;
                return false;
            }
        }
    cout << "Wrong input, please try again!" << endl << endl;
    }
}
*/
void Player::printAvailableArmy()
{
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->hasFreeSpace())
        {
            cout << "Army Unit: " << i+1 << endl;
            cout << "Honour: " << army.at(i)->getHonour() << endl;
            cout << "Has space for " << army.at(i)->getItemSpace() << " items." << endl;
            cout << "Has space for " << army.at(i)->getFollowerSpace() << " followers." << endl << endl;
        }
    }
}

void Player::printAvailableUnits()
{
    int j = 0;
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(!army.at(i)->getTapped() && !army.at(i)->getSelected())
        {
            cout << "Army Unit: " << i+1 << endl;
            army.at(i)->printArmyCard();
            cout << endl;
            j++;
        }
    }
    if(!j)
    {
        cout << "You have no Army available!" << endl << endl;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printSelectedUnits()
{
    if(!selectedArmy.empty())
    {
        for(unsigned int i = 0; i< selectedArmy.size(); i++)
        {
            if(!selectedArmy.at(i)->getTapped())
            {
                cout << "Army Unit: " << i+1 << endl;
                army.at(i)->printArmyCard();
                cout << endl;
            }
        }
    }
    else
    {
        cout << "You has no Army selected!" << endl << endl;
        cout << "---" << endl;
        cout << endl;
    }
}

void Player::printUnTappedUnits()
{
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(!army.at(i)->getTapped())
            army.at(i)->printArmyCard();
    }
}

bool Player::canBeAttached(Item* i)
{
    int options = 0;
    for(unsigned int j = 0; j < army.size(); j++)
    {
        cout << army.at(j) << endl;
        if(army.at(j)->hasItemSpace() && i->getMinimumHonour() <= army.at(j)->getHonour())
            options++;
    }
    if(options)
        return true;
    else
        return false;
}

bool Player::canBeAttached(Follower* f)
{
    int options = 0;
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->hasFollowerSpace() && f->getMinimumHonour() <= army.at(i)->getHonour())
            options++;
    }
    if(options)
        return true;
    else
        return false;
}

void Player::printPersonalityForSelection(Item* item)
{
    for (unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->hasItemSpace() > 0 && item->getMinimumHonour() <= army.at(i)->getHonour())
        {
            cout << "Army " << i+1 << ":"<< endl;
            army.at(i)->printCard();
            cout << endl;
        }
    }
}

void Player::printPersonalityForSelection(Follower* follow)
{
    for (unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->hasFollowerSpace() && follow->getMinimumHonour() <= army.at(i)->getHonour())
        {
            cout << "Army " << i+1 << ":"<< endl;
            army.at(i)->printCard();
            cout << endl;
        }
    }
}

void Player::selectPersonality(Item* i)
{
    unsigned int a = 0;
    string input = "";
    printPersonalityForSelection(i);
    cout << "Please select the number of the Personality you want to own the Item:" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= army.size() && a)
        {
            if(army.at(a-1)->canAttach(i))
            {
                if(verifyPurchase())
                {
                    army.at(a-1)->attach(i);
                    break;
                }
            }
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
}

void Player::selectPersonality(Follower* f)
{
    unsigned int a = 0;
    string input = "";
    printPersonalityForSelection(f);
    cout << "Please select the number of the Personality you want the lead the Follower:" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= army.size() && a)
        {
            if(army.at(a-1)->canAttach(f))
            {
                if(verifyPurchase())
                {
                    army.at(a-1)->attach(f);
                    break;
                }
            }
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
}
/*
void Player::createChains()
{
    printHoldings();
    bool turn = true;
    unsigned int a = 0;
    string input = "";
    while(turn)
    {
        cout << "Please select the number of the card you wish use:" << endl;
        cout << "(Use 0 to cancel and return to previous menu.)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= holdings.size())
            {
                if(a)
                {
                    switch(holdings.at(a-1)->getCardType())
                    {
                        case(2): selectHoldingToChain(holdings.at(a-1)); break;
                        case(3): selectHoldingToChain(holdings.at(a-1)); break;
                        case(4): selectHoldingToChain(holdings.at(a-1)); break;
                        default: cout << "Cannot Attach Holdings to this Property!" << endl << endl; break;
                    }
                    turn = false;
                }
                else
                    turn = false;
                break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
}
*/
void Player::purchaseGreenCard()
{
    Item* item;
    Follower* follower;
    TypeConverter t;
    int amount = 0;
    int cost = 0;
    unsigned int a = 0;
    int balance = 0;
    bool turn = true;
    string input = "";
    printHand();
    while(turn)
    {
        cout << "Please select the number of card you wish to purchase:" << endl;
        cout << "(Use 0 to cancel and return to previous menu.)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: " << endl;
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= hand.size())
            {
                if(a)
                {
                    cost = hand.at(a-1)->getHandCost();
                    if(cost)
                    {
                        amount = pickHoldings();
                        balance = amount - cost;
                        if(balance >= 0)
                        {
                            t.getCorrectType(hand.at(a-1), &follower, &item);
                            if(follower)
                            {
                                if(canBeAttached(follower))
                                {
                                    if(verifyPurchase())
                                    {
                                        selectPersonality(follower);
                                        if(follower->getSelected())
                                        {
                                            follower->activateBonusCondition();
                                            follower->setDeSelected();
                                        }
                                        hand.erase(hand.begin()+(a-1));
                                        tapSelectedHoldings();
                                        cout << "Card purchased!" << endl << endl;
                                        amount = 0;
                                        turn = false;
                                    }
                                }
                                else
                                    cout << "Your choice cannot be attached to a personality!" << endl << endl;
                            }
                            if(item)
                            {
                                if(canBeAttached(item))
                                {
                                    if(verifyPurchase())
                                    {
                                        selectPersonality(item);
                                        if(item->getSelected())
                                        {
                                            item->activateBonusCondition();
                                            item->setDeSelected();
                                        }
                                        hand.erase(hand.begin()+(a-1));
                                        tapSelectedHoldings();
                                        cout << "Card purchased!" << endl << endl;
                                        amount = 0;
                                        turn = false;
                                    }
                                }
                                else
                                    cout << "Your choice cannot be attached to a personality!" << endl << endl;
                            }
                        }
                        else
                        {
                            if(amount){cout << "Sorry, insufficient funds!" << endl << endl;}
                        }
                        deSelectHoldings();
                        amount = 0;
                    }
                    else
                    {
                        t.getCorrectType(hand.at(a-1), &follower, &item);
                        if(follower)
                        {
                            if(canBeAttached(follower))
                            {
                                if(verifyPurchase())
                                {
                                    selectPersonality(follower);
                                    if(follower->getSelected())
                                        {
                                            follower->activateBonusCondition();
                                            follower->setDeSelected();
                                        }
                                    hand.erase(hand.begin()+(a-1));
                                    turn = false;
                                }
                            }
                            else
                                cout << "Your choice cannot be attached to a personality!" << endl << endl;
                        }
                        if(item)
                        {
                            if(canBeAttached(item))
                            {
                                if(verifyPurchase())
                                {
                                    selectPersonality(item);
                                    if(item->getSelected())
                                        {
                                            item->activateBonusCondition();
                                            item->setDeSelected();
                                        }
                                    hand.erase(hand.begin()+(a-1));
                                    turn = false;
                                }
                            }
                            else
                                cout << "Your choice cannot be attached to a personality!" << endl << endl;
                            }
                    }
                    break;
                }
                else
                {
                    turn = false;
                    break;
                }
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    amount = 0;
}

void Player::selectHoldingToChain(Holding* ho)
{
    printHoldings();
    unsigned int a = 0;
    string input = "";
    cout << "Please select the number of the card you wish to attach this holding to:" << endl;
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= holdings.size() && a)
        {
            ho->attachChain(holdings.at(a-1));
            break;
        }
        cout << "Wrong input, please try again!" << endl << endl;
    }
}

void Player::deSelectHoldings()
{
    for(unsigned int i = 0; i < pickedHoldings.size(); i++)
        pickedHoldings.at(i)->setDeSelected();
    pickedHoldings.clear();
}

void Player::deSelectProvinces()
{
    for(unsigned int i = 0; i < provinces.size(); i++)
        provinces.at(i)->setDeSelected();
}

void Player::tapSelectedHoldings()
{
    for(unsigned int i = 0; i < pickedHoldings.size(); i++)
        pickedHoldings.at(i)->setTapped();
}

void Player::printAttackOptions()
{
    cout << "Type 1 to view your available units." << endl;
    cout << "Type 2 to view your selected army." << endl;
 //   cout << "Type 3 to view your enemy's available units." << endl;
 //   cout << "Type 4 to view your enemy's provinces." << endl;
    cout << "Type 3 select units for your army." << endl;
    cout << "Type 4 to clear your selected army." << endl;
 //   cout << "Type 6 to choose your target." << endl;
  //  cout << "Type 6 to view your enemy's initial defense." << endl;
    cout << "Type 0 to end the phase." << endl;
}

void Player::printDefenseOptions()
{
    cout << "Type 1 to view your available units." << endl;
    cout << "Type 2 to view your selected army." << endl;
 //   cout << "Type 3 to view your enemy's attacking army." << endl;
    cout << "Type 3 to view your enemy's attacking army strength." << endl;
//    cout << "Type 5 to view which province is under attack." << endl;
    cout << "Type 4 select units for your army." << endl;
    cout << "Type 5 to clear your selected army." << endl;
    cout << "Type 6 to view your initial defense." << endl;
    cout << "Type 0 to end the phase." << endl;
}

void Player::attack()
{
    unsigned int a = 0;
    string input = "";
    bool turn = true;
    while(turn)
    {
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            printAttackOptions();
            cout << "Please type your option:" << endl;
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= ATTACK_OPTIONS)
                break;
            cout << "Wrong input, please try again!" << endl << endl;
        }
        switch(a)
        {
            case(0): cout << "Phase ended!" << endl << endl; turn = false; break;
            case(1): this->printAvailableUnits(); break;
            case(2): this->printSelectedUnits(); break;
 //           case(3): p->printUnTappedUnits(); break;
 //           case(4): p->printProvinces(); break;
            case(3): this->selectArmy(); break;
            case(4): this->deSelectArmy(); cout << "Selected Army Cleared" << endl; break;
//            case(6): this->aquireTarget(p); break;
         //   case(6): cout << "Your enemy's initial defence is: " << p->getInitialDefense() << endl << endl; break;
        }
    }
    getSelectedArmyStrength();
}

void Player::defend(int s)
{
    unsigned int a = 0;
    string input = "";
    bool turn = true;
    while(turn)
    {
        cout << "You are under attack!" << endl;
        cout << this->getName() << " time to make your move!" << endl;
        printDefenseOptions();
        cout << "Please type your option:" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
     //       cout << p->getName() << " is attacking!" << endl;
    //        cout << this->getName() << " time to make your move!" << endl;
   //         printDefenseOptions();
  //          cout << "Please type your option:" << endl;
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= DEFENSE_OPTIONS)
                break;
            cout << "Wrong input, please try again!" << endl << endl;
        }
        switch(a)
        {
            case(0): cout << "Phase ended!" << endl << endl; turn = false; break;
            case(1): this->printAvailableUnits(); break;
            case(2): this->printSelectedUnits(); break;
   //         case(3): p->printSelectedUnits(); break;
            case(3): cout << "Attacking Army strentgh: " << s << endl << endl; break;
  //          case(5): this->printSelectedProvince(); cout << endl; break;
            case(4): this->selectArmy(); break;
            case(5): this->deSelectArmy(); cout << "Selected Army Cleared" << endl; break;
            case(6): cout << "Your Initial Defense: " << initialDefense << endl; break;
        }
    }
    getSelectedArmyDefense();
}

void Player::selectArmy()
{
    printAvailableUnits();
    unsigned int a = 0;
    bool turn = true;
    string input = "";
    while(turn)
    {
        cout << "Please select the number of the unit you want to add:" << endl;
        cout << "(Use 0 once done selecting. You get to review your choise later.)" << endl;
        cout << "(Use 0 with no provinces selected, and confirm it to go the previous menu)" << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= army.size())
            {
                if(a && !army.at(a-1)->getTapped() && !army.at(a-1)->getSelected())
                {
                    army.at(a-1)->setSelected();
                    selectedArmy.push_back(army.at(a-1));
                }
                else
                    if(a && army.at(a-1)->getSelected())
                        cout << "Unit already selected!" << endl;
                    turn = false;
            break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    printSelectedUnits();
}

void Player::getSelectedArmyStrength()
{
    strength = 0;
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
        strength += selectedArmy.at(i)->getCombinedAttack();
    }
}

void Player::getSelectedArmyDefense()
{
    strength = 0;
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
        strength += selectedArmy.at(i)->getCombinedDefense();
    }
}

void Player::tapSelectedArmy()
{
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
            selectedArmy.at(i)->setTapped();
    }
}

void Player::deSelectArmy()
{
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
        selectedArmy.at(i)->setDeSelected();
    selectedArmy.clear();
}
/*
void Player::aquireTarget(Player* p)
{
    unsigned int a = 0;
    string input = "";
    p->printProvinces();
    while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
    {
        cout << "Please select the number of the province you want to attack:" << endl;
        cout << "(Use 0 to cancel and return to previous menu.)" << endl;
        cout << "Your input: ";
        getline(cin, input);
        stringstream myStream(input);
        cout << endl;
        if (myStream >> a && a <= p->provinces.size())
                break;
        cout << "Wrong input, please try again!" << endl << endl;
    }
    if(a)
    {
        p->provinces.at(a-1)->setSelected();
    }
}*/

void Player::overwhelmed()
{
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
        selectedArmy.at(i)->setIsDead();
    }
    selectedArmy.clear();
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->getIsDead())
        {
            discardedCards.push_back(army.at(i));
            army.erase(army.begin()+i);
            i--;
        }
    }
}

void Player::annihilated()
{
    overwhelmed();
    discardedCards.push_back(provinces.back());
    provinces.pop_back();
    numberOfProvinces--;
}

bool Player::checkForAvailableHoldingsToChain(Holding* ho)
{
    int options = 0;
    switch(ho->getCardType())
    {
        case(2):
            for(unsigned int i = 0; i < holdings.size(); i++)
            {
                if(holdings.at(i)->getCardType() == 3 && !holdings.at(i)->hasSubHolding())
                    options++;
            }break;
        case(3):
            for(unsigned int i = 0; i < holdings.size(); i++)
            {
                if((holdings.at(i)->getCardType() == 2 && !holdings.at(i)->hasUpperHolding()) || (holdings.at(i)->getCardType() == 4 && !holdings.at(i)->hasSubHolding()))
                    options++;
            }break;
        case(4):
            for(unsigned int i = 0; i < holdings.size(); i++)
            {
                if(holdings.at(i)->getCardType() == 3 && !holdings.at(i)->hasUpperHolding())
                    options++;
            }break;
    }
    if(options > 0)
        return true;
    else
        return false;
}

void Player::victorious()
{
    for(unsigned(i) = 0; i < selectedArmy.size(); i++)
    {
        selectedArmy.at(i)->setDeSelected();
        selectedArmy.at(i)->setTapped();
    }
    selectedArmy.clear();
}

void Player::offensiveVictory(int amount)
{
    int target = amount;
    unsigned int a = 0;
    string input = "";
    while(target > 0)
    {
        printSelectedUnits();
        cout << getName() << ", you won the battle but suffered casualties!" << endl;
        cout << "You have to select units whose attack power is equal or exceeds " << target << "!" << endl;
        cout << "You may use items, followers, personalities or combined units! " << endl;
        cout << "Please select the number of the unit you want to lose:" << endl;
        cout << "(If the unit has followers or items attached, you'll get to choose what you want to lose)." << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= selectedArmy.size() && a)
            {
                if(selectedArmy.at(a-1)->hasAttachments())
                {
                    target -= selectedArmedAttackingPersonalities(selectedArmy.at(a-1));
                }
                else
                    if(verifyPurchase())
                    {
                        selectedArmy.at(a-1)->setIsDead();
                        target -= selectedArmy.at(a-1)->getCombinedAttack();
                    }

            break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
        selectedArmy.at(i)->setTapped();
        selectedArmy.at(i)->offensiveAftermath();
    }
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->getIsDead())
        {
            discardedCards.push_back(army.at(i));
            army.erase(army.begin()+i);
            i--;
        }
    }
    selectedArmy.clear();
}

int Player::selectedArmedAttackingPersonalities(Personality* p)
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    p->printArmyCard();
    if(p->hasItems() && p->hasFollowers())
    {
        cout << "Your choise has items and followers equipted!" << endl;
        cout << "Select 1 to choose your personality with all the attachments." << endl;
        cout << "Amount: " << p->getCombinedAttack() << endl;
        cout << "Select 2 to pick items from your personality." << endl;
        cout << "Select 3 to pick followers from your personality." << endl;
        cout << "Select 0 to return to the previous menu." << endl;
        while(true)
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= 3)
            {
                switch(a)
                {
                    case(1):if(verifyPurchase())amount = p->getCombinedAttack(); break;
                    case(2):amount = p->pickOffensiveItem(); break;
                    case(3):amount = p->pickOffensiveFollower(); break;
                    case(0):amount = 0; break;
                }
                break;
            }
            else
        cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    else
    {
        if(p->hasItems() && !p->hasFollowers())
        {
            cout << "Your choise has items equipted!" << endl;
            cout << "Select 1 to choose your personality with all the attachments." << endl;
            cout << "Amount: " << p->getCombinedAttack() << endl;
            cout << "Select 2 to pick items from your personality." << endl;
            cout << "Select 0 to return to the previous menu." << endl;
            while(true)
            {
                cout << "Your input: ";
                getline(cin, input);
                stringstream myStream(input);
                cout << endl;
                if (myStream >> a && a <= 2)
                {
                    switch(a)
                    {
                        case(1):if(verifyPurchase())amount = p->getCombinedAttack(); break;
                        case(2):amount = p->pickOffensiveItem(); break;
                        case(0):amount = 0; break;
                    }
                    break;
                }
                else
                    cout << "Wrong input, please try again!" << endl << endl;
            }
        }
        if(!p->hasItems() && p->hasFollowers())
        {
            cout << "Your choise has followers!" << endl;
            cout << "Select 1 to choose your personality with all the attachments." << endl;
            cout << "Amount: " << p->getCombinedAttack() << endl;
            cout << "Select 2 to pick followers from your personality." << endl;
            cout << "Select 0 to return to the previous menu." << endl;
            while(true)
            {
                cout << "Your input: ";
                getline(cin, input);
                stringstream myStream(input);
                cout << endl;
                if (myStream >> a && a <= 3)
                {
                switch(a)
                {
                    case(1):if(verifyPurchase())amount = p->getCombinedAttack(); break;
                    case(2):amount = p->pickOffensiveFollower(); break;
                    case(0):amount = 0; break;
                }
                break;
            }
            else
                cout << "Wrong input, please try again!" << endl << endl;
            }
        }
    }
    return amount;
}

void Player::defensiveVictory(int amount)
{
    int target = amount;
    unsigned int a = 0;
    string input = "";
    while(target > 0)
    {
        printSelectedUnits();
        cout << getName() << ", you won the battle but suffered casualties!" << endl;
        cout << "You have to select units whose defense is equal or exceeds " << target << "!" << endl;
        cout << "You may use items, followers, personalities or combined units! " << endl;
        cout << "Please select the number of the unit you want to lose:" << endl;
        cout << "(If the unit has followers or items attached, you'll get to choose what you want to lose)." << endl;
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= selectedArmy.size() && a)
            {
                if(selectedArmy.at(a-1)->hasAttachments())
                {
                    target -= selectedArmedDefendingPersonalities(selectedArmy.at(a-1));
                }
                else
                {
                    selectedArmy.at(a-1)->setIsDead();
                    target -= selectedArmy.at(a-1)->getCombinedDefense();
                }
            break;
            }
            cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    for(unsigned int i = 0; i < selectedArmy.size(); i++)
    {
        selectedArmy.at(i)->setTapped();
    }
    for(unsigned int i = 0; i < army.size(); i++)
    {
        if(army.at(i)->getIsDead())
        {
            discardedCards.push_back(army.at(i));
            army.erase(army.begin()+i);
            i--;
        }
    }
    selectedArmy.clear();
}

int Player::selectedArmedDefendingPersonalities(Personality* p)
{
    int amount = 0;
    unsigned int a = 0;
    string input = "";
    p->printArmyCard();
    if(p->hasItems() && p->hasFollowers())
    {
        cout << "Your choise has items and followers equipted!" << endl;
        cout << "Select 1 to choose your personality with all the attachments." << endl;
        cout << "Amount: " << p->getCombinedDefense() << endl;
        cout << "Select 2 to pick items from your personality." << endl;
        cout << "Select 3 to pick followers from your personality." << endl;
        cout << "Select 0 to return to the previous menu." << endl;
        while(true)
        {
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= 3)
            {
                switch(a)
                {
                    case(1):if(verifyPurchase())amount = p->getCombinedDefense(); break;
                    case(2):amount = p->pickDefensiveItem(); break;
                    case(3):amount = p->pickDefensiveFollower(); break;
                    case(0):amount = 0; break;
                }
                break;
            }
            else
        cout << "Wrong input, please try again!" << endl << endl;
        }
    }
    else
    {
        if(p->hasItems() && !p->hasFollowers())
        {
            cout << "Your choise has items equipted!" << endl;
            cout << "Select 1 to choose your personality with all the attachments." << endl;
            cout << "Amount: " << p->getCombinedDefense() << endl;
            cout << "Select 2 to pick items from your personality." << endl;
            cout << "Select 0 to return to the previous menu." << endl;
            while(true)
            {
                cout << "Your input: ";
                getline(cin, input);
                stringstream myStream(input);
                cout << endl;
                if (myStream >> a && a <= 2)
                {
                    switch(a)
                    {
                        case(1):if(verifyPurchase())amount = p->getCombinedDefense(); break;
                        case(2):amount = p->pickDefensiveItem(); break;
                        case(0):amount = 0; break;
                    }
                    break;
                }
                else
                    cout << "Wrong input, please try again!" << endl << endl;
            }
        }
        if(!p->hasItems() && p->hasFollowers())
        {
            cout << "Your choise followers equipted!" << endl;
            cout << "Select 1 to choose your personality with all the attachments." << endl;
            cout << "Amount: " << p->getCombinedDefense() << endl;
            cout << "Select 2 to pick followers from your personality." << endl;
            cout << "Select 0 to return to the previous menu." << endl;
            while(true)
            {
                cout << "Your input: ";
                getline(cin, input);
                stringstream myStream(input);
                cout << endl;
                if (myStream >> a && a <= 3)
                {
                switch(a)
                {
                    case(1):if(verifyPurchase())amount = p->getCombinedDefense(); break;
                    case(2):amount = p->pickDefensiveFollower(); break;
                    case(0):amount = 0; break;
                }
                break;
            }
            else
                cout << "Wrong input, please try again!" << endl << endl;
            }
        }
    }
    return amount;
}
