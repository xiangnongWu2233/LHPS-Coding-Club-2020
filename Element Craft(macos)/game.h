#ifndef GAME_H
#define GAME_H
#include <cstring>
#include <ctime>
#include <map>
using namespace std;

class status
{
public:
    bool control, damageOvertime;
    int trial, frozen, inAir;
    int shield;
    status()
    {
        control = 0;
        damageOvertime = 0;
        trial = 0;
        frozen = 0;
        inAir = 0;
    }
};

class element
{
public:
    string name;
    int user, elementLevel;
    int hpMaximum[11];
    int baseAttack, baseDefense, baseHP;
    void normalAttack(int target);
    virtual void skill(int target);
};

class player
{
public:
    int last, next;
    string name;
    status status_bar;
    int user, hp, attack, defense, hpRestore, level, exp;
    element *ele;
    ~player();
    void initialize(string n, int id, string e);
    void show();
    void showStatus(int mode);
    void turn();
    void upgrade();
    void receiveDamage(int from, int damage);
    void gainExp(int amount);
    void restoreHP(int amount);
    void mutate();
    void evolve();
};

player players[101];
int n, dn = 0, first;
int Round = 0;
#endif // GAME_H