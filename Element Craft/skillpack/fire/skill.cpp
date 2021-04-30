#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "../../game.h"
#include "skill.h"
using namespace std;

bombing::bombing()
{
    name = "Bombing";
    CD = 2;
    level = 1;
}

void use()
{
    printf("Bombing!\n");
    sleep(1);
}