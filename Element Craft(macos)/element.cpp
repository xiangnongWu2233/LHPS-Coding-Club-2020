#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include "game.h"
using namespace std;

void element::normalAttack(int target)
{
    players[target].receiveDamage(user, players[user].attack);
    players[user].gainExp(1);
}

void element::skill(int target)
{
    normalAttack(target);
}