#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

poison::poison() : grass()
{
    name = "Poison";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[43m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 4;
}

void poison::ultimate()
{
}