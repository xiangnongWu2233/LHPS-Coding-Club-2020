#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "grassElement.h"
using namespace std;

earth::earth() : grass()
{
    name = "Earth";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[42m");
    cout << name;
    printf("\033[0m\n");
}

void earth::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 20)
        normalAttack(target);
    else if (coin > 20 && coin <= 40)
        entanglingRoots();
    else if (coin > 40 && coin <= 70)
    {
        for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
            if (i != user)
            {
                if (players[i].status_bar.seeds > 0)
                {
                    rejuvenation();
                    return;
                }
            }
        allFlowersbloom();
    }
    else if (coin > 70)
        allFlowersbloom();
    if (coin > 20)
        players[user].gainExp(1);
}

void earth::entanglingRoots()
{
    printf("Entangling Roots!\n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            players[i].receiveDamage(user, players[user].level + players[i].defense);
            if (players[i].status_bar.trial == 0 && players[i].status_bar.frozen == 0 && players[i].status_bar.terrified == 0)
            {
                players[i].status_bar.inAir = 0;
                printf("%d %s was stunned!\n", i, players[i].name.c_str());
                players[i].status_bar.stunned += 2;
                players[i].status_bar.control = 1;
            }
        }
    sleep(1);
}

void earth::rejuvenation()
{
    printf("Rejuvenation!\n");
    int num = 0;
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            num += players[i].status_bar.seeds;
            players[i].status_bar.seeds = 0;
        }
    players[user].restoreHP(num * 2);
    sleep(1);
}

void earth::allFlowersbloom()
{
    printf("All Flowers Bloom!!!\n");
    sleep(2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            players[i].receiveDamage(user, players[i].status_bar.seeds * 3 + 3);
            players[i].status_bar.seeds++;
            if (players[i].status_bar.seeds > 3)
                players[i].status_bar.seeds = 3;
        }
    sleep(1);
}