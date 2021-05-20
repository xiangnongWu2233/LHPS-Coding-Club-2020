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
    if (coin <= 20)
        normalAttack(target);
    else if (coin > 20 && coin <= 60)
        missle(target);
    else if (coin > 60 && coin <= 80)
    {
        if (missles == 3)
            nuclearStrike(target);
        else
            missle(target);
    }
    else if (coin > 80)
        devastate(target);
    if (coin > 20)
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
    sleep(1);
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
    sleep(1);
}

void bomb::nuclearStrike(int target)
{
    printf("Nuclear Strike!!!\n");
    sleep(2);
    players[target].receiveDamage(user, players[user].attack * 2 + players[user].level);
    if (players[target].last != user)
        players[players[target].last].receiveDamage(user, players[user].attack * 2 + players[user].level - 5);
    if (players[target].next != user)
        players[players[target].next].receiveDamage(user, players[user].attack * 2 + players[user].level - 5);
    missles = 0;
    sleep(1);
}