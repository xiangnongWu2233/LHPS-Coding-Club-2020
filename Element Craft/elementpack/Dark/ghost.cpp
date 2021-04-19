#include <cstdio>
#include <cstring>
#include "../../game.h"
#include "../element.h"
using namespace std;

ghost::ghost() : element(4)
{
    name = "Ghost";
    skillNum = 3;
}