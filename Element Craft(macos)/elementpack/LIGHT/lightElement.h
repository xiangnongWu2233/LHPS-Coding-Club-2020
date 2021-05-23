#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class light : public element
{
public:
    light();
    virtual void skill(int target);
    void shine();
};

class divine : public light
{
public:
    int courage;
    divine();
    virtual void skill(int target);
    void divineGlory();
    void judgement(int);
    void justice(int target);
};

class spirit : public light
{
public:
    int bless;
    spirit();
    virtual void skill(int target);
    void soulFerry();
    void angelBless();
    void callFromsoul(int target);
};

#endif