#ifndef GRASSELEMENT_H
#define GRASSELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class grass : public element
{
public:
    grass();
    virtual void skill(int target);
    void grow();
};

class earth : public grass
{
public:
    earth();
    virtual void skill(int target);
    void root();
};

class poison : public grass
{
public:
    poison();
    virtual void skill(int target);
    void poisoning(int target, int time, int damage);
    void poisonGas(int target);
    void virusAttack(int target);
};

#endif