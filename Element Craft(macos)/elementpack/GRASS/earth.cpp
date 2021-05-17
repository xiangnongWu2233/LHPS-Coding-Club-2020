#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "grassElement.h"
using namespace std;

earth::earth() : grass()
{
    name = "Earth";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[42m");
    cout << name;
    printf("\033[0m\n");
}

void earth::skill(int target)
{
}