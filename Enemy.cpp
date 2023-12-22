#include "Enemy.h"

Enemy::Enemy(int mhp, int chp, int atk, int spd, int def)
{
  m_health_ = mhp;
  c_health_ = chp;
  attack_ = atk;
  defense_ = def;
  speed_ = spd;
}

int Enemy::GetMaxHP()
{
  return m_health_;
}

void Enemy::SetCurrentHP(int damageTaken)
{//sets current hp to 0 if currenthealth - damagetaken <= 0
  if (c_health_ - damageTaken <= 0)
  {
    c_health_ = 0;
  }
  else {
    c_health_ = c_health_ - damageTaken;
    }
}

int Enemy::GetCurrentHP()
{
  return c_health_;
}

int Enemy::GetAttack()
{
  return attack_;
}

int Enemy::GetSpeed()
{
  return speed_;
}

int Enemy::GetDefense()
{
  return defense_;
}

void Enemy::SetName(string someName)
{
  name_ = someName;
}

string Enemy::GetName()
{
  return name_;
}