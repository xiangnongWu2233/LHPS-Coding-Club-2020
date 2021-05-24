#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include "game.h"

#include "elementpack/WATER/waterElement.h"
#include "elementpack/FIRE/fireElement.h"
#include "elementpack/GRASS/grassElement.h"
#include "elementpack/LIGHT/lightElement.h"
#include "elementpack/DARK/darkElement.h"
using namespace std;

player::~player()
{
    delete ele;
}

void player::initialize(string n, int id, string e) //initialize each players
{
    name = n;
    user = id;
    hpRestore = 1;
    exp = 0;
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
    ele->user = id;
    attack = ele->baseAttack;
    defense = ele->baseDefense;
    hp = ele->baseHP;
}

void player::show()
{
    printf("%d %-10s : Element %-8s Attack %-2d  Defense %-2d  HP  %-2d  EXP %-2d Level %d\n", user, name.c_str(), ele->name.c_str(), attack, defense, hp, exp, level);
}

void player::showStatus(int mode)
{
    if (mode == 1) //control
    {
        printf("%d %s ", user, name.c_str());
        if (status_bar.trial > 0)
        {
            printf("On trial!");
            status_bar.trial--;
            status_bar.frozen = 0;
            status_bar.terrified = 0;
            status_bar.inAir = 0;
            status_bar.stunned = 0;
        }
        else if (status_bar.frozen > 0)
        {
            printf("Frozen!");
            status_bar.frozen--;
            status_bar.terrified = 0;
            status_bar.inAir = 0;
            status_bar.stunned = 0;
        }
        else if (status_bar.terrified > 0)
        {
            printf("Terrified!");
            status_bar.terrified--;
            status_bar.inAir = 0;
            status_bar.stunned = 0;
        }
        else if (status_bar.inAir > 0 || status_bar.stunned > 0)
        {
            if (status_bar.inAir > 0)
            {
                printf("In Air!");
                status_bar.inAir--;
            }
            else if (status_bar.stunned > 0)
            {
                printf("Stunned!");
                status_bar.stunned--;
            }
        }
        if (status_bar.trial == 0 && status_bar.frozen == 0 && status_bar.terrified == 0 && status_bar.inAir == 0 && status_bar.stunned == 0)
            status_bar.control = 0;
        cout << endl;
    }
}

void player::turn()
{
    if (status_bar.control == 1)
    {
        showStatus(1);
        return;
    }
    printf("It's %d %s 's turn! ", user, name.c_str());
    sleep(1);
    printf("Choose your target: \n");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
            printf("%d %s\n", i, players[i].name.c_str());
    cout << endl;
    string choice;
    cin >> choice;
    while (players[stoi(choice)].hp <= 0 || stoi(choice) == user)
    {
        if (stoi(choice) == user)
            printf("Can't attack yourself!\n");
        else
            printf("Please enter a valid target!\n");
        sleep(2);
        cin >> choice;
    }
    ele->skill(stoi(choice));
    if (dn == n - 1)
        return;
    if (status_bar.damageOvertime)
    {
        if (status_bar.poisoning[1] > 0)
        {
            receiveDamage(status_bar.poisoning[0], status_bar.poisoning[2]);
            status_bar.poisoning[1]--;
        }
    }
}

void player::upgrade()
{
    if (exp >= level * 2 + 1)
    {
        exp -= level * 2 + 1;
        level++;
        printf("Upgrade! \n\n");
        sleep(1);
        restoreHP(ele->hpMaximum[level] - hp);
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
        if (level >= 2 && ele->elementLevel == 1)
        {
            int coin = rand() % 100 + 1;
            if (coin >= 1 - 10 * (level - 3))
                mutate();
        }
    }
    cout << endl;
}

void player::receiveDamage(int from, int damage)
{
    if (status_bar.soulpiece > 0)
    {
        damage *= 2;
        status_bar.soulpiece--;
    }
    damage -= defense;
    if (damage <= 0)
        damage = 1;
    if (status_bar.shield > 0)
    {
        status_bar.shield -= damage;
        if (status_bar.shield > 0)
        {
            printf("%d %s shield remains: %d\n", user, name.c_str(), status_bar.shield);
            return;
        }
        damage = -status_bar.shield;
        status_bar.shield = 0;
        printf("Shield broken!\n");
        cout << endl;
        sleep(1);
        if (damage == 0)
            return;
    }
    printf("%d %s - %d\n", user, name.c_str(), damage);
    hp -= damage;
    cout << endl;
    if (hp <= 0)
    {
        dn++;
        printf("\033[31m\033[40mKilled %d %s!\n\033[0m", user, name.c_str());
        players[last].next = next;
        players[next].last = last;
        if (user == first)
            first = next;
        sleep(1);
        players[from].gainExp(players[from].level + 4);
    }
}

void player::gainExp(int amount)
{
    printf("%d %s EXP + %d!\n", user, name.c_str(), amount);
    exp += amount;
    upgrade();
}

void player::restoreHP(int amount)
{
    printf("%d %s gains %d health!\n", user, name.c_str(), amount);
    hp += amount;
    if (hp > ele->hpMaximum[level])
        hp = ele->hpMaximum[level];
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
    ele->user = user;
    sleep(1);
}