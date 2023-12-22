#ifndef PALADIN_H
#define PALADIN_H
#include <ctime>
#include <cstdlib>
#include "Character.h"

class Paladin : public Character
{
public:
    Paladin();
    void StatLevel();
    void SaveGame();
    int GetWeaponMight(string);
    int GetClassCrit();
    void SetWeapon(int);
};
#endif