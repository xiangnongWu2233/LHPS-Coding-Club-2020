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
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 5; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i - 1;
    for (int i = 6; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 3;
}
