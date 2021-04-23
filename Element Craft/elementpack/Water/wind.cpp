#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

wind::wind(int i) : element(i, "1")
{
    name = "Wind";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[46m");
    cout << name;
    printf("\033[0m\n");
    ultracost = 4;
}

void wind::ultimate()
{
    printf("飓风！");
}