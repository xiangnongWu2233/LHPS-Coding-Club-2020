#ifndef ELEMENT_H
#define ELEMENT_H

#include "../game.h"
#include <cstring>
#include <cstdio>

class ice : public element
{
public:
    ice();
    virtual void ultimate();
};

class wind : public element
{
public:
    wind();
    virtual void ultimate();
};

class thunder : public element
{
public:
    thunder();
    virtual void ultimate();
};

class bomb : public element
{
public:
    bomb();
    virtual void ultimate();
};

class earth : public element
{
public:
    earth();
    virtual void ultimate();
};

class poison : public element
{
public:
    poison();
    virtual void ultimate();
};

class divine : public element
{
public:
    divine();
    virtual void ultimate();
};

class spirit : public element
{
public:
    spirit();
    virtual void ultimate();
};

class demon : public element
{
public:
    demon();
    virtual void ultimate();
};

class ghost : public element
{
public:
    ghost();
    virtual void ultimate();
};

#endif