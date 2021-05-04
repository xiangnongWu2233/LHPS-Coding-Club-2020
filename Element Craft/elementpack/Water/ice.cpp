#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

ice::ice() : water()
{
    name = "Ice";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[46m");
    cout << name;
    printf("\033[0m\n");
}
