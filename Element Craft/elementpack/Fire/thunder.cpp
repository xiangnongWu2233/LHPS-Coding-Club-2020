#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

thunder::thunder() : fire()
{
    name = "Thunder";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[46m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 5;
}

void thunder::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), players[id].ele->ultimateCost);
    players[id].energy -= players[id].ele->ultimateCost;
    sleep(1);
    printf("Tremendous Thunderbolt!!!\n");
    sleep(2);
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != id)
            players[i].receiveDamage(id, players[id].attack);
    sleep(1);
}