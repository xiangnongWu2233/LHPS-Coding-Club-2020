#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "game.h"
using namespace std;

element::element(string e)
{
    skillNum = 1;
    elementLevel = 1;
    if (e == "1")
        name = "Water";
    if (e == "2")
        name = "Fire";
    if (e == "3")
        name = "Grass";
    if (e == "4")
        name = "Light";
    if (e == "5")
        name = "Dark";
}

void element::normalAttack(int attacker)
{
    printf("Choose your target: \n");
    for (int i = 1; i <= n; i++)
        if (i != attacker && players[i].hp > 0)
            printf("%d %s\n", i, players[i].name.c_str());
    cout << endl;
    string t;
    cin >> t;
    while (players[stoi(t)].hp <= 0)
    {
        printf("Please enter a valid target!\n");
        sleep(2);
        cin >> t;
    }
    int damage = players[attacker].attack - players[stoi(t)].defense;
    if (damage <= 0)
        damage = 1;
    players[stoi(t)].receiveDamage(damage);
    if (players[stoi(t)].hp <= 0)
        players[attacker].gainEnergy(players[attacker].level * 2 + ceil(Round / 5));
    players[attacker].gainEnergy(1);
}