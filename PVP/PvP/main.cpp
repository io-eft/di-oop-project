#include <iostream>
#include "BlackCard.hpp"
#include "Card.hpp"
#include "Follower.hpp"
#include "GreenCard.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Player.hpp"
#include "PlayerComm.hpp"
#include "GameBoard.hpp"
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "StrongHold.hpp"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;
/*
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
}
*/

int main(int argc, char *argv[])
{


    char *host = argv[1];
    char *player = argv[5];
    int portToConnect = atoi(argv[2]);
    int portToListen = atoi(argv[3]);
    int turn = atoi(argv[4]);

    PlayerComm pl(argv[1], portToConnect, portToListen);
    pl.init(turn);

    cout<<"I am Player : "<<player<<endl;
    pl.sendMessage(player);
        string * opponent = pl.readMessage();
        cout<<"My opponent is Player : "<< *opponent<<endl;

    sleep(1);


    player *p = new Player(*player);
    GameBoard g;
    g.initializeGameBoard(p, t);
    g.gameplay();
    delete player;
}




