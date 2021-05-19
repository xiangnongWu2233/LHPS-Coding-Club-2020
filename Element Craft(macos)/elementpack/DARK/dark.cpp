#include <iostream>
#include "../../game.h"
#include "darkElement.h"

using namespace std;

dark::dark()
{
    name = "Dark";
    baseAttack = 4;
    baseDefense = 3;
    baseHP = 30;
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 5; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i + 2;
    for (int i = 6; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 4;
}
