#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

demon::demon() : element(4)
{
    name = "Demon";
    skillNum = 3;
}