#ifndef DARKELEMENT_H
#define DARKELEMENT_H
#include <iostream>
#include <cstdio>
#include "../../game.h"

class dark : public element
{
public:
    dark();
    virtual void skill(int target);
    void cut(int target);
};

class demon : public dark
{
public:
    int sigils;
    demon();
    virtual void skill(int target);
    void blackSigil();
    void devour(int target);
    void sixFoldcurse();
};

class ghost : public dark
{
public:
    ghost();
    virtual void skill(int target);
    void terrify(int target);
    void drainSoul(int target);
    void mentalConfusion();
};

#endif