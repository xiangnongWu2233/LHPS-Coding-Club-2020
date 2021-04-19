#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

poison::poison() : element(3)
{
    name = "Poison";
    skillNum = 3;
}