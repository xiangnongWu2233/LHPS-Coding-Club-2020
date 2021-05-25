#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "lightElement.h"
using namespace std;

spirit::spirit() : light()
{
    name = "Spirit";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[91m\033[48m");
    cout << name;
    printf("\033[0m\n");
}

void spirit::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 20)
    {
        if (bless > 0)
        {
            players[user].attack++;
            normalAttack(target);
            players[user].attack--;
            bless--;
        }
        else
            normalAttack(target);
    }
    else if (coin > 20 && coin <= 50)
        soulFerry();
    else if (coin > 50 && coin <= 70)
        angelBless();
    else if (coin > 70)
        callFromsoul(target);
    if (coin > 20)
        players[user].gainExp(1);
}

void spirit::soulFerry()
{
    printf("Soul Ferry!\n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
            players[i].receiveDamage(user, players[user].attack + players[user].level);
    sleep(1);
}

void spirit::angelBless()
{
    printf("Angel Bless!\n");
    players[user].restoreHP(int((players[user].ele->hpMaximum[players[user].level] - players[user].hp) / 6) + 1);
    bless += 2;
    sleep(1);
}

void spirit::callFromsoul(int target)
{
    printf("Call From the Soul!!!\n");
    sleep(2);
    printf("%d %s became fragile!\n", target, players[target].name.c_str());
    players[target].status_bar.soulpiece += 2;
    players[target].receiveDamage(user, players[target].defense + players[target].level);
    bless++;
    sleep(1);
}
