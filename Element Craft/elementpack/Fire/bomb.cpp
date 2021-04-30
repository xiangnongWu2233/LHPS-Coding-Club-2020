#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "../baseelement.h"
#include "../mutatedelement.h"
using namespace std;

bomb::bomb() : fire()
{
    name = "Bomb";
    skillNum = 3;
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[93m\033[41m");
    cout << name;
    printf("\033[0m\n");
    skillNum = 3;
    ultimateCost = 6;
}

void bomb::skill()
{
    int cnt = 0;
    for (int i = 1; i <= skillNum; i++)
    {
        printf("%d %s : ", i, skillName[i].c_str());
        if (CD[i] == 0)
        {
            cnt++;
            printf("Ready");
        }
        else
        {
            if (CD[i] == 1)
                printf("1 more round");
            else
                printf("%d more rounds", CD[i]);
        }
        cout << endl;
    }
    sleep(1);
    if (cnt == 0)
        return;
    printf("Do you want to use skills? Y/N\n");
    string choice;
    cin >> choice;
    if (choice == "yes" || choice == "Y" || choice == "y" || choice == "YES" || choice == "Yes")
    {
        printf("Choose your skill: \n");
        cin >> choice;
        while (stoi(choice) <= 1 || stoi(choice) >= skillNum || CD[stoi(choice)] != 0)
        {
            if (CD[stoi(choice)] != 0)
                printf("Skill in cooldown!\n");
            else
                printf("Please enter a valid option!\n");
            sleep(2);
            cin >> choice;
        }
        if (choice == "1")
            bombing();
        if (choice == "2")
            torpedo();
        if (choice == "3")
            devastate();
    }
    else
        return;
}

void bomb::bombing()
{
}

void bomb::torpedo()
{
}

void bomb::devastate()
{
    printf("Choose your target: \n");
    string t;
    for (int i = 1; i <= n; i++)
        if (players[i].hp > 0 && i != id)
            printf("%d %s\n", players[i].id, players[i].name.c_str());
    cin >> t;
    while (players[stoi(t)].hp <= 0 || stoi(t) == id)
    {
        printf("Please enter a valid target: \n");
        sleep(2);
        cin >> t;
    }
    sleep(2);
    printf("Devastate!!!\n");
    players[stoi(t)].receiveDamage(id, 8 + int((players[stoi(t)].ele->hpMaximum[players[stoi(t)].level] - players[stoi(t)].hp) / 3));
    sleep(1);
}

void bomb::ultimate()
{
    printf("%d %s - %d energies! \n", id, players[id].name.c_str(), ultimateCost);
    players[id].energy -= ultimateCost;
    sleep(1);
}
