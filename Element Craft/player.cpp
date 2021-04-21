#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include "game.h"
#include "elementpack/element.h"
using namespace std;

player::~player()
{
    delete ele;
}

void player::initialize(string n, int i, string e) //initialize each players
{
    ele = new element(e); // eventually delete the element object when the player die or get a new element
    name = n;
    id = i;
    hpRestore = 1;
    energy = 0;
    level = 1;
    if (e == "1")
    {
        attack = 2;
        defense = 5;
        hp = 15;
    }
    if (e == "2")
    {
        attack = 5;
        defense = 2;
        hp = 14;
    }
    if (e == "3")
    {
        attack = 3;
        defense = 3;
        hp = 16;
    }
    if (e == "4")
    {
        attack = 3;
        defense = 4;
        hp = 15;
    }
    if (e == "5")
    {
        attack = 4;
        defense = 3;
        hp = 15;
    }
}

void player::show()
{
    printf("%d %-8s :   Element %-8s Attack %-3d  Defense %-3d  HP  %-3d  Level %d  Energy %d\n", id, name.c_str(), ele->name.c_str(), attack, defense, hp, level, energy);
}

void player::turn()
{
    printf("It's %d %s's turn to attack! ", id, name.c_str());
    ele->normalAttack(id);
    if (ele->elementLevel > 1)
    {
        if (energy >= ele->skillcost[1])
        {
            sleep(1);
            printf("Ultimate Ready! 1. Use 2. Skip\n");
            string choice;
            cin >> choice;
            while (choice != "1" && choice != "2")
            {
                printf("Please enter a valid option! \n");
                sleep(2);
                cin >> choice;
            }
            if (choice == "1")
            {
                ele->ultimate();
                energy -= ele->skillcost[1];
            }
        }
    }
}

void player::upgrade()
{
    if (energy >= level * 2 - 1)
    {
        energy -= level * 2 - 1;
        level++;
        printf("Upgrade! \n\n");
        sleep(1);
        printf("Choose to upgrade: \n");
        printf("1. Attack %d+1\n2.Defense %d+1\n", attack, defense);
        if (hpRestore < 3)
            printf("3.Hp-Restore %d+1\n", hpRestore);
        string choice;
        cin >> choice;
        while (choice != "1" && choice != "2" && choice != "3" || (choice == "3" && hpRestore == 3))
        {
            if (choice == "3")
                printf("Has reached its maximum! Try again! \n");
            else
            {
                printf("Please enter a valid option! \n");
                sleep(2);
            }
            cin >> choice;
        }
        if (choice == "1")
            attack++;
        if (choice == "2")
            defense++;
        if (choice == "3")
            hpRestore++;
        if (level >= 4 && level <= 8 && ele->elementLevel == 1)
        {
            int coin = rand() % 100 + 1;
            if (coin >= 50)
                mutate();
        }
    }
}

void player::receiveDamage(int from, int damage)
{
    printf("%d %s - %d\n", id, name.c_str(), damage);
    hp -= damage;
    cout << endl;
    players[from].gainEnergy(1);
    if (hp <= 0)
    {
        dn++;
        printf("\033[31m\033[40mKilled %d %s!\n\033[0m", id, name.c_str());
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

void player::restore(int amount)
{
    printf("%d %s gains %d health!\n", id, name.c_str(), amount);
    hp += amount;
}

void player::mutate()
{
    printf("Element mutated! ");
    sleep(1);
    printf("Choose your element: \n");
    delete ele;
    string choice;

    if (ele->name == "Water")
    {
        printf("1. Ice     2. Wind\n");
        cin >> choice;
        while (choice != "1" && choice != "2")
        {
            printf("Enter a valid number!!!");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            ele = new ice();
        else
            ele = new wind();
    }

    if (ele->name == "Fire")
    {
        printf("1. Bomb    2. Thunder\n");
        cin >> choice;
        while (choice != "1" && choice != "2")
        {
            printf("Enter a valid number!!!");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            ele = new bomb();
        else
            ele = new thunder();
    }

    if (ele->name == "Grass")
    {
        printf("1. Earth   2. Poison\n");
        cin >> choice;
        while (choice != "1" && choice != "2")
        {
            printf("Enter a valid number!!!");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            ele = new earth();
        else
            ele = new poison();
    }

    if (ele->name == "Light")
    {
        printf("1. Divine  2. Spirit\n");
        cin >> choice;
        while (choice != "1" && choice != "2")
        {
            printf("Enter a valid number!!!");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            ele = new divine();
        else
            ele = new spirit();
    }

    if (ele->name == "Dark")
    {
        printf("1. Demon   2. Ghost\n");
        cin >> choice;
        while (choice != "1" && choice != "2")
        {
            printf("Enter a valid number!!!");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            ele = new demon();
        else
            ele = new ghost();
    }
    sleep(1);
}