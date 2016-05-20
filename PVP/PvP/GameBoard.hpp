#ifndef __GAMEBOARD_HPP_
#define __GAMEBOARD_HPP_
#include "DeckBuilder.hpp"
#include "TypeConverter.hpp"
#include "Holding.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Follower.hpp"
#include "Player.hpp"
#include <iostream>
#include "PlayerComm.hpp"
#define EQUIPT_OPTIONS 6
#define ECONOMY_OPTIONS 5

using namespace std;

class GameBoard
{
  Player* player;
  int turn;

  public:
  GameBoard();
  void initializeGameBoard(Player* x, int t);

  bool checkWinningCondition();
  void startingPhase(Player* p);
  void equiptPhase(Player* p);
  int battlePhase(Player* p1);
  void economyPhase(Player* p);
  void endingPhase(Player* p);

  void gameplay();

  int battle(int s, Player* p2);
  void aftermath(){};

  void printGameStatistics(Player* p);
  void printEconomyOptions();
  void printEquiptOptions();
};

#endif
