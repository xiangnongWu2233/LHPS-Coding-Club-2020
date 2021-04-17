#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include "game.h"
using namespace std;

player::~player()
{
    delete ele;
}

void player::initialize(string n, int i, int e) //initialize each players
{
    ele = new element(e); // eventually delete the element object when the player die or get a new element
    name = n;
    id = i;
    hpRestore = 1;
    energy = 0;
    level = 1;
    if (e == 1)
    {
        attack = 2;
        defense = 5;
        hp = 15;
    }
    if (e == 2)
    {
        attack = 5;
        defense = 2;
        hp = 14;
    }
    if (e == 3)
    {
        attack = 3;
        defense = 3;
        hp = 16;
    }
    if (e == 4)
    {
        attack = 3;
        defense = 4;
        hp = 15;
    }
    if (e == 5)
    {
        attack = 4;
        defense = 3;
        hp = 15;
    }
}

void player::show()
{
    printf("%d %s: Element %s Attack %d  Defense %d  HP  %d  Level %d  Energy %d\n", id, name.c_str(), ele->name.c_str(), attack, defense, hp, level, energy);
}

void player::turn()
{
    printf("It's %d %s's turn to move! ", id, name.c_str());
    if (ele->skillNum == 1)
        ele->normalAttack(id);
}

void player::upgrade()
{
    if (energy >= level * 2 - 1)
    {
        level++;
        energy = 0;
        printf("Upgrade! \n\n");
        sleep(1);
        printf("Choose to upgrade: \n");
        int t = 2; //temporary variable
        printf("1. Attack %d+1\n2.Defense %d+1\n", attack, defense);
        if (hpRestore < 3)
        {
            printf("3.Hp-Restore %d+1\n", hpRestore);
            t = 3;
        }
        int choice;
        cin >> choice;
        while (choice < 1 || choice > t)
        {
            if (choice == 3)
                printf("Has reached its maximum! \n");
            else
            {
                printf("Please enter a valid option! \n");
                sleep(2);
            }
        }
        if (choice == 1)
            attack++;
        if (choice == 2)
            defense++;
        if (choice == 3)
            hpRestore++;
        if (level >= 4 && level <= 8)
        {
            //mutate();
        }
    }
}

void player::receiveDamage(int from, int damage)
{
    printf("%d %s - %d\n", id, name.c_str(), damage);
    hp -= damage;
    cout << endl;
    if (hp <= 0)
    {
        printf("Killed %d %s!\n", id, name.c_str());
        sleep(1);
        players[from].gainEnergy(level * 2 + ceil(Round / 5));
    }
}

void player::gainEnergy(int amount)
{
    printf("%d %s gains %d energies!\n", id, name.c_str(), amount);
    energy += amount;
    upgrade();
}