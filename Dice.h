#ifndef DICE_HPP
#define DICE_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Dice
{
    public:
        bool DiceRoll();

    private:
        int D1, D2;
};

#endif // DICE_HPP
