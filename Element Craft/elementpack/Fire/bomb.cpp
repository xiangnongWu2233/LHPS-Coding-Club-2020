#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../element.h"
using namespace std;

bomb::bomb(int i) : element(i, "2")
{
    name = "Bomb";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 7;
}

void bomb::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), players[id].ele->ultimateCost);
    players[id].energy -= players[id].ele->ultimateCost;
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
    players[stoi(t)].receiveDamage(id, 10 + players[id].attack);
    sleep(1);
}