#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../element.h"
using namespace std;

ghost::ghost(int i) : element(i, "5")
{
    name = "Ghost";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[30m\033[44m");
    cout << name;
    printf("\033[0m\n");
    ultracost = 4;
}

void ghost::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), players[id].ele->ultracost);
    players[id].energy -= players[id].ele->ultracost;
    sleep(1);
    printf("Choose your target: \n");

    printf("Soul Strike!\n");
}