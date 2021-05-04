#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

wind::wind() : water()
{
    name = "Wind";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[46m");
    cout << name;
    printf("\033[0m\n");
}

void wind::skill()
{
}

void wind::ultimate()
{
}