#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

earth::earth() : grass()
{
    name = "Earth";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[42m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 4;
}

void earth::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), players[id].ele->ultimateCost);
    players[id].energy -= players[id].ele->ultimateCost;
    sleep(1);
    printf("Spring renews the earth");
}