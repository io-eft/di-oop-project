#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    first_player = NULL;
    second_player = NULL;
}

void GameBoard::initializeGameBoard(Player* x, Player* y, int deck_size)
{
    if( x->getHonour() > y->getHonour())
    {
        first_player = x;
        second_player = y;
    }
    if ( x->getHonour() < y->getHonour())
    {
        first_player = y;
        second_player = x;
    }
    if ( x->getHonour() == y->getHonour())
    {
        if(rand()%2)
        {
            first_player = x;
            second_player = y;
        }
        else
        {
            first_player = y;
            second_player = x;
        }
    }
    cout << first_player->getName() << " goes first!" << endl << endl;
    if(first_player->getDynastyDeckSize() > deck_size || first_player->getFateDeckSize() > deck_size)
        cout << first_player->getName() << "has irregular decks!" << endl;
    if(second_player->getDynastyDeckSize() > deck_size || second_player->getFateDeckSize() > deck_size)
        cout << first_player->getName() << "has irregular decks!" << endl;
}

bool GameBoard::checkWinningCondition()
{
    if(first_player->getNumberOfProvinces() == 0 || second_player->getNumberOfProvinces() == 0)
        return true;
    else
        return false;
}

void GameBoard::startingPhase(Player* p)
{
    p->unTapEverything();
    p->deSelectEverything();
    p->drawFateCard();
    p->revealProvinces();
    p->printHand();
    p->printProvinces();
}

void GameBoard::equiptPhase(Player* p)
{
    cout << "Equipt Phase!" << endl;
    p->printName(); cout << "'s turn!" << endl << endl;
    if(p->hasArmy())
    {
        unsigned int a = 0;
        string input = "";
        bool turn = true;
        while(turn)
        {
            while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
            {
                printEquiptOptions();
                cout << "Please type your option:" << endl;
                cout << "Your input: ";
                getline(cin, input);
                stringstream myStream(input);
                cout << endl;
                if (myStream >> a && a <= EQUIPT_OPTIONS)
                    break;
                cout << "Wrong input, please try again!" << endl << endl;
            }
            switch(a)
            {
                case(0): cout << "Phase ended!" << endl << endl; turn = false; break;
                case(1): p->printArena(); break;
                case(2): p->printAvailableArmy(); break;
                case(3): p->printHand(); break;
                case(4): p->printHoldings(); break;
                case(5): p->printAvailableMoney(); break;
                case(6): p->purchaseGreenCard(); break;
            }
        }
    }
    else
        cout << "Sorry, you have no army to equipt!" << endl << endl;
}

void GameBoard::battlePhase(Player* p1, Player* p2)
{
    p1->printName(); cout << "'s turn!" << endl << endl;
    if(p1->hasArmy())
    {
        cout << "Battle Phase!" << endl;
        p1->attack();
        if(p1->hasSelectedArmy())
        {
            p2->defend(p1->getStrength());
            battle(p1,p2);
        }
    }
    else
        cout << "You have no army!" << endl << endl;
    p1->deSelectEverything();
    p2->deSelectEverything();
}

void GameBoard::economyPhase(Player* p)
{
    unsigned int a = 0;
    bool turn = true;
    string input = "";
    cout << "Economy Phase!" << endl;
    p->printName(); cout << "'s turn!" << endl << endl;
    while(turn)
    {
        while(true)         // This part was found on http://www.cplusplus.com/forum/articles/6046/
        {
            printEconomyOptions();
            cout << "Please type your option:" << endl;
            cout << "Your input: ";
            getline(cin, input);
            stringstream myStream(input);
            cout << endl;
            if (myStream >> a && a <= ECONOMY_OPTIONS)
                break;
            cout << "Wrong input, please try again!" << endl << endl;
        }
        switch(a)
        {
            case(0):cout << "Phase ended!" << endl << endl; turn = false; break;
            case(1): p->printProvinces(); break;
            case(2): p->printHoldings(); break;
            case(3): p->printAvailableMoney(); break;
            case(4): p->purchaseProvince(); break;
       //     case(5): p->createChains(); break;
            case(5):p->replaceProvince(); break;
        }
    }
}

void GameBoard::endingPhase(Player* p)
{
    if(p->getHandSize() > MAX_HAND_AMOUNT)
    {
        p->printName(); cout << "'s turn!" << endl << endl;
        cout << "Your have too many cards in your hand!" << endl;
        p->discardSurplusFateCards();
    }
}

void GameBoard::printGameStatistics(Player* p)
{
    cout << "Player: " << p->getName() << endl;
    p->printHand();
    p->printProvinces();
    p->printArena();
    p->printHoldings();
}

