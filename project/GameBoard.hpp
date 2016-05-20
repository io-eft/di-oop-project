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
#define EQUIPT_OPTIONS 6
#define ECONOMY_OPTIONS 5

using namespace std;

class GameBoard
{
  Player* first_player;
  Player* second_player;

  public:
  GameBoard();
  void initializeGameBoard(Player* x, Player* y, int deck_size);

  bool checkWinningCondition();
  void startingPhase(Player* p);
  void equiptPhase(Player* p);
  void battlePhase(Player* p1, Player* p2);
  void economyPhase(Player* p);
  void endingPhase(Player* p);

  void gameplay();

  void battle(Player* p1, Player* p2);
  void aftermath(){};

  void printGameStatistics(Player* p);
  void printEconomyOptions();
  void printEquiptOptions();
};

#endif
