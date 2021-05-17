#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "../../game.h"
#include "fireElement.h"

using namespace std;

fire::fire()
{
    name = "Fire";
    baseAttack = 5;
    baseDefense = 2;
    baseHP = 20;
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 5; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i - 1;
    for (int i = 6; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 3;
}

void fire::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 70)
        normalAttack(target);
    else if (coin > 70)
        fireball(target);
    if (coin > 70)
        players[user].gainExp(1);
}

void fire::fireball(int target)
{
    printf("Fireball!\n");
    players[target].receiveDamage(user, players[user].attack + 2);
}