#ifndef DARKELEMENT_H
#define DARKELEMENT_H
#include <iostream>
#include <cstdio>
#include "../../game.h"

class dark : public element
{
public:
    dark();
};

class demon : public dark
{
public:
    int sigil;
    demon();
    //virtual void skill();
};

class ghost : public dark
{
public:
    ghost();
    //virtual void skill();
};

#endif