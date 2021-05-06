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

void wind::skill()
{
    if (players[user].energy >= 4)
        stormrage();
}

void wind::stormrage()
{
    printf("Stormrage!!!\n");
    sleep(2);
    printf("Choose your target: \n");
    string t;
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != user)
            printf("%d %s\n", players[i].user, players[i].name.c_str());
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == user)
    {
        printf("Please enter a valid target: \n");
        sleep(2);
        cin >> t;
    }
    players[stoi(t)].receiveDamage(user, players[user].defense + 3);
    printf("%d %s in air!\n", stoi(t), players[stoi(t)].name.c_str());
    players[stoi(t)].lock += 1;
    sleep(1);
}