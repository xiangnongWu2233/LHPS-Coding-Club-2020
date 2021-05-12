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

void ice::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 20)
        normalAttack(target);
    else if (coin > 20 && coin <= 40)
        freeze(target, 1);
    else if (coin > 40 && coin <= 60)
    {
        int t = 0;
        for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
            if (i != user && players[i].status_bar.frozen > 0)
            {
                t = 1;
                break;
            }
        if (t == 1)
            frostStrike(target);
    }
    else if (coin > 60 && coin <= 80)
        glacier();
}

void ice::freeze(int target, int time)
{

    printf("Freeze %d %s !\n", target, players[target].name.c_str());
    if (players[target].status_bar.trial == 0)
    {
        players[target].status_bar.frozen += time;
        players[target].status_bar.control = 1;
    }
}

void ice::frostStrike(int target)
{
    printf("Frost-Strike!\n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
    {
        if (players[i].status_bar.frozen > 0 && i != user)
            players[i].receiveDamage(user, players[user].level + players[user].attack);
    }
}

void ice::glacier()
{
    printf("Glacier!!!\n");
    sleep(2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            freeze(i, 3);
            players[i].receiveDamage(user, 3 + players[user].level);
        }
    sleep(1);
}