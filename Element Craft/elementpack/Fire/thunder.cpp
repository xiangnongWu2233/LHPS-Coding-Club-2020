#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "fireElement.h"
using namespace std;

thunder::thunder() : fire()
{
    name = "Thunder";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[46m");
    cout << name;
    printf("\033[0m\n");
}
