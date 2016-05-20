#ifndef __PLAYER_HPP_
#define __PLAYER_HPP_
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "Holding.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Follower.hpp"
#include "StrongHold.hpp"
#include <iostream>
#include <sstream>
#define STARTING_HAND_AMOUNT 2
#define MAX_HAND_AMOUNT 10
#define NUMBER_OF_PROVINCES 4
#define ATTACK_OPTIONS 4
#define DEFENSE_OPTIONS 6

using namespace std;

class Player
{
    string name;
    int money;
    int honour;
    int initialDefense;
    int numberOfProvinces;
    StrongHold strong;
    int strength;
    list<GreenCard*>* fateDeck;
    list<BlackCard*>* dynastyDeck;
    vector<BlackCard*> provinces;
    vector<GreenCard*> hand;
    vector<Personality*> army;
    vector<Personality*> selectedArmy;
    vector<Holding*> holdings;
    vector<Holding*> pickedHoldings;
    vector<Card*> discardedCards;

    public:
    Player(string s);
    ~Player();

    void addtoarmy(Personality* p){army.push_back(p);}

    void setMoney(int a);
    void setHonour(int a);
    void setInitialDefense(int a);
    void setNumberOfProvinces(int a);
    void setName(string s);
    void setStrength(int a);

    int getMoney();
    int getHonour();
    int getInitialDefense();
    int getNumberOfProvinces();
    int getStrength();
    string getName();

    int getFateDeckSize();
    int getDynastyDeckSize();
    int getHandSize();

    void drawFateCard();
    void drawDynastyCard();
    void unTapEverything();
    void deSelectEverything();
    void revealProvinces();
    void deSelectProvinces();

    void printHand();
    void printProvinces();
    void printHoldings();
    void printArena();
    void printPlayer();
    void printName();
    void printSelectedProvince();

    void discardSurplusFateCards();

    bool hasArmy();
    bool hasSelectedArmy();

    void printAvailableMoney();
    void printSelectedMoney();

    int pickHoldings();
    bool verifyPurchase();
   // bool confirmHoldingSelection(int& amount);
    void deSelectHoldings();
    void tapSelectedHoldings();

    void selectArmy();
    void deSelectArmy();
    void tapSelectedArmy();
   // void aquireTarget(Player* p);
    void getSelectedArmyStrength();
    void getSelectedArmyDefense();
    int selectedArmedAttackingPersonalities(Personality* p);
    int selectedArmedDefendingPersonalities(Personality* p);

    void purchaseProvince();
    void replaceProvince();
    void purchaseGreenCard();

    void printAvailableArmy();
    bool canBeAttached(Item* i);
    bool canBeAttached(Follower* f);
    void selectPersonality(Item* i);
    void selectPersonality(Follower* f);
    void printPersonalityForSelection(Item* item);
    void printPersonalityForSelection(Follower* follower);
    void printAttackOptions();
    void printDefenseOptions();
    void printAvailableUnits();
    void printSelectedUnits();
    void printUnTappedUnits();

 //   void createChains();
    void selectHoldingToChain(Holding* ho);
    bool checkForAvailableHoldingsToChain(Holding* ho);
    void discardEverything();

    void attack();
    void defend(int s);
    void victorious();
    void offensiveVictory(int amount);
    void defensiveVictory(int amount);
    void overwhelmed();
    void annihilated();
};

#endif