void GameBoard::gameplay()
{
    while(!checkWinningCondition())
    {
        startingPhase(first_player);
        startingPhase(second_player);
        equiptPhase(first_player);
        equiptPhase(second_player);
        battlePhase(first_player, second_player);
        battlePhase(second_player, first_player);
        economyPhase(first_player);
        economyPhase(second_player);
        endingPhase(first_player);
        endingPhase(second_player);
        printGameStatistics(first_player);
        printGameStatistics(second_player);
    }
    if(first_player->getNumberOfProvinces() == 0 && second_player->getNumberOfProvinces() == 0)
        cout << "It's a draw!" << endl << endl;
    if(first_player->getNumberOfProvinces() == 0 && second_player->getNumberOfProvinces() > 0)
        cout << second_player->getName() << " is the winner!" << endl << endl;
    if(first_player->getNumberOfProvinces() > 0 && second_player->getNumberOfProvinces() == 0)
        cout << first_player->getName() << " is the winner!" << endl << endl;
}

/* 2nd version of gameplay, where each player does all 5 phases before the 2nd one
void GameBoard::gameplay()
{
    while(!checkWinningCondition())
    {
        startingPhase(first_player);
        equiptPhase(first_player);
        battlePhase(first_player, second_player);
        economyPhase(first_player);
        endingPhase(first_player);
        printGameStatistics(first_player);
        startingPhase(second_player);
        equiptPhase(second_player);
        battlePhase(second_player, first_player);
        economyPhase(second_player);
        endingPhase(second_player);
        printGameStatistics(second_player);
    }
    if(first_player->getNumberOfProvinces() == 0 && second_player->getNumberOfProvinces() == 0)
        cout << "It's a draw!" << endl << endl;
    if(first_player->getNumberOfProvinces() == 0 && second_player->getNumberOfProvinces() > 0)
        cout << second_player->getName() << " is the winner!" << endl << endl;
    if(first_player->getNumberOfProvinces() > 0 && second_player->getNumberOfProvinces() == 0)
        cout << first_player->getName() << " is the winner!" << endl << endl;
}*/

void GameBoard::printEconomyOptions()
{
    cout << "Type 1 to view your available provinces." << endl;
    cout << "Type 2 to view your holdings." << endl;
    cout << "Type 3 to view your available money." << endl;
    cout << "Type 4 to purchase a province." << endl;
    //cout << "Type 5 to create a chain with your holdings." << endl;
    cout << "Type 5 to discard a province and replace it with a new one. The new province will remain hidden until the next round." << endl;
    cout << "Type 0 to end the phase." << endl;
}


void GameBoard::printEquiptOptions()
{
    cout << "Type 1 to view your army." << endl;
    cout << "Type 2 to view your available army units." << endl;
    cout << "Type 3 to view your hand." << endl;
    cout << "Type 4 to view your holdings." << endl;
    cout << "Type 5 to view your available money." << endl;
    cout << "Type 6 to purchase an item or follower from your hand and add it to an army unit." << endl;
    cout << "Type 0 to end the phase." << endl;
}

void GameBoard::battle(Player* p1, Player* p2)
{
    int result = p1->getStrength() - (p2->getStrength() + p2->getInitialDefense());
    int amount = p1->getStrength() - p2->getStrength();
    if(result >= 0)
    {
        cout << p1->getName() << " triumphed over " << p2->getName() << "!" << endl;
        cout << p2->getName() << "'s province is destroyed!" << endl << endl;
        p1->victorious();
        p2->annihilated();
    }
    else
    {
        if(amount > 0)
        {
            cout << p2->getName() << " gave a good fight, but " << p1->getName() << " won, although he suffered casualties too!" << endl;
            cout << p2->getName() << "'s province still stands!" << endl << endl;
            p1->offensiveVictory(amount);
            p2->overwhelmed();
        }
        if(amount < 0)
        {
            cout << p1->getName() << " did a solid attempt, but " << p2->getName() << " was the winner!" << endl;
            cout << "He lost troops in the fight too, but defended his province" << endl << endl;
            p1->overwhelmed();
    /*        if(p1->getStrength() > - amount)
                p2->defensiveVictory(-amount);
            else
                p2->defensiveVictory(p1->getStrength()); */
            p2->defensiveVictory(-amount);
        }
        if(amount == 0)
        {
            cout << "A real masacre! Both sides have huge casualties!" << endl << endl;
            p1->overwhelmed();
            p2->overwhelmed();
        }
    }
}
