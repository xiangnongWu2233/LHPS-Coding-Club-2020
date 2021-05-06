#ifndef WATERELEMENT_H
#define WATERELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class water : public element
{
public:
    water();
    void flow();
    virtual void skill();
};

class ice : public water
{
public:
    ice();
    virtual void skill();
    void freeze(int target);
    void frostStrike();
    void glacier();
};

class wind : public water
{
public:
    wind();
    virtual void skill();
    void cyclone();
    void Hurricane();
    void stormrage();
};

#endif