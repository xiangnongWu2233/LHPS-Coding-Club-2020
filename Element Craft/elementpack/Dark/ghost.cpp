#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

ghost::ghost() : dark()
{
    name = "Ghost";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[30m\033[44m");
    cout << name;
    printf("\033[0m\n");
    ultimateCost = 5;
}

void ghost::ultimate()
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
    printf("Soul Strike!!!\n");
    printf("%d %s defense - 1!\n", stoi(t), players[stoi(t)].name.c_str());
    players[stoi(t)].defense -= 1;
    players[stoi(t)].receiveDamage(id, players[id].attack);
    sleep(1);
}