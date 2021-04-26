#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

divine::divine(int i)
{
    name = "Divine";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[48m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 4;
}

void divine::ultimate()
{
    printf("圣光审判！");
}