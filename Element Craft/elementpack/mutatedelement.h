#ifndef ELEMENT_H
#define ELEMENT_H

#include "../game.h"
#include "baseelement.h"
#include <cstring>
#include <cstdio>

class ice : public water
{
public:
    ice();
    virtual void ultimate();
    //virtual void skill();
    void freeze();
    void frostStrike();
};

class wind : public water
{
public:
    wind();
    virtual void ultimate();
    //virtual void skill();
    void cyclone();
    void Hurricane();
};

class thunder : public fire
{
public:
    thunder();
    virtual void ultimate();
    //virtual void skill();
};

class bomb : public fire
{
public:
    bomb();
    virtual void ultimate();
    //virtual void skill();
};

class earth : public grass
{
public:
    earth();
    virtual void ultimate();
    //virtual void skill();
};

class poison : public grass
{
public:
    poison();
    virtual void ultimate();
    //virtual void skill();
};

class divine : public light
{
public:
    divine();
    virtual void ultimate();
    //virtual void skill();
};

class spirit : public light
{
public:
    spirit();
    virtual void ultimate();
    //virtual void skill();
};

class demon : public dark
{
public:
    int sigil;
    demon();
    virtual void ultimate();
    //virtual void skill();
};

class ghost : public dark
{
public:
    ghost();
    virtual void ultimate();
    //virtual void skill();
};

#endif