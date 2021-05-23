#include <iostream>
#include <cstdio>
#include "../../game.h"
#include "lightElement.h"

using namespace std;

light::light()
{
    name = "Light";
    baseAttack = 3;
    baseDefense = 4;
    baseHP = 30;
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 5; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i + 2;
    for (int i = 6; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 4;
}

void light::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 60)
        normalAttack(target);
    else if (coin > 60)
        shine();
}

void light::shine()
{
    printf("Shine!\n");
    printf("%d %s + 1 shield\n", user, players[user].name.c_str());
    players[user].status_bar.shield++;
    players[user].gainExp(1);
}