#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <ctime>
using namespace std;

class element
{
public:
    string name, skillNames[101];
    int id, skillNum, elementLevel, ultimateCost;
    int hpMaximum[11];
    int baseAttack, baseDefense, baseHP;
    void normalAttack();
    virtual void ultimate() {}
};

class player
{
public:
    string name;
    int id, hp, attack, defense, hpRestore, energy, level;
    int lock;
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