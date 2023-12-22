#include "Paladin.h"

Paladin::Paladin() : Character() // stats + seed's randomly generated values for each stat
{ 
  srand(time(0));
  int randHealth = rand() % 9;
  currentHealth = 20 + randHealth;
  maxHealth = 20 + randHealth;
  attack = 5 + rand() % 2;
  defense = 7 + rand() % 2;
  speed = 4;
  weapon = "Bronze Axe";
}

void Paladin::StatLevel() // growths
{
  if (MaxExp() == true) {
    cout << "Level up!" << endl;
    SetLevel(1);
    cout << "Your level increased to " << GetLevelAfterLU() << endl;
    if (RandomValue() <= 50) {
      maxHealth++;
      cout << "You earned a point in max HP!" << endl;
    }
    if (RandomValue() <= 40) {
      attack++;
      cout << "You earned a point in attack!" << endl;
    }
    if (RandomValue() <= 50) {
      defense++;
      cout << "You earned a point in defense!" << endl;
    }
    if (RandomValue() <= 15) {
      speed++;
      cout << "You earned a point in speed!" << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << endl;
  }
}

void Paladin::SaveGame()
{
  string input = "";
  string fileName = "";
  cout << "Please enter a name for the file." << endl;
  cin >> input;
  fileName = input + ".txt";
  ofstream fout(fileName);
  fout << "Paladin" << endl;         // class
  fout << GetStageNum() << endl;     // stage number
  fout << GetLevel() << endl;        // level
  fout << GetCurrentHp() << endl;    // chp
  fout << GetMaxHp() << endl;        // mhp
  fout << GetAttack() << endl;       // attack
  fout << GetDefense() << endl;      // def
  fout << GetSpeed() << endl;        // spd
  fout << GetExp() << endl;          // exp
  fout << GetGold() << endl;         // gold
  fout << GetElixirAmount() << endl; // elixirs
}

int Paladin::GetWeaponMight(string weapon)
{
  if (weapon == "Bronze Axe") {
    return 4;
  }
  else if (weapon == "Iron Axe") {
    return 8;
  }
  else if (weapon == "Steel Axe") {
    return 12;
  }
  return 15;
}

int Paladin::GetClassCrit()
{
  return 0;
}

void Paladin::SetWeapon(int stage) // attack value for each weapon
{
  if (stage == 2){
    weapon = "Iron Axe";
    cout << "You picked up an Iron Axe!" << endl;
  }
  else if (stage == 3){
    weapon = "Steel Axe";
    cout << "You picked up a Steel Axe!" << endl;
  }
  else {
    weapon = "Silver Axe";
    cout << "You picked up an Silver Axe!" << endl;
  }
}

/*Paladin Growth Rates:
health = 50%
attack = 40%
defense = 50%
speed = 15%*/