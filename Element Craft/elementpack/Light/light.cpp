#include <iostream>
#include <cstdio>
#include "../../game.h"
#include "lightElement.h"

using namespace std;

light::light()
{
    name = "Light";
    baseAttack = 3;
    baseDefense = 4;
    baseHP = 19;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 2;
}
