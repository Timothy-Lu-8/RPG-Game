#ifndef TACTICIAN_H
#define TACTICIAN_H
#include <ctime>
#include <cstdlib>
#include "Character.h"

class Tactician : public Character
{
public:
    Tactician();
    void StatLevel();
    void SaveGame();
    int GetWeaponMight(string);
    int GetClassCrit();
    void SetWeapon(int);

private:
    int baseCritRate;
};
#endif