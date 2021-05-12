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
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 4; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i;
    for (int i = 5; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 6;
}

void water::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 60)
        normalAttack(target);
    else if (coin > 60)
        flow();
}

void water::flow()
{
    printf("Flow!\n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
    {
        if (i != user)
            players[i].receiveDamage(user, players[user].level);
    }
    sleep(1);
}