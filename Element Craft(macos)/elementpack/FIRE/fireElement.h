#ifndef FIREELEMENT_H
#define FIREELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class fire : public element
{
public:
    fire();
    //virtual void skill();
};

class thunder : public fire
{
public:
    thunder();
    //virtual void skill();
};

class bomb : public fire
{
public:
    bomb();
    //virtual void skill();
};

#endif