#ifndef BASIC_ENEMY_H
#define BASIC_ENEMY_H
#include <iostream>
#include "Enemy.h"
#include "Enemy.cpp"

class Basic_Enemy : public Enemy
{
public:
  Basic_Enemy(int, int, int, int, int);
  int BasicAttack();
  void BeginningChargeAttack();
  void OneTurnChargeAttack();
  int UnleashChargeAttack();
  void Victory();
};
#endif