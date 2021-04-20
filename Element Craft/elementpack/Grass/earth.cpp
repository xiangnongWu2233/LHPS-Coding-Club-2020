#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

earth::earth() : element("3")
{
    name = "Earth";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[34m\033[42m");
    cout << name;
    printf("\033[0m\n");
}