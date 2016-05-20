#include <iostream>
#include "BlackCard.hpp"
#include "Card.hpp"
#include "Follower.hpp"
#include "GreenCard.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "StrongHold.hpp"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    srand(time(NULL));
    string name = "";                                       //Code for players name taken from http://www.cplusplus.com/forum/articles/6046/
    cout << "Please enter first player's name:" << endl;
    getline(cin, name);
    cout << endl;
    Player* player1 = new Player(name);
    cout << "Please enter second player's name:" << endl;
    getline(cin, name);
    cout << endl;
    Player* player2 = new Player(name);
    GameBoard g;
    g.initializeGameBoard(player1, player2, MAXDECKSIZE);
    g.gameplay();
    delete player1;
    delete player2;
}





