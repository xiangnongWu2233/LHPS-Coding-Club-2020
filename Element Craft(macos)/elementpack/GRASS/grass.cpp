#include <iostream>
#include <unistd.h>
#include "../../game.h"
#include "grassElement.h"

using namespace std;

grass::grass()
{
    name = "Grass";
    baseAttack = 3;
    baseDefense = 3;
    baseHP = 35;
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 6; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i;
    for (int i = 7; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 6;
}

void grass::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 60)
        normalAttack(target);
    else if (coin > 60)
        grow();
}

void grass::grow()
{
    printf("Grow!\n");
    for (int i = 1; i <= 10; i++)
        hpMaximum[i] += 1;
    players[user].gainExp(1);
    sleep(1);
}