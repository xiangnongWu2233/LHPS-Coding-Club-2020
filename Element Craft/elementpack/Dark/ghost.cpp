#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../element.h"
using namespace std;

ghost::ghost() : element("5")
{
    name = "Ghost";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[30m\033[44m");
    cout << name;
    printf("\033[0m\n");
    skillcost[1] = 4;
}

void ghost::ultimate(int attacker)
{
    printf("%d %s - 5 energies! \n", players[attacker].id, players[attacker].name.c_str());
    sleep(1);
    printf("Soul Strike!!!");
    sleep(2);
    printf("Choose your target:");
    sleep(1);
}