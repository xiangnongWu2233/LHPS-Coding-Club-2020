#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../element.h"
using namespace std;

thunder::thunder() : element("2")
{
    name = "Thunder";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[46m");
    cout << name;
    printf("\033[0m\n");
    ultracost = 4;
}

void thunder::ultimate(int attacker)
{
    printf("%d %s - 4 energies! \n", players[attacker].id, players[attacker].name.c_str());
    players[attacker].energy -= 4;
    sleep(1);
    printf("Tremendous Thunderbolt!!!");
    sleep(2);
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != attacker)
            players[i].receiveDamage(2 + players[attacker].level);
    sleep(1);
}