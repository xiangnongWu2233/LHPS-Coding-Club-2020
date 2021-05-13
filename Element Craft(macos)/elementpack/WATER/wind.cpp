#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "waterElement.h"
using namespace std;

wind::wind() : water()
{
    name = "Wind";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[46m");
    cout << name;
    printf("\033[0m\n");
}

void wind::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 10)
        cyclone();
    else if (coin > 10 && coin <= 50)
        hurricane(target);
    else if (coin > 50 && coin <= 60)
        stormrage(target);
    else if (coin > 60 && coin <= 80)
        normalAttack(target);
    if (coin >= 1 && coin <= 60)
        players[user].gainExp(1);
}

void wind::cyclone()
{
    printf("Cyclone!\n");
    sleep(1);
    printf("%d %s + %d shield\n", user, players[user].name.c_str(), players[user].level);
    players[user].status_bar.shield += 2;
}

void wind::hurricane(int target)
{
    printf("Hurricane!\n");
    sleep(1);
    players[target].receiveDamage(user, 1 + players[user].level);
    if (players[target].last != user)
        players[players[target].last].receiveDamage(user, 1 + 2 * players[user].level);
    if (players[target].next != user)
        players[players[target].next].receiveDamage(user, 1 + 2 * players[user].level);
}

void wind::stormrage(int target)
{
    printf("Stormrage!!!\n");
    sleep(1);
    players[target].receiveDamage(user, players[user].defense + players[user].level + 3);

    if (players[target].status_bar.trial == 0 && players[target].status_bar.frozen == 0)
    {
        printf("%d %s in air!\n", target, players[target].name.c_str());
        players[target].status_bar.inAir = 2;
        players[target].status_bar.control = 1;
    }
    sleep(1);
}