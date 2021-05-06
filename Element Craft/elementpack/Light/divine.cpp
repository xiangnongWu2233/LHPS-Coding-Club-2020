#include <iostream>
#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "lightElement.h"
using namespace std;

divine::divine() : light()
{
    name = "Divine";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[48m");
    cout << name;
    printf("\033[0m\n");
}
