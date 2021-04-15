#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "game.h"
#include "player.cpp"
#include "element.cpp"
using namespace std;

int main()
{
    printf("Enter the number of players: ");
    cin >> n;
    cout << endl;
    printf("1 Water  Attack 2 Defense 5 HP 15\n");
    printf("2 Fire   Attack 5 Defense 2 HP 14\n");
    printf("3 Grass  Attack 3 Defense 3 HP 16\n");
    printf("4 Light  Attack 3 Defense 4 HP 15\n");
    printf("5 Dark   Attack 4 Defense 3 HP 15\n");
    cout << endl;
    sleep(1);
    for (int i = 1; i <= n; i++)
    {
        string n;
        int e;
        printf("Enter the name of player %d: ", i);
        cin >> n;
        printf("Choose your element: ");
        cin >> e;
        players[i].initialize(n, i, e);
        cout << endl;
    }
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
                players[i].show();
        cout << endl;
        sleep(1);
    }
    return 0;
}