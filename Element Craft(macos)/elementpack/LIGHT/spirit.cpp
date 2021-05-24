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
    if (coin <= 40)
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
    else if (coin > 40 && coin <= 60)
        soulFerry();
    else if (coin > 60 && coin <= 80)
        angelBless();
    else if (coin > 80)
        callFromsoul(target);
    if (coin > 40)
        players[user].gainExp(1);
}

void spirit::soulFerry()
{
    printf("Soul Ferry!\n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
            players[i].receiveDamage(user, players[user].attack);
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
