#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#include "game.h"
#include "element.cpp"
#include "player.cpp"

#include "elementpack/element.h"
#include "elementpack/baseelement.h"

#include "elementpack/Water/ice.cpp"
#include "elementpack/Water/wind.cpp"

#include "elementpack/Fire/bomb.cpp"
#include "elementpack/Fire/thunder.cpp"

#include "elementpack/Grass/earth.cpp"
#include "elementpack/Grass/poison.cpp"

#include "elementpack/Light/divine.cpp"
#include "elementpack/Light/spirit.cpp"

#include "elementpack/Dark/demon.cpp"
#include "elementpack/Dark/ghost.cpp"

using namespace std;

int main()
{
    srand(time(0));
    system("clear");
    printf("Enter the number of players: ");
    cin >> n;
    cout << endl;
    printf("1 Water  Attack 2 Defense 4 HP 15\n");
    printf("2 Fire   Attack 5 Defense 2 HP 13\n");
    printf("3 Grass  Attack 3 Defense 3 HP 18\n");
    printf("4 Light  Attack 3 Defense 4 HP 16\n");
    printf("5 Dark   Attack 4 Defense 3 HP 16\n");
    cout << endl;
    sleep(1);
    for (int i = 1; i <= n; i++)
    {
        string na, e;
        printf("Enter the name of player %d: ", i);
        cin >> na;
        printf("Choose your element: ");
        cin >> e;
        players[i].initialize(na, i, e);
        cout << endl;
    }
    system("clear");
    for (int i = 1; i <= n; i++)
        players[i].show();
    cout << endl;
    sleep(1);
    while (dn < n - 1)
    {
        Round++;
        for (int i = 1; i <= n; i++)
        {
            if (players[i].hp <= 0)
                continue;
            players[i].turn();
            sleep(1);
            cout << endl;
        }
        for (int i = 1; i <= n; i++)
            if (players[i].hp > 0)
            {
                players[i].restore(players[i].hpRestore);
                if (players[i].hp > players[i].ele->hpMaximum[players[i].level])
                    players[i].hp = players[i].ele->hpMaximum[players[i].level];
            }
        sleep(1);
        system("clear");
        for (int i = 1; i <= n; i++)
            if (players[i].hp > 0)
                players[i].show();

        cout << endl;
        sleep(1);
    }
    return 0;
}