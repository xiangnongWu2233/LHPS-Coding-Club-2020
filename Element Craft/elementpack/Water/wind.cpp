#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

wind::wind() : water()
{
    name = "Wind";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[46m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 5;
}

void wind::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), ultimateCost);
    players[id].energy -= ultimateCost;
    sleep(1);
    printf("Choose your target: \n");
    string t;
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != id)
            printf("%d %s\n", players[i].id, players[i].name.c_str());
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == id)
    {
        printf("Please enter a valid target: \n");
        sleep(2);
        cin >> t;
    }
    sleep(2);
    printf("Stormrage!!!\n");
    players[stoi(t)].receiveDamage(id, players[id].defense + 3);
    printf("%d %s in air!\n", stoi(t), players[stoi(t)].name.c_str());
    players[stoi(t)].lock += 1;
    sleep(1);
}