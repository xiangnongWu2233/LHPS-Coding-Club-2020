#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "fireElement.h"
using namespace std;

bomb::bomb() : fire()
{
    name = "Bomb";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
}

void bomb::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 30)
        normalAttack(target);
    else if (coin > 30 && coin <= 60)
        missle(target);
    else if (coin > 60 && coin <= 70)
    {
        if (missles == 3)
            nuclearStrike();
        else
            missle(target);
    }
    else if (coin > 70 && coin <= 80)
        devastate(target);
    if (coin > 30 && coin <= 80)
        players[user].gainExp(1);
}

void bomb::missle(int target)
{
    printf("Gain a missle!\n");
    printf("Missles stored: %d\n", missles);
    sleep(1);
    printf("1. Release.\n2. Store.\n");
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2")
    {
        printf("Please enter a valid option!\n");
        sleep(2);
        cin >> choice;
    }
    if (choice == "1")
    {
        players[target].receiveDamage(user, players[user].level + 4);
        if (players[target].last != user)
            players[players[target].last].receiveDamage(user, players[user].level + 2);
        if (players[target].next != user)
            players[players[target].next].receiveDamage(user, players[user].level + 2);
    }
    else
        missles++;
}

void bomb::devastate(int target)
{
    printf("Devastate!\n");
    if (players[target].hp <= 3 + players[user].level)
    {
        players[target].receiveDamage(user, 999 + players[target].defense);
        return;
    }
    players[target].receiveDamage(user, players[user].attack);
}

void bomb::nuclearStrike()
{
    printf("Nuclear Strike!!!\n");
    sleep(2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next)
    {
        if (i != user)
        {
            players[i].receiveDamage(user, players[user].attack * 3);
        }
    }
    sleep(1);
}