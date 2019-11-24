#include "Dice.h"
using namespace std;

bool Dice::DiceRoll()
{
    int total;
    srand(static_cast<unsigned>(time(NULL)));
    D1 = (rand() % 6 + 1);
    D2 = (rand() % 6 + 1);
    total = D1 + D2;
    if(total > 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}
