#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

poison::poison(int i)
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
    printf("毒气侵袭！");
}