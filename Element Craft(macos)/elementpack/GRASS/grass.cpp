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
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 6; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i;
    for (int i = 7; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 6;
}
