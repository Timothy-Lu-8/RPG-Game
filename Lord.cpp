#include "Lord.h"

Lord::Lord() : Character()
{ // stats + seed's randomly generated values for each stat
  srand(time(0));
  int randHealth = rand() % 6;
  currentHealth = 20 + randHealth;
  maxHealth = 20 + randHealth;
  attack = 4 + rand() % 2;
  defense = 5 + rand() % 2;
  speed = 6 + rand() % 2;
  weapon = "Bronze Sword";
}

void Lord::StatLevel()
{ // growths
  if (MaxExp() == true)
  {
    cout << "Level up!" << endl;
    SetLevel(1);
    cout << "Your level increased to " << GetLevelAfterLU() << endl;
    if (RandomValue() <= 40)
    {
      maxHealth++;
      cout << "You earned a point in max HP!" << endl;
    }
    if (RandomValue() <= 40)
    {
      attack++;
      cout << "You earned a point in attack!" << endl;
    }
    if (RandomValue() <= 40)
    {
      defense++;
      cout << "You earned a point in defense!" << endl;
    }
    if (RandomValue() <= 30)
    {
      speed++;
      cout << "You earned a point in speed!" << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << endl;
  }
}

void Lord::SaveGame()
{
  string input = "";
  string fileName = "";
  cout << "Please enter a name for the file." << endl;
  cin >> input;
  fileName = input + ".txt";
  ofstream fout(fileName);
  fout << "Lord" << endl;            // class
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

int Lord::GetWeaponMight(string weapon)
{
  // attack value for each weapon
  if (weapon == "Bronze Sword")
  {
    return 5;
  }
  else if (weapon == "Iron Sword")
  {
    return 7;
  }
  else if (weapon == "Steel Sword")
  {
    return 11;
  }
  else
  {
    return 14;
  }
}

int Lord::GetClassCrit()
{
  return 0;
}

void Lord::SetWeapon(int stage)
{
  if (stage == 2)
  {
    weapon = "Iron Sword";
    cout << "You picked up an Iron Sword!" << endl;
  }

  else if (stage == 3)
  {
    weapon = "Steel Sword";
    cout << "You picked up a Steel Sword!" << endl;
  }

  else
  {
    weapon = "Silver Sword";
    cout << "You picked up a Silver Sword!" << endl;
  }
}

/*Lord Growth Rates:
maxHealth = 40%;
int attack = 40%;
int defense = 40%;
int speed = 25%;*/