#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "grassElement.h"
using namespace std;

poison::poison() : grass()
{
    name = "Poison";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[43m");
    cout << name;
    printf("\033[0m\n");
}
