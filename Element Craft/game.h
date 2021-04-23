#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <ctime>
using namespace std;

class element
{
public:
    string name, skillNames[101];
    int id, skillNum, elementLevel, ultracost;
    element(int i, string e);
    void normalAttack();
    virtual void ultimate() {}
};

class player
{
public:
    string name;
    int id;
    int hp, attack, defense, hpRestore, lock, energy, level;
    element *ele;
    ~player();
    void initialize(string n, int i, string e);
    void show();
    void turn();
    void skill();
    void upgrade();
    void receiveDamage(int from, int damage);
    void gainEnergy(int amount);
    void restore(int amount);
    void mutate();
    void evolve();
};

player players[101];
int n, dn = 0;
int Round = 0;
#endif // GAME_H