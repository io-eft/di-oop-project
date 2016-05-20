#include "Card.hpp"

Card::Card(){}

Card::~Card(){}

void Card::setName(string nam){name = nam;}

void Card::setCost(int cos){cost = cos;}

void Card::setTapped(){isTapped = true;}

void Card::setUnTapped(){isTapped = false;}

void Card::setSelected(){selected = true;}

void Card::setDeSelected(){selected = false;}

string Card::getName(){return name;}

int Card::getCost(){return cost;}

bool Card::getTapped(){return isTapped;}

void Card::setCardType(int t){cardType = t;}

int Card::getCardType(){return cardType;}

bool Card::getSelected(){return selected;}

