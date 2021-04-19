#ifndef ELEMENT_H
#define ELEMENT_H

#include "../game.h"
#include <cstring>
#include <cstdio>

class ice : public element
{
public:
    ice();
};

class wind : public element
{
public:
    wind();
};

class thunder : public element
{
public:
    thunder();
};

class bomb : public element
{
public:
    bomb();
};

class earth : public element
{
public:
    earth();
};

class poison : public element
{
public:
    poison();
};

class divine : public element
{
public:
    divine();
};

class spirit : public element
{
public:
    spirit();
};

class demon : public element
{
public:
    demon();
};

class ghost : public element
{
public:
    ghost();
};

#endif