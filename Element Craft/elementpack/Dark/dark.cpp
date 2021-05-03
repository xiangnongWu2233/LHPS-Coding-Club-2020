#include <iostream>
#include "../../game.h"
#include "../baseelement.h"

using namespace std;

dark::dark()
{
    name = "Dark";
    baseAttack = 4;
    baseDefense = 3;
    baseHP = 19;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 3;
}
