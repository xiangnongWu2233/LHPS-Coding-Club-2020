#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include "../game.h"

class bombing : public skill
{
    bombing();
    virtual void use();
};

class torpedo : public skill
{
    torpedo();
    virtual void use();
};

class devastate : public skill
{
    devastate();
    virtual void use();
};

#endif