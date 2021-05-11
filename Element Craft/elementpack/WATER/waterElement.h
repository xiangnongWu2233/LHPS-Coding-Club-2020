#ifndef WATERELEMENT_H
#define WATERELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class water : public element
{
public:
    water();
    virtual void skill(int target);
    void flow();
};

class ice : public water
{
public:
    ice();
    virtual void skill(int target);
    void freeze(int target, int time);
    void frostStrike(int target);
    void glacier();
};

class wind : public water
{
public:
    wind();
    virtual void skill(int target);
    void cyclone(int target);
    void hurricane(int target);
    void stormrage(int target);
};

#endif