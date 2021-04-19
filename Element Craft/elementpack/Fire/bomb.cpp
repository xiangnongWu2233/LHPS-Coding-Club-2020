#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

bomb::bomb() : element(2)
{
    name = "Bomb";
    skillNum = 3;
}