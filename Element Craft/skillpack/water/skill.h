#include <iostream>
#include <cstdio>
#include "../../game.h"

class flow : public skill
{
public:
    flow(int id);
    virtual void use();
};

class glacier : public skill
{
public:
    int cost;
    glacier(int id);
    virtual void use();
};

class stormrage : public skill
{
public:
    int cost;
    stormrage(int id);
    virtual void use();
};