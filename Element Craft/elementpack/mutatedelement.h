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
};

class wind : public water
{
public:
    wind();
    virtual void ultimate();
};

class thunder : public fire
{
public:
    thunder();
    virtual void ultimate();
};

class bomb : public fire
{
public:
    bomb();
    virtual void ultimate();
};

class earth : public grass
{
public:
    earth();
    virtual void ultimate();
};

class poison : public grass
{
public:
    poison();
    virtual void ultimate();
};

class divine : public light
{
public:
    divine();
    virtual void ultimate();
};

class spirit : public light
{
public:
    spirit();
    virtual void ultimate();
};

class demon : public dark
{
public:
    int sigil;
    demon();
    virtual void ultimate();
};

class ghost : public dark
{
public:
    ghost();
    virtual void ultimate();
};

#endif