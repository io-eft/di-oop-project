#include "GameBoard.hpp"

GameBoard::GameBoard()
{
    player = NULL;
}

void GameBoard::initializeGameBoard(Player* x, int t)
{
    player = x;
    if(t == 1)
        turn = 1;
    else
        turn = 0;
}
/*
bool GameBoard::checkWinningCondition()
{
    if(first_player->getNumberOfProvinces() == 0 || second_player->getNumberOfProvinces() == 0)
        return true;
    else
        return false;
}
*/
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

int GameBoard::battlePhase(Player* p1)
{
    p1->printName(); cout << "'s turn!" << endl << endl;
    if(p1->hasArmy())
    {
        cout << "Battle Phase!" << endl;
        p1->attack();
        if(p1->hasSelectedArmy())
        {
            return p1->getStrength();
        }
    }
    else
        cout << "You have no army!" << endl << endl;
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
/*
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
*/
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

int GameBoard::battle(int s, Player* p2)
{
    int result = s - (p2->getStrength() + p2->getInitialDefense());
    int amount = s - p2->getStrength();
    if(result >= 0)
    {
    //    cout << p1->getName() << " triumphed over " << p2->getName() << "!" << endl;
        cout << "You lost and your province is destroyed!" << endl << endl;
  //      p1->victorious();
        p2->annihilated();
        return -1;
    }
    else
    {
        if(amount > 0)
        {
            cout << "You gave a good fight, but your opponent won, although he suffered casualties too!" << endl;
        //    cout << p2->getName() << "'s province still stands!" << endl << endl;
        //    p1->offensiveVictory(amount);
            p2->overwhelmed();
            return 0;
        }
        if(amount < 0)
        {
        //    cout << p1->getName() << " did a solid attempt, but " << p2->getName() << " was the winner!" << endl;
            cout << "You lost troops in the fight too, but defended his province" << endl << endl;
  //          p1->overwhelmed();
            p2->defensiveVictory(-amount);
            return 0;
        }
        if(amount == 0)
        {
            cout << "A real masacre! Both sides have huge casualties!" << endl << endl;
         //   p1->overwhelmed();
            p2->overwhelmed();
            return 0;
        }
    }
}

void GameBoard :: gamePlay(PlayerComm &pl)
{
        int flag = 1;
        int choice = 0;
        int att = 0;
        int result = 0;
        int amount = 0;
        string* mymsg;
        stringstream myStream;
        while(true)
        {
            if(turn == 1)
            {
                pl.sendMessage("Opponent starts turn");
                startingPhase(player);
                attachPhase(player);
                att = battlePhase(player);
                if(att)
                {
                    myStream << att;
                    *mymsg = myStream.str();
                    pl.sendMessage(mymsg);
                    sleep(1);
                    string *myrec = pl.readMessage();
                    if( strcmp( (*myrec).c_str() , "-1") == 0 )
                    {
                        cout << "You won and destroyed your Enemy's province!" << endl;
                        player->victorious();
                    }
                    else if(strcmp((*myrec).c_str() , "0")==0)
                    {
                        cout << "You lose all your units!" << endl;
                        player->overwhelmed();
                    }
                    else
                    {
                        cout << "You won, but failed to destroy the province!" << endl;
                        myStream << *myrec;
                        if(myStream >> amount)
                        {
                            player->offensiveVictory(amount);
                        }
                    }
                }
                purchasePhase(player);
                endingPhase(player);
                cout<<"Press -1 to terminate the program : ";
                cin>>flag;

                if(flag == -1)
                {
                    pl.sendMessage("Terminate");
                    break;
                }
                else
                {
                    pl.sendMessage("End of Turn");
                    turn = !turn;
                }
            }
            else
            {
                cout<<"Waiting for the other player to finish"<<endl;
                string *message = pl.readMessage();
                if( strcmp( (*message).c_str() , "Terminate") == 0 )
                    break;
                else if(strcmp((*message).c_str() , "End of Turn")==0)
                    turn = !turn;
                else
                {
                    myStream << *message;
                    if(myStream >> att)
                    {
                        cout<<"I am recieving attack"<<endl;
                        player->defend(att);
                        result = battle(att, player);
                        if(result == -1)
                        {
                            pl.sendMessage("-1");
                        }
                        if(result == 0)
                        {
                            pl.sendMessage("0");
                        }
                        if(result > 0)
                        {
                            myStream << result;
                            *mymsg = myStream.str();
                            pl.sendMessage(*mymsg);
                        }
                    }
                    else
                        cout<<*message<<endl;
            }
        }
        sleep(1);
        }
}


