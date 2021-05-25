#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "lightElement.h"
using namespace std;

divine::divine() : light()
{
    name = "Divine";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[48m");
    cout << name;
    printf("\033[0m\n");
}

void divine::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 10)
        normalAttack(target);
    else if (coin > 10 && coin <= 30)
        divineGlory();
    else if (coin > 30 && coin <= 70)
        judgement(target);
    else if (coin > 70)
        justice(target);
    if (coin > 10)
        players[user].gainExp(1);
    if (courage > 0)
    {
        players[user].restoreHP(players[user].level);
        courage--;
    }
}

void divine::divineGlory()
{
    printf("Divine Glory!\n");
    int last = players[user].last, next = players[user].next;
    players[last].receiveDamage(user, players[user].level * 2 + players[last].defense);
    players[next].receiveDamage(user, players[user].level * 2 + players[next].defense);
    sleep(1);
}

void divine::judgement(int target)
{
    printf("Judgement!\n");
    players[target].receiveDamage(user, players[user].level * 3 + players[user].attack);
    if (players[target].hp <= players[target].ele->hpMaximum[players[target].level] / 9)
    {
        players[target].receiveDamage(user, 999 + players[target].defense);
        return;
    }
    sleep(1);
}

void divine::justice(int target)
{
    printf("Justice!!!\n");
    sleep(2);
    printf("%d %s was on trial!\n", target, players[target].name.c_str());
    players[target].status_bar.trial = 2;
    players[target].status_bar.control = 1;
    courage += 3;
    sleep(1);
}