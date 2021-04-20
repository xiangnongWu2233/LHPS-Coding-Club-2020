#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

divine::divine() : element(4)
{
    name = "Divine";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[48m");
    cout << name;
    printf("\033[0m\n");
}