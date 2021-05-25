#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>

#include "game.h"
#include "element.cpp"
#include "player.cpp"

#include "elementpack/WATER/waterElement.h"
#include "elementpack/WATER/water.cpp"
#include "elementpack/WATER/ice.cpp"
#include "elementpack/WATER/wind.cpp"

#include "elementpack/FIRE/fireElement.h"
#include "elementpack/FIRE/fire.cpp"
#include "elementpack/FIRE/thunder.cpp"
#include "elementpack/FIRE/bomb.cpp"

#include "elementpack/GRASS/grassElement.h"
#include "elementpack/GRASS/grass.cpp"
#include "elementpack/GRASS/earth.cpp"
#include "elementpack/GRASS/poison.cpp"

#include "elementpack/LIGHT/lightElement.h"
#include "elementpack/LIGHT/light.cpp"
#include "elementpack/LIGHT/divine.cpp"
#include "elementpack/LIGHT/spirit.cpp"

#include "elementpack/DARK/darkElement.h"
#include "elementpack/DARK/dark.cpp"
#include "elementpack/DARK/demon.cpp"
#include "elementpack/DARK/ghost.cpp"

using namespace std;

int main()
{
    srand(time(0));
    system("clear");
    printf("*******************LHPS Coding Club*******************\n");
    sleep(1);
    printf("***************Produced by Xiangnong Wu***************\n\n");
    sleep(2);
    printf("Enter the number of players: ");
    cin >> n;
    cout << endl;
    printf("1 Water  Attack 2 Defense 5 HP 28\n");
    printf("2 Fire   Attack 5 Defense 2 HP 25\n");
    printf("3 Grass  Attack 3 Defense 3 HP 35\n");
    printf("4 Light  Attack 3 Defense 4 HP 30\n");
    printf("5 Dark   Attack 4 Defense 3 HP 30\n");
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
        players[i].last = i - 1;
        players[i].next = i + 1;
        cout << endl;
    }
    players[1].last = n;
    players[n].next = 1;
    first = 1;
    system("clear");
    for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        players[i].show();
    cout << endl;
    sleep(1);
    while (dn < n - 1)
    {
        Round++;
        for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        {
            players[i].turn();
            sleep(1);
            cout << endl;
        }
        for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
        {
            players[i].restoreHP(players[i].hpRestore);
            if (players[i].ele->elementLevel == 1)
                players[i].gainExp(1);
        }

        sleep(1);
        system("clear");
        for (int i = first, cnt = 1; cnt <= n - dn; i = players[i].next, cnt++)
            players[i].show();
        sleep(1);
        cout << endl;
    }
    return 0;
}