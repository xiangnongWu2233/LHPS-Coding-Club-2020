#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "fireElement.h"
using namespace std;

thunder::thunder() : fire()
{
    name = "Thunder";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[46m");
    cout << name;
    printf("\033[0m\n");
}

void thunder::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 20)
        normalAttack(target);
    else if (coin > 20 && coin <= 50)
        thunderStrike(target);
    else if (coin > 50 && coin <= 60)
        ballLightning();
    else if (coin > 60 && coin <= 80)
        tremendousThunderbolt();
    if (coin > 20 && coin <= 80)
        players[user].gainExp(1);
}

void thunder::thunderStrike(int target)
{
    printf("Thunder Strike!\n");
    players[target].receiveDamage(user, players[user].attack + players[target].defense);
    if (players[target].status_bar.trial == 0 && players[target].status_bar.frozen == 0)
    {
        players[target].status_bar.inAir = 0;
        printf("%d %s Stunned!\n", target, players[target].name.c_str());
        players[target].status_bar.stunned += 1;
        players[target].status_bar.control = 1;
    }
    sleep(1);
}

void thunder::ballLightning()
{
    printf("Ball Lightning!\n");
    players[user].restoreHP(players[user].level);
    sleep(1);
}

void thunder::tremendousThunderbolt()
{
    printf("Tremendous Thunderbolt!!!\n");
    sleep(2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next)
    {
        if (i != user)
        {
            players[i].receiveDamage(user, players[user].level * 2 + players[user].attack + players[i].defense);
        }
    }
}