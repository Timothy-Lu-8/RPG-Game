#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

class Enemy 
{
public:
  Enemy(int mhp, int chp, int atk, int spd, int def);  
  int GetMaxHP();
  void SetCurrentHP(int);
  int GetCurrentHP();
  int GetAttack();
  int GetSpeed();
  int GetDefense();
  void SetName(string);
  string GetName();
  virtual int BasicAttack() {return 0;}
protected:
  int m_health_;
  int c_health_;
  int attack_;
  int speed_;
  int defense_;
  string name_; 
};
#endif