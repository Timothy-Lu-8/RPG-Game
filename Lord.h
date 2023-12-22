#ifndef LORD_H
#define LORD_H
#include <cstdlib>
#include "Character.h"

class Lord : public Character
{
public:
    Lord();
    void StatLevel();
    void SaveGame();
    int GetWeaponMight(string);
    int GetClassCrit();
    void SetWeapon(int);
};
#endif