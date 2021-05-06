#ifndef GRASSELEMENT_H
#define GRASSELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class grass : public element
{
public:
    grass();
};

class earth : public grass
{
public:
    earth();
    //virtual void skill();
};

class poison : public grass
{
public:
    poison();
    //virtual void skill();
};

#endif