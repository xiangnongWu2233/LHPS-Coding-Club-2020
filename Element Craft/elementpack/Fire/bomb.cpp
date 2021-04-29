#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

bomb::bomb() : fire()
{
    name = "Bomb";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 6;
}

void bomb::skill()
{
}

void bomb::ultimate()
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
    printf("Devastate!!!\n");
    players[stoi(t)].receiveDamage(id, 8 + int((players[stoi(t)].ele->hpMaximum[players[stoi(t)].level] - players[stoi(t)].hp) / 3));
    sleep(1);
}
