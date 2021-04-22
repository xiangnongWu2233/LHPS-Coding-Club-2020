#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

bomb::bomb() : element("2")
{
    name = "Bomb";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
    ultracost = 5;
}

void bomb::ultimate(int attacker)
{
    printf("%d %s - 4 energies! \n", players[attacker].id, players[attacker].name.c_str());
    players[attacker].energy -= 4;
    sleep(1);
    printf("Choose your target: ");
    string t;
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 || i == attacker)
            printf("%d %s\n", players[i].id, players[i].name.c_str());
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == attacker)
    {
        printf("Please enter a valid target: \n");
        sleep(2);
        cin >> t;
    }
    sleep(2);
    printf("Devastate!");
    players[stoi(t)].receiveDamage(10 + players[attacker].level);
    sleep(1);
}