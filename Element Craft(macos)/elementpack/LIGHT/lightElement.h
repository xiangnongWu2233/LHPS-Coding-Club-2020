#ifndef LIGHTELEMENT_H
#define LIGHTELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class light : public element
{
public:
    light();
};

class divine : public light
{
public:
    divine();
    //virtual void skill();
};

class spirit : public light
{
public:
    spirit();
    //virtual void skill();
};

#endif