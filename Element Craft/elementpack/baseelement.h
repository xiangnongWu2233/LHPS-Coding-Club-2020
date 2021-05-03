#ifndef BASEELEMENT_H
#define BASEELEMENT_H

#include "../game.h"
class water : public element
{
public:
    water();
    virtual void primaryAbility();
    virtual void secondaryAbility();
};

class fire : public element
{
public:
    fire();
    virtual void primaryAbility();
    virtual void secondaryAbility();
};

class grass : public element
{
public:
    grass();
    virtual void primaryAbility();
    virtual void secondaryAbility();
};

class light : public element
{
public:
    light();
    virtual void primaryAbility();
    virtual void secondaryAbility();
};

class dark : public element
{
public:
    dark();
    virtual void primaryAbility();
    virtual void secondaryAbility();
};
#endif