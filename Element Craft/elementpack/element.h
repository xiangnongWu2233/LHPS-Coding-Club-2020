#ifndef ELEMENT_H
#define ELEMENT_H

#include "../game.h"
#include <cstring>
#include <cstdio>

class ice : public element
{
public:
    ice();
    virtual void ultimate(int attacker);
};

class wind : public element
{
public:
    wind();
    virtual void ultimate(int attacker);
};

class thunder : public element
{
public:
    thunder();
    virtual void ultimate(int attacer);
};

class bomb : public element
{
public:
    bomb();
    virtual void ultimate(int attacker);
};

class earth : public element
{
public:
    earth();
    virtual void ultimate(int attacker);
};

class poison : public element
{
public:
    poison();
    virtual void ultimate(int attacker);
};

class divine : public element
{
public:
    divine();
    virtual void ultimate(int attacker);
};

class spirit : public element
{
public:
    spirit();
    virtual void ultimate(int attacker);
};

class demon : public element
{
public:
    demon();
    virtual void ultimate(int attacker);
};

class ghost : public element
{
public:
    ghost();
    virtual void ultimate(int attacker);
};

#endif