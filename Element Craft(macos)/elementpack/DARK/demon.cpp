#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "../../game.h"
#include "darkElement.h"
using namespace std;

demon::demon() : dark()
{
    name = "Demon";
    elementLevel = 2;
    printf("Element mutated: ");
    printf("\033[35m\033[40m");
    cout << name;
    printf("\033[0m\n");
}

void demon::skill(int target)
{
    int coin = rand() % 100 + 1;
    if (coin <= 10)
        normalAttack(target);
    else if (coin > 10 && coin <= 50)
        blackSigil();
    else if (coin > 50 && coin <= 70)
    {
        if (sigils == 6)
            sixFoldcurse();
        else
            blackSigil();
    }
    else if (coin > 70)
        devour(target);
    if (coin > 10)
        players[user].gainExp(1);
}

void demon::blackSigil()
{
    printf("Black Sigil!\n");
    sigils++;
    players[user].restoreHP(1);
    sleep(1);
}

void demon::devour(int target)
{
    printf("Devour!\n");
    int damage = (players[target].ele->hpMaximum[players[target].level] - players[target].hp) * 0.1 + players[user].level * 3 + players[target].defense;
    players[target].receiveDamage(user, damage);
    sleep(1);
}

void demon::sixFoldcurse()
{
    printf("Six-Fold Curse!!!\n");
    sigils -= 6;
    sleep(2);
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        if (i != user)
        {
            if (players[i].hp > players[user].hp)
            {
                printf("Tearing!\n");
                players[i].receiveDamage(user, players[user].level * 4 + players[i].defense);
            }
            else
            {
                printf("Suffering!\n");
                players[i].receiveDamage(user, players[user].level * 3 + players[i].defense);
            }
        }
    sleep(1);
}
