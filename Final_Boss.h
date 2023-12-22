#ifndef FINAL_BOSS_H
#define FINAL_BOSS_H
#include <iostream>
#include "Enemy.h"
using namespace std;

class Final_Boss : public Enemy
{
public:
  Final_Boss(int, int, int, int, int);
  void IntroductoryDialogue();
  void VictoryDialogue();
  int BasicAttack();
  int DoubleAttack();
  void PreparingChargeAttack();
  void AlmostDoneChargeAttack();
  int DoingChargeAttack();
};
#endif