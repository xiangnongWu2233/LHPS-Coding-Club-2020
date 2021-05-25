#include <iostream>
#include <unistd.h>
#include "../../game.h"
#include "darkElement.h"

using namespace std;

dark::dark()
{
    name = "Dark";
    baseAttack = 4;
    baseDefense = 3;
    baseHP = 30;
    hpMaximum[1] = baseHP;
    for (int i = 2; i <= 5; i++)
        hpMaximum[i] = hpMaximum[i - 1] + i + 2;
    for (int i = 6; i <= 10; i++)
        hpMaximum[i] = hpMaximum[i - 1] + 4;
}

void dark::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 60)
        normalAttack(target);
    else if (coin > 60)
        cut(target);
}

void dark::cut(int target)
{
    printf("Cut!\n");
    players[user].attack += 2;
    players[user].ele->normalAttack(target);
    players[user].attack -= 2;
    sleep(1);
}