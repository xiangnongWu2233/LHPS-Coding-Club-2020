#ifndef ELEMENT_H
#define ELEMENT_H

#include "../game.h"
#include <cstring>
#include <cstdio>

class ice : public element
{
public:
    ice(int i);
    virtual void ultimate();
};

class wind : public element
{
public:
    wind(int i);
    virtual void ultimate();
};

class thunder : public element
{
public:
    thunder(int i);
    virtual void ultimate();
};

class bomb : public element
{
public:
    bomb(int i);
    virtual void ultimate();
};

class earth : public element
{
public:
    earth(int i);
    virtual void ultimate();
};

class poison : public element
{
public:
    poison(int i);
    virtual void ultimate();
};

class divine : public element
{
public:
    divine(int i);
    virtual void ultimate();
};

class spirit : public element
{
public:
    spirit(int i);
    virtual void ultimate();
};

class demon : public element
{
public:
    int sigil;
    demon(int i);
    virtual void ultimate();
};

class ghost : public element
{
public:
    ghost(int i);
    virtual void ultimate();
};

#endif