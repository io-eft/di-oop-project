#ifndef __HOLDING__HPP
#define __HOLDING__HPP
#include "BlackCard.hpp"

enum{PLAIN=1, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};

class Holding: public BlackCard
{
  int harvestValue;
  Holding* upperHolding;
  Holding* subHolding;

  public:
  Holding(string nam, int typ);
  ~Holding(){}

  void setHarvest(int a);
  int getHarvest();
  int getOriginalHarvestValue();

  int getType();
  void printCard();
  void printCardType();

  bool hasSubHolding();
  bool hasUpperHolding();

  bool canBeAdded();

  void attachSubHolding(Holding* hol);
  void attachUpperHolding(Holding* hol);
  void attachChain(Holding* ho);
};

#endif

