#ifndef __STRONGHOLD__HPP
#define __STRONGHOLD__HPP
#include "Holding.hpp"
#include <cstdlib>

using namespace std;

class StrongHold
{
    Holding* hold;
    int honour;
    int money;
    int initialDefense;
    string text;
    int stronghold_type;

    public:
    StrongHold();
    ~StrongHold();

    void setHonour(int a);
    void setMoney(int a);
    void setInitialDefense(int a);
    void setText(string s);
    void setStrongHoldType(int a);

    int getHonour();
    int getMoney();
    int getInitialDefense();
    string getText();
    int getStrongHoldType();
    Holding* getStrongHold();

    void printStrongHoldType();
    void printStrongHold();
};

#endif
