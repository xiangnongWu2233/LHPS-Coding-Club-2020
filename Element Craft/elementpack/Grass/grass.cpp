#include <iostream>
#include "../../game.h"
#include "grassElement.h"

using namespace std;

grass::grass()
{
    name = "Grass";
    baseAttack = 3;
    baseDefense = 3;
    baseHP = 20;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 3;
}
