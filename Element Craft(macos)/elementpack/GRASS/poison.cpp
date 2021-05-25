#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "grassElement.h"
using namespace std;

poison::poison() : grass()
{
    name = "Poison";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[43m");
    cout << name;
    printf("\033[0m\n");
}

void poison::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 40)
    {
        normalAttack(target);
        if (players[target].status_bar.poisoning[0] == 0)
            poisoning(target, 2, 2);
    }
    else if (coin > 40 && coin <= 70)
        poisonGas(target);
    else if (coin > 70)
        virusAttack(target);
    if (coin > 40)
        players[user].gainExp(1);
}

void poison::poisoning(int target, int time, int damage)
{
    printf("%d %s was poisoned!\n", target, players[target].name.c_str());
    players[target].status_bar.poisoning[0] = user;
    players[target].status_bar.poisoning[1] = time;
    players[target].status_bar.poisoning[2] = damage;
    players[target].status_bar.damageOvertime = 1;
    sleep(1);
}

void poison::poisonGas(int target)
{
    printf("Poison Gas!\n");
    players[target].receiveDamage(user, players[user].attack + players[user].defense);
    poisoning(target, 3, players[user].level + players[user].attack);
    for (int i = players[target].last; i != user; i = players[i].last)
    {
        players[i].receiveDamage(user, players[user].attack);
        poisoning(i, 3, players[user].level + players[user].attack - 2);
    }
    for (int i = players[target].next; i != user; i = players[i].next)
    {
        players[i].receiveDamage(user, players[user].attack);
        poisoning(i, 3, players[user].level + players[user].attack - 2);
    }
    sleep(1);
}

void poison::virusAttack(int target)
{
    printf("Virus Attack!!!\n");
    sleep(2);
    players[target].receiveDamage(user, players[target].status_bar.poisoning[0] * 5 + players[user].level * 2);
    players[user].restoreHP(players[target].status_bar.poisoning[0] * 3 + 1);
    if (players[target].hp <= 0)
        players[user].restoreHP(players[user].level * 2);
    sleep(1);
}
