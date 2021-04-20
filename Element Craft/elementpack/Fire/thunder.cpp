#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

thunder::thunder() : element(2)
{
    name = "Thunder";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[46m");
    cout << name;
    printf("\033[0m\n");
}