#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <ctime>
using namespace std;

class skill
{
public:
    string name;
    int CD;
    int level;
    virtual void use();
};

class element
{
public:
    string name;
    int id, elementLevel;
    int hpMaximum[11], energyMaximum[11];
    int baseAttack, baseDefense, baseHP;

    void normalAttack();
    virtual void ultimate() {}
    virtual void skill() {}
};

class player
{
public:
    string name;
    int id, hp, attack, defense, hpRestore, energy, level, exp;
    int lock;
    element *ele;
    ~player();
    void initialize(string n, int i, string e);
    void show();
    void turn();
    void upgrade();
    void receiveDamage(int from, int damage);
    void gainExp(int amount);
    void gainEnergy(int amount);
    void restoreHP(int amount);
    void mutate();
    void evolve();
};

player players[101];
int n, dn = 0;
int Round = 0;
#endif // GAME_H