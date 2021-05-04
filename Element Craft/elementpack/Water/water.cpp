#include <iostream>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"

using namespace std;

water::water()
{
    name = "Water";
    baseAttack = 2;
    baseDefense = 5;
    baseHP = 15;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 3;
}
