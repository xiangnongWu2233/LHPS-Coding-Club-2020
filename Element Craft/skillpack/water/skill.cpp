#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "../../game.h"
#include "skill.h"
//water
flow::flow(int id)
{
    name = "Flow";
    CD = 2;
    level = 1;
    user = id;
    upgradeCost = 2;
}

void flow::use()
{
    printf("Flow!\n");
    for (int i = 1; i <= n; i++)
    {
        if (players[i].hp > 0 && i != user)
            players[i].receiveDamage(user, level);
    }
    sleep(1);
}

//ice
glacier::glacier(int id)
{
    name = "Glacier";
    CD = 5;
    level = 1;
    user = id;
    cost = 4;
    upgradeCost = 4;
}

void glacier::use()
{
    printf("%d %s - %d energies! \n", user, players[user].name.c_str(), cost);
    players[user].energy -= cost;
    sleep(1);
    printf("Glacier!!!\n");
    sleep(2);
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != user)
        {
            printf("Freeze %d %s !\n", i, players[i].name.c_str());
            players[i].lock += int(players[user].level / 2);
            players[i].receiveDamage(user, players[user].level);
        }
    sleep(1);
}

//wind
stormrage::stormrage(int id)
{
    name = "Stormrage";
    CD = 5;
    level = 1;
    user = id;
    cost = 4;
    upgradeCost = 4;
}

void stormrage::use()
{
    printf("%d %s - %d energies! \n", user, players[user].name.c_str(), cost);
    players[user].energy -= cost;
    sleep(1);
    printf("Choose your target: \n");
    string t;
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != user)
            printf("%d %s\n", players[i].user, players[i].name.c_str());
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == user)
    {
        printf("Please enter a valid target: \n");
        sleep(2);
        cin >> t;
    }
    sleep(2);
    printf("Stormrage!!!\n");
    players[stoi(t)].receiveDamage(user, players[user].defense + 3);
    printf("%d %s in air!\n", stoi(t), players[stoi(t)].name.c_str());
    players[stoi(t)].lock += 1;
    sleep(1);
}