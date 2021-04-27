#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

spirit::spirit() : light()
{
    name = "Spirit";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[91m\033[48m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 4;
}

void spirit::ultimate()
{
    printf("圣灵净化！");
}