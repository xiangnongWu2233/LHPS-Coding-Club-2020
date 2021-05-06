#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include "game.h"
using namespace std;

void element::normalAttack()
{
    printf("Choose your target: \n");
    for (int i = 1; i <= n; i++)
        if (i != user && players[i].user > 0)
            printf("%d %s\n", i, players[i].name.c_str());
    cout << endl;
    string t;
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == user)
    {
        if (stoi(t) == user)
            printf("Can't attack yourself!\n");
        else
            printf("Please enter a valid target!\n");
        sleep(2);
        cin >> t;
    }
    players[stoi(t)].receiveDamage(user, players[user].attack);
    players[user].gainEnergy(1);
}

void element::skill()
{
}