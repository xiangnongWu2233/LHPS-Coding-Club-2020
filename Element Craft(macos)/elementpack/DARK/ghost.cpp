#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "darkElement.h"
using namespace std;

ghost::ghost() : dark()
{
    name = "Ghost";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[30m\033[44m");
    cout << name;
    printf("\033[0m\n");
}

void ghost::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 10)
        normalAttack(target);
    else if (coin > 10 && coin <= 30)
    {
        terrify(target);
        players[target].defense--;
        players[user].ele->normalAttack(target);
        players[target].defense++;
    }
    else if (coin > 30 && coin <= 70)
        drainSoul(target);
    else if (coin > 70)
    {
        if (players[user].hp >= 5)
            mentalConfusion();
        else
            terrify(target);
    }
    if (coin > 30)
        players[user].gainExp(1);
}

void ghost::terrify(int target)
{
    printf("Terrify!\n");
    if (players[target].status_bar.trial == 0 && players[target].status_bar.frozen == 0)
    {
        printf("%d %s was terrified!\n", target, players[target].name.c_str());
        players[target].status_bar.terrified++;
    }
    sleep(1);
}

void ghost::drainSoul(int target)
{
    printf("Drain Soul!\n");
    players[target].receiveDamage(user, players[user].level * 2 + players[user].attack);
    players[user].restoreHP(players[user].level);
    sleep(1);
}

void ghost::mentalConfusion()
{
    printf("Mental Confusion!!!\n");
    sleep(2);
    players[user].receiveDamage(user, players[user].hp * 0.2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            players[i].receiveDamage(user, players[user].attack * 3 + players[user].level);
            terrify(i);
        }
    sleep(1);
}