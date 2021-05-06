#include <iostream>
#include <unistd.h>
#include "../../game.h"
#include "waterElement.h"

using namespace std;

water::water()
{
    name = "Water";
    baseAttack = 2;
    baseDefense = 5;
    baseHP = 15;
    energyMaximum[1] = 2;
    for (int i = 2; i <= 10; i++)
        energyMaximum[i] = energyMaximum[i - 1] + 3;
}

void water::flow()
{
    printf("Flow!\n");
    for (int i = 1; i <= n; i++)
    {
        if (players[i].hp > 0 && i != user)
            players[i].receiveDamage(user, players[i].level);
    }
    sleep(1);
}

void water::skill()
{
    flow();
}