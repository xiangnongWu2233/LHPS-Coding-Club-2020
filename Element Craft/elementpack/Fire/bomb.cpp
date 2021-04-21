#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

bomb::bomb() : element("2")
{
    name = "Bomb";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
    skillcost[1] = 4;
}

void bomb::ultimate()
{
    printf("狂轰滥炸！");
}