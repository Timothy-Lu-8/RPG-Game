#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

class Character
{
public:
    Character();
    void SetCurrentHp(int);
    void SetHpAfterBattle(int);
    void SetHpElixir(int);
    void SetCurrentHpInput(int);
    int GetCurrentHp();
    void SetMaxHp(int);
    int GetMaxHp();
    void SetAttack(int);
    int GetAttack();
    void SetDefense(int);
    int GetDefense();
    void SetSpeed(int);
    int GetSpeed();
    void SetLevel(int);
    int GetLevel();
    int GetLevelAfterLU();
    void SetExpAfterLU(int);
    void SetExp(int);
    void SetExpInput(int);
    int GetExp();
    void SetGoldEnemyDefeat(int);
    void SetGold(int);
    int GetGold();
    void ElixirUse();
    void SetElixirAmountAP(int);
    void SetElixirAmount(int);
    int GetElixirAmount();
    void SetGoldElixirPurchase(int);
    void ElixirShop();
    void LevelUp();
    bool LevelCap();
    bool MaxExp();
    int RandomValue();
    void AfterLevelStageNum(int);
    void SetStageNum(int);
    int GetStageNum();
    int GetBaseCrit();
    void SetWeaponType(string);
    string GetWeaponType();
    void SetInputLevel(int); // sets player level that is read from file
    virtual void StatLevel(){};
    virtual void SaveGame(){};
    virtual int GetWeaponMight(string) { return 0; } // gets weapon power based on which weapon is used
    virtual int GetClassCrit() { return 0; }         // gets crit value depending on class
    virtual void SetWeapon(int){};

protected:
    int currentHealth;
    int maxHealth;
    int attack;
    int defense;
    int speed;
    int level;
    int elixirAmount;
    int expPoints;
    int gold;
    int option;
    int levelNum;
    int baseCrit;
    string characterName;
    string weapon;
};
#endif