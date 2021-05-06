#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "lightElement.h"
using namespace std;

spirit::spirit() : light()
{
    name = "Spirit";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[91m\033[48m");
    cout << name;
    printf("\033[0m\n");
}
