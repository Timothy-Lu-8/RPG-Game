#include "Final_Boss.h"

Final_Boss::Final_Boss(int mhp, int chp, int atk, int spd, int def) : Enemy(mhp, chp, atk, spd, def){}

void Final_Boss::IntroductoryDialogue()
{
  cout << "So you've made it this far." << endl;
  cout << "Let's see if you have what it takes to defeat me!" << endl;
}

int Final_Boss::BasicAttack()
{
  return GetAttack();
}

int Final_Boss::DoubleAttack()
{
  return (3 * GetAttack() / 4) + GetAttack() / 2;
}

void Final_Boss::PreparingChargeAttack() // messages when basic enemy is beginning charging attack
{
  cout << "The Dragon is charging a strong attack!" << endl;
  cout << "The Dragon will attack in 2 turns." << endl;
}

void Final_Boss::AlmostDoneChargeAttack() // message when basic enemy will unleash charged attack next turn
{
  cout << "The Dragon will attack in 1 turn." << endl;
}

int Final_Boss::DoingChargeAttack()
{
  return ((GetAttack() * 2 + GetAttack()) / 2);
}

void Final_Boss::VictoryDialogue()
{
  cout << "You've... bested... me..." << endl;
  cout << "You defeated the Dragon!" << endl;
}