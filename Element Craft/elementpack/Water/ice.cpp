#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../element.h"
using namespace std;

ice::ice(int i) : element(i, "1")
{
    name = "Ice";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[46m");
    cout << name;
    printf("\033[0m\n");
    ultracost = 4;
}

void ice::ultimate()
{
    printf("Freeze!!!!");
    sleep(1);
}