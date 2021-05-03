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
        if (i != id && players[i].hp > 0)
            printf("%d %s\n", i, players[i].name.c_str());
    cout << endl;
    string t;
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == id)
    {
        if (stoi(t) == id)
            printf("Can't attack yourself!\n");
        else
            printf("Please enter a valid target!\n");
        sleep(2);
        cin >> t;
    }
    players[stoi(t)].receiveDamage(id, players[id].attack);
    players[id].gainEnergy(1);
}

void element::skill()
{
    srand(time(0));
    int coin = rand() % 2 + 1;
    if (coin == 1)
        primaryAbility();
    else
        secondaryAbility();
    cout << endl;
    sleep(1);
}