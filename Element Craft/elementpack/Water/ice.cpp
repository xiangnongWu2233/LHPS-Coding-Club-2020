#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "waterElement.h"
using namespace std;

ice::ice() : water()
{
    name = "Ice";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[46m");
    cout << name;
    printf("\033[0m\n");
}

void ice::skill()
{
    int coin;
    coin = rand() % 100 + 1;
    if (coin >= 70)
    {
        }
    if (players[user].energy >= 4)
        glacier();
}

void ice::freeze(int target)
{
    printf("Freeze %d %s !\n", target, players[target].name);
    if (players[target].status_bar.trial == 0)
        players[target].status_bar.frozen = 2;
}

void ice::frostStrike()
{
}

void ice::glacier()
{
    printf("Glacier!!!\n");
    sleep(2);
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != user)
        {
            freeze(i);
            players[i].receiveDamage(user, players[user].level);
        }
    sleep(1);
}