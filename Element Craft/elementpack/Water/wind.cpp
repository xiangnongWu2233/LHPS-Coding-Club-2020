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
}

void wind::cyclone(int target)
{
    printf("Cyclone!\n");
    printf("%d %s + %d shield\n", user, players[user].name.c_str(), players[user].level);
    players[user].status_bar.shield += 3;
    players[target].receiveDamage(user, players[user].attack);
}

void wind::hurricane(int target)
{
    /*players[target].receiveDamage(user);
    players*/
}

void wind::stormrage(int target)
{
    printf("Stormrage!!!\n");
    sleep(2);
    players[target].receiveDamage(user, players[user].defense + 3);
    printf("%d %s in air!\n", target, players[target].name.c_str());
    sleep(1);
}