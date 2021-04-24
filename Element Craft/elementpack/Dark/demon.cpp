#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

demon::demon(int i) : element(i, "5")
{
    name = "Demon";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[40m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 4;
}

void demon::ultimate()
{
    printf("六重咒杀！");
}