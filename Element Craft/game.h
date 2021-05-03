#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <ctime>
#include <map>
using namespace std;

class skill
{
public:
    string name;
    int level, CD;
};

class element
{
public:
    string name;
    int id, elementLevel;
    int energyMaximum[11];
    int baseAttack, baseDefense, baseHP;
    void normalAttack();
    virtual void skill();
    virtual void primaryAbility(){};
    virtual void secondaryAbility(){};
    virtual void ultimate() {}
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