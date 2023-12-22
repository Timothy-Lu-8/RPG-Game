#include "Tactician.h"

Tactician::Tactician() : Character() // stats + seed's randomly generated values for each stat
{
  srand(time(0));
  int randHealth = rand() % 3;
  currentHealth = 20 + randHealth;
  maxHealth = 20 + randHealth;
  attack = 6 + rand() % 3;
  defense = 4 + rand() % 2;
  speed = 8 + rand() % 3;
  weapon = "Fire";
  baseCritRate = 10;
}

void Tactician::StatLevel() // growths
{
  if (MaxExp() == true) {
    cout << "Level up!" << endl;
    SetLevel(1);
    cout << "Your level increased to " << GetLevelAfterLU() << endl;
    if (RandomValue() <= 30) {
      maxHealth++;
      cout << "You earned a point in max HP!" << endl;
    }
    if (RandomValue() <= 60) {
      attack++;
      cout << "You earned a point in attack!" << endl;
    }
    if (RandomValue() <= 20) {
      defense++;
      cout << "You earned a point in defense!" << endl;
    }
    if (RandomValue() <= 45) {
      speed++;
      cout << "You earned a point in speed!" << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << endl;
  }
}

void Tactician::SaveGame()
{
  string input = "";
  string fileName = "";
  cout << "Please enter a name for the file." << endl;
  cin >> input;
  fileName = input + ".txt";
  ofstream fout(fileName);
  fout << "Tactician" << endl;       // class
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

int Tactician::GetWeaponMight(string weapon) // attack value for each weapon
{
  if (weapon == "Fire"){
    return 2;
  }
  else if (weapon == "Elwind") {
    return 4;
  }
  else if (weapon == "Arcthunder") {
    return 10;
  }
  return 7;
}

int Tactician::GetClassCrit()
{
  return 10;
}

void Tactician::SetWeapon(int stage)
{
  if (stage == 2) {
    weapon = "Elwind";
    cout << "You picked up an Elwind tome!" << endl;
  }
  else if (stage == 3) {
    weapon = "Arcthunder";
    cout << "You picked up an Arcthunder tome!" << endl;
  }
  else {
    weapon = "Flux";
    cout << "You picked up a Flux tome!" << endl;
  }
}

/*Tactician Growth Rates:
health = 30%
attack = 60%
defense = 20%
speed = 45%*/