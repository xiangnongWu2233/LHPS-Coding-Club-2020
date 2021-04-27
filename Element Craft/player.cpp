#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include "game.h"
#include "elementpack/baseelement.h"
#include "elementpack/mutatedelement.h"
using namespace std;

player::~player()
{
    delete ele;
}

void player::initialize(string n, int i, string e) //initialize each players
{
    name = n;
    id = i;
    hpRestore = 1;
    energy = 2;
    level = 1;
    if (e == "1")
        ele = new water();
    else if (e == "2")
        ele = new fire();
    else if (e == "3")
        ele = new grass();
    else if (e == "4")
        ele = new light();
    else if (e == "5")
        ele = new dark();
    ele->elementLevel = 1;
    ele->id = i;
    attack = ele->baseAttack;
    defense = ele->baseDefense;
    hp = ele->baseHP;
}

void player::show()
{
    printf("%d %-8s :   Element %-8s Attack %-3d  Defense %-3d  HP  %-3d  Level %d  Energy %d\n", id, name.c_str(), ele->name.c_str(), attack, defense, hp, level, energy);
}

void player::turn()
{
    if (lock >= 1)
    {
        printf("%d %s can't move!!!\n", id, name.c_str());
        lock--;
        return;
    }
    printf("It's %d %s's turn to attack! ", id, name.c_str());
    ele->normalAttack();
    if (dn == n - 1)
        return;
    if (ele->elementLevel > 1)
    {
        while (energy >= ele->ultimateCost)
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
                ele->ultimate();
            else
                break;
            if (dn == n - 1)
                return;
        }
    }
}

void player::upgrade()
{
    if (energy >= level * 2 + 1)
    {
        energy -= level * 2 + 1;
        level++;
        printf("Upgrade! \n\n");
        sleep(1);
        printf("HP + %d\n", int(ele->hpMaximum[level] / 4));
        hp += int(ele->hpMaximum[level] / 4);
        if (hp > ele->hpMaximum[level])
            hp = ele->hpMaximum[level];
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
        if (level >= 3 && ele->elementLevel == 1)
        {
            int coin = rand() % 100 + 1;
            if (coin >= 50 - 10 * (level - 3))
                mutate();
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
        dn++;
        printf("\033[31m\033[40mKilled %d %s!\n\033[0m", id, name.c_str());
        sleep(1);
        players[from].gainEnergy(players[from].level + 4);
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
    ele->id = id;
    sleep(1);
}