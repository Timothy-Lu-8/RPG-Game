#include "Character.h"

Character::Character()
{
  currentHealth = 20;
  maxHealth = 20;
  attack = 6;
  defense = 5;
  speed = 4;
  level = 1;
  elixirAmount = 1;
  expPoints = 0;
  gold = 1000;
  levelNum = 1;
  baseCrit = 10;
}

// takes an int value that is subtracted from current hp. if its <= 0, current hp = 0
void Character::SetCurrentHp(int someHp)
{
  if (someHp <= 0)
  {
    currentHealth = currentHealth - 0;
  }
  else
  {
    currentHealth -= someHp;
  }
}

// fully restores player's hp after completing a stage
void Character::SetHpAfterBattle(int maxHp)
{
  currentHealth = maxHp;
}

// fully heals player after using elixir
void Character::SetHpElixir(int maxHp)
{
  currentHealth = maxHp;
}

// function for setting hp from file read in
void Character::SetCurrentHpInput(int input)
{
  currentHealth = input;
}

int Character::GetCurrentHp()
{
  return currentHealth;
}

void Character::SetMaxHp(int someHp)
{
  maxHealth = someHp;
}

int Character::GetMaxHp()
{
  return maxHealth;
}

void Character::SetAttack(int a)
{
  attack = a;
}

int Character::GetAttack()
{
  return attack;
}

void Character::SetDefense(int d)
{
  defense = d;
}

int Character::GetDefense()
{
  return defense;
}

void Character::SetSpeed(int s)
{
  speed = s;
}

int Character::GetSpeed()
{
  return speed;
}

// levels up player if they are below level 100
void Character::SetLevel(int l)
{
  if (level == 100)
  {
    level = 100;
  }
  else
  {
    level += l;
  }
}

int Character::GetLevel()
{
  return level;
}

// retrieves level of player after they level up
int Character::GetLevelAfterLU()
{
  return level++;
}

// sets exp of character after they level up
void Character::SetExpAfterLU(int e)
{
  expPoints = e - 100;
}

// function that adds int argument to current exp
void Character::SetExp(int e)
{
  expPoints += e;
}

void Character::SetExpInput(int input)
{
  expPoints = input;
}

int Character::GetExp()
{
  return expPoints;
}

// adds gold after stage has been cleared
void Character::SetGoldEnemyDefeat(int victoryGold)
{
  gold += victoryGold;
}

void Character::SetGold(int g)
{
  gold = g;
}

int Character::GetGold()
{
  return gold;
}

// subtracts 1 from the player's elixir count
void Character::ElixirUse()
{
  elixirAmount--;
}

void Character::SetElixirAmountAP(int amount)
{
  elixirAmount += amount;
}

// adds however many elixirs the user purchased
void Character::SetElixirAmount(int e)
{
  elixirAmount = e;
}

int Character::GetElixirAmount()
{
  return elixirAmount;
}

void Character::SetGoldElixirPurchase(int spent)
{
  gold -= spent;
}

void Character::ElixirShop()
{
  char confirm;
  int purchased;
  cout << "Would you like to buy elixirs?" << endl;
  cout << "If you would like to purchase elixirs, press any key except q or Q to continue." << endl;
  cin >> confirm;
  if (confirm == 'q' || confirm == 'Q') {
    cout << "Decided not to buy any elixirs." << endl;
    cout << "-------------------------------------------" << endl;
  }
  else { 
    cout << "How many would you like to purchase?" << endl;
    cin >> purchased;
    if (purchased * 500 > GetGold()) { // player doesn't have enough for desired amount
      cout << "Insufficient gold." << endl;
      cout << "-------------------------------------------" << endl;
    }
    else {
      SetElixirAmountAP(purchased);           // updates elixir count
      SetGoldElixirPurchase(purchased * 500); // subtracts elixirs bought * 500
      cout << purchased << " elixirs purchased." << endl;
      cout << "Gold remaining: " << GetGold() << endl;
      cout << "-------------------------------------------" << endl;
    }
  }
}

void Character::LevelUp()
{
  if (GetExp() >= 100) {
    if (LevelCap() == false) {
      SetExpAfterLU(GetExp());
    }
  }
  if (GetLevel() == 100) {
    level = 100;
    expPoints = 0;
    cout << "Max level reached." << endl;
  }
}

bool Character::LevelCap()
{
  if (level == 100) {
    return true;
  }
  return false;
}

bool Character::MaxExp()
{
  if (GetExp() >= 100) {
    return true;
  }
  return false;
}

int Character::RandomValue()
{
  int randInt = rand() % 99 + 1;
  return randInt;
}

void Character::AfterLevelStageNum(int aStage)
{
  levelNum += aStage;
}

void Character::SetStageNum(int stage)
{
  levelNum = stage;
}

int Character::GetStageNum()
{
  return levelNum;
}

int Character::GetBaseCrit()
{
  return 10;
}

void Character::SetWeaponType(string w)
{
  weapon = w;
}

string Character::GetWeaponType()
{
  return weapon;
}

void Character::SetInputLevel(int i_level)
{
  level = i_level;
}
