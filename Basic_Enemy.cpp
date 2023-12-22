#include "Basic_Enemy.h"

Basic_Enemy::Basic_Enemy(int m_hp, int c_hp, int atk, int spd, int def) : Enemy(m_hp, c_hp, atk, spd, def)
{
}

int Basic_Enemy::BasicAttack()
{
  return GetAttack();
}

void Basic_Enemy::BeginningChargeAttack() // messages when basic enemy is beginning charging attack
{
  cout << GetName() << " is charging a strong attack!" << endl;
  cout << GetName() << " will attack in 2 turns." << endl;
}

void Basic_Enemy::OneTurnChargeAttack() // message when basic enemy will unleash charged attack next turn
{
  cout << GetName() << " will attack in 1 turn." << endl;
}

int Basic_Enemy::UnleashChargeAttack()
{
  return (GetAttack() * 2);
}