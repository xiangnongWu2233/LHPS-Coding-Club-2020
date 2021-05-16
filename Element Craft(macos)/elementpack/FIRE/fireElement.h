#ifndef FIREELEMENT_H
#define FIREELEMENT_H

#include <iostream>
#include <cstdio>
#include "../../game.h"

class fire : public element
{
public:
    fire();
    virtual void skill(int target);
    void fireball(int target);
};

class thunder : public fire
{
public:
    thunder();
    virtual void skill(int target);
    void thunderStrike(int target);
    void ballLightning();
    void tremendousThunderbolt();
};

class bomb : public fire
{
public:
    int missles;
    bomb();
    virtual void skill(int target);
    void missle(int target);
    void devastate(int target);
    void nuclearStrike();
};

#endif