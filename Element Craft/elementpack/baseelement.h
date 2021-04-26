#ifndef BASEELEMENT_H
#define BASEELEMENT_H

#include "../game.h"
class water : public element
{
public:
    water()
    {
        name = "Water";
        baseAttack = 2;
        baseDefense = 5;
        baseHP = 15;
        hpMaximum[1] = baseHP;
        for (int i = 2; i <= 10; i++)
            hpMaximum[i] = hpMaximum[i - 1] + i;
    }
};

class fire : public element
{
public:
    fire()
    {
        name = "Fire";
        baseAttack = 5;
        baseDefense = 2;
        baseHP = 13;
        hpMaximum[1] = baseHP;
        for (int i = 2; i <= 10; i++)
            hpMaximum[i] = hpMaximum[i - 1] + 2;
    }
};

class grass : public element
{
public:
    grass()
    {
        name = "Grass";
        baseAttack = 3;
        baseDefense = 3;
        baseHP = 20;
        hpMaximum[1] = baseHP;
        for (int i = 2; i <= 10; i++)
            hpMaximum[i] = hpMaximum[i - 1] + 4;
    }
};

class light : public element
{
public:
    light()
    {
        name = "Light";
        baseAttack = 3;
        baseDefense = 4;
        baseHP = 18;
        hpMaximum[1] = baseHP;
        for (int i = 2; i <= 10; i++)
            hpMaximum[i] = hpMaximum[i - 1] + i - 1;
    }
};

class dark : public element
{
public:
    dark()
    {
        name = "Dark";
        baseAttack = 4;
        baseDefense = 3;
        baseHP = 18;
        hpMaximum[1] = baseHP;
        for (int i = 2; i <= 10; i++)
            hpMaximum[i] = hpMaximum[i - 1] + 3;
    }
};
#endif