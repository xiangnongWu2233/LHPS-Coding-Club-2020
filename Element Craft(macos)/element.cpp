#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include "game.h"
using namespace std;

void element::normalAttack(int target)
{
    int t = players[target].hp;
    players[target].receiveDamage(user, players[user].attack);
    if (t > players[target].hp)
        players[user].gainExp(1);
}