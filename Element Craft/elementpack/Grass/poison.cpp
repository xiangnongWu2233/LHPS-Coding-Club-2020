#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

poison::poison() : element("3")
{
    name = "Poison";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[32m\033[43m");
    cout << name;
    printf("\033[0m\n");
}