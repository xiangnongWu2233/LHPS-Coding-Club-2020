#include <iostream>
#include "../../game.h"
#include "fireElement.h"

using namespace std;

fire::fire()
{
    name = "Fire";
    baseAttack = 5;
    baseDefense = 2;
    baseHP = 14;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 2;
}
