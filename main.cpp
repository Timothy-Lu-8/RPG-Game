#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include "Character.h"
#include "Character.cpp"
#include "Lord.h"
#include "Lord.cpp"
#include "Paladin.h"
#include "Paladin.cpp"
#include "Tactician.h"
#include "Tactician.cpp"
#include "Enemy.h"
#include "Basic_Enemy.h"
#include "Basic_Enemy.cpp"
#include "Final_Boss.h"
#include "Final_Boss.cpp"
using namespace std;

// function that displays classes if the input by user is invalid.
// loop terminates when there is a valid input
////returns a string used to determine the class created
string CharacterSelection()
{
  string userNum = "0";
  cin >> userNum;
  while (userNum < "1" || userNum > "3")
  {
    cout << "Please enter a valid option!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Press 1 for the Lord class." << endl;
    cout << "The Lord class is a well-rounded class that is strong from start to finish." << endl;
    cout << "This class uses swords." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Press 2 for the Paladin class." << endl;
    cout << "The Paladin class sacrifices speed for defensive stats and attack power." << endl;
    cout << "This means the Paladin will usually move second in a turn." << endl;
    cout << "This class uses axes." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Press 3 for the Tactician class." << endl;
    cout << "The Tactician class excels as a glass cannon, excelling in damage and speed." << endl;
    cout << "The Tactician class also has a higher crit rate." << endl;
    cout << "Tacticians start off slow due to their lack of knowledge on tomes." << endl;
    cout << "As the game goes on, Tacticians earn more experience through defeating enemies." << endl;
    cout << "With this added knowledge, they will become even more dangerous to enemies." << endl;
    cout << "This class uses tomes." << endl;
    cin >> userNum;
  }
  return userNum;
}

void ProceedLine()
{
  cout << "Are you sure you want to choose this class? Press a or A to proceed." << endl;
}

// funtion that displays text when creating new character.
// returns a string used to determine the class created
string NewGameIntros()
{
  string confirmation = "w";
  string option = "q";
  cout << "Hello! Welcome to Weak Seed v.1.0.0!" << endl;
  cout << "First, you need to choose a class." << endl; // character selection
  cout << endl;
  cout << "Press 1 for the Lord class." << endl;
  cout << "The Lord class is a well-rounded class that is strong from start to finish." << endl;
  cout << "This class uses swords." << endl;
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "Press 2 for the Paladin class." << endl;
  cout << "The Paladin class sacrifices speed for defensive stats and attack power." << endl;
  cout << "This means the Paladin will usually move second in a turn." << endl;
  cout << "This class uses axes." << endl;
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "Press 3 for the Tactician class." << endl;
  cout << "The Tactician class excels as a glass cannon, excelling in damage and speed." << endl;
  cout << "The Tactician class also has a higher crit rate." << endl;
  cout << "Tacticians start off slow due to their lack of knowledge on tomes." << endl;
  cout << "As the game goes on, Tacticians earn more experience through defeating enemies." << endl;
  cout << "With this added knowledge, they will become even more dangerous to enemies." << endl;
  cout << "This class uses tomes." << endl;
  option = CharacterSelection();
  ProceedLine();
  cin >> confirmation;
  if (confirmation == "a" || confirmation == "A")
  {
    cout << "Good choice. That class suits you well." << endl;
    return option;
  }
  else
  {
    cout << "Press 1 for the Lord class." << endl;
    cout << "The Lord class is a well-rounded class that is strong from start to finish." << endl;
    cout << "This class uses swords." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Press 2 for the Paladin class." << endl;
    cout << "The Paladin class sacrifices speed for defensive stats and attack power." << endl;
    cout << "This means the Paladin will usually move second in a turn." << endl;
    cout << "This class uses axes." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Press 3 for the Tactician class." << endl;
    cout << "The Tactician class excels as a glass cannon, excelling in damage and speed." << endl;
    cout << "The Tactician class also has a higher crit rate." << endl;
    cout << "Tacticians start off slow due to their lack of knowledge on tomes." << endl;
    cout << "As the game goes on, Tacticians earn more experience through defeating enemies." << endl;
    cout << "With this added knowledge, they will become even more dangerous to enemies." << endl;
    cout << "This class uses tomes." << endl;
    option = CharacterSelection();
    ProceedLine();
    cin >> confirmation;
    if (confirmation == "a" || confirmation == "A")
    { // user confirmation for class they chose
      cout << "Good choice. That class suits you well." << endl;
      return option;
    }
    while (confirmation != "a" || confirmation != "A")
    { // loops until the player confirms a class
      cout << "Press 1 for the Lord class." << endl;
      cout << "The Lord class is a well-rounded class that is strong from start to finish." << endl;
      cout << "This class uses swords." << endl;
      cout << "--------------------------------------------------------------------------------" << endl;
      cout << "Press 2 for the Paladin class." << endl;
      cout << "The Paladin class sacrifices speed for defensive stats and attack power." << endl;
      cout << "This means the Paladin will usually move second in a turn." << endl;
      cout << "This class uses axes." << endl;
      cout << "--------------------------------------------------------------------------------" << endl;
      cout << "Press 3 for the Tactician class." << endl;
      cout << "The Tactician class excels as a glass cannon, excelling in damage and speed." << endl;
      cout << "The Tactician class also has a higher crit rate." << endl;
      cout << "Tacticians start off slow due to their lack of knowledge on tomes." << endl;
      cout << "As the game goes on, Tacticians earn more experience through defeating enemies." << endl;
      cout << "With this added knowledge, they will become even more dangerous to enemies." << endl;
      cout << "This class uses tomes." << endl;
      CharacterSelection();
      ProceedLine();
      cin >> confirmation;
      if (confirmation == "a" || confirmation == "A")
      {
        break;
      }
    }
  }
  cout << "Good choice. That class suits you well." << endl;
  return option;
}

// first message output by program when running.
void ReturningPlayer()
{
  cout << "Hello, are you continuing a preexisting save?" << endl;
  cout << "Press a or A if you are not. Otherwise, press any other key." << endl;
}

// sees if player's hp is <= 0. they die if it is and program terminates
void PlayerDeath(Character *player)
{
  if (!(player->GetCurrentHp() > 0))
  {
    cout << "You died." << endl;
    exit(0);
  }
}

// menu for player on their turn
void CurrentTurn(Character *p)
{
  cout << "-------------------------------------------" << endl;
  cout << endl;
  cout << "What would you like to do this turn?" << endl;
  cout << endl;
  cout << "-------------------------------------------" << endl;
  cout << "You have " << p->GetElixirAmount() << " elixirs left." << endl;
  cout << "You have " << p->GetGold() << " gold." << endl;
  cout << endl;
  cout << "-------------------------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  cout << "1.Attack" << endl;
  cout << "2.Elixir \t\t\t"
       << "3.Elixir Shop" << endl;
}

// messages output after basic enemy's hp reaches 0
void Victory(Basic_Enemy enemy)
{
  cout << enemy.GetName() << " has been defeated!" << endl;
  cout << "You earned 2000 gold!" << endl;
}

// checks if basic enemy's hp is <= 0. they die if it is
bool BasicEnemyDeath(Character *player, Basic_Enemy enemy)
{
  if (enemy.GetCurrentHP() <= 0)
  {
    return true;
  }
  return false;
}

// function that checks if dragon's hp is <= 0. it die if it is
bool FinalEnemyDeath(Character *player, Final_Boss enemy)
{
  if (enemy.GetCurrentHP() <= 0)
  {
    return true;
  }
  return false;
}

// function that runs all the functionalities of the player
// returns a value used for determining whether the player has done damage to a basic enemy or not
int PlayerTurn(Character *p1, Basic_Enemy enemy)
{
  string option = "";
  string elixirOption = "";
  CurrentTurn(p1);
  cin >> option;
  if (option == "1")
  {
    int randValue = p1->RandomValue();
    int player_damage = 0;
    int critRate = p1->GetBaseCrit() + p1->GetClassCrit();
    if (randValue <= critRate)
    {
      cout << "Critical hit!" << endl;
      player_damage = (2 * p1->GetAttack()) + p1->GetWeaponMight(p1->GetWeaponType());
      cout << "You did " << player_damage - enemy.GetDefense() << " damage with " << p1->GetWeaponType() << "." << endl;
    }
    else
    {
      player_damage = p1->GetAttack() + p1->GetWeaponMight(p1->GetWeaponType());
      cout << "You did " << player_damage - enemy.GetDefense() << " damage with " << p1->GetWeaponType() << "." << endl;
    }
    p1->SetExp(25);
    p1->StatLevel();
    p1->LevelUp();
    return (player_damage - enemy.GetDefense());
  }
  else if (option == "2")
  {
    cout << "Would you like to use an elixir?" << endl;
    cout << "Press a or A if you would like to use one." << endl;
    cin >> elixirOption;
    if (elixirOption == "a" || elixirOption == "A")
    {
      if (p1->GetElixirAmount() == 0)
      {
        cout << "No elixirs left." << endl;
      }
      else
      {
        if (p1->GetCurrentHp() == p1->GetMaxHp())
        {
          cout << "Elixir had no effect." << endl;
        }
        else
        {
          cout << "Elixir used. Health has been fully restored!" << endl;
          p1->SetHpElixir(p1->GetMaxHp());
          cout << "Your health is " << p1->GetCurrentHp() << endl;
          p1->ElixirUse();
          cout << p1->GetElixirAmount() << " elixir(s) left." << endl;
        }
      }
    }
    else
    {
      cout << "Decided not to use an elixir." << endl;
    }
    return 0;
  }
  else if (option == "3")
  {
    p1->ElixirShop();
    return 0;
  }
  return 0;
}

// function that runs all the functionalities of the player
// returns a value used for determining whether the player has done damage to the dragon or not
int FPlayerTurn(Character *p1, Final_Boss enemy)
{
  string option = "";
  string elixirOption = "";
  CurrentTurn(p1);
  cin >> option;
  if (option == "1")
  {
    int randValue = p1->RandomValue();
    int player_damage = 0;
    int critRate = p1->GetBaseCrit() + p1->GetClassCrit();
    if (randValue <= critRate)
    {
      cout << "Critical hit!" << endl;
      player_damage = (2 * p1->GetAttack()) + p1->GetWeaponMight(p1->GetWeaponType());
      cout << "You did " << player_damage - enemy.GetDefense() << " damage with " << p1->GetWeaponType() << "." << endl;
    }
    else
    {
      player_damage = p1->GetAttack() + p1->GetWeaponMight(p1->GetWeaponType());
      cout << "You did " << player_damage - enemy.GetDefense() << " damage with " << p1->GetWeaponType() << "." << endl;
    }
    p1->SetExp(25);
    p1->StatLevel();
    p1->LevelUp();
    return (player_damage - enemy.GetDefense());
  }
  else if (option == "2")
  {
    cout << "Would you like to use an elixir?" << endl;
    cout << "Press a or A if you would like to use one." << endl;
    cin >> elixirOption;
    if (elixirOption == "a" || elixirOption == "A")
    {
      if (p1->GetElixirAmount() == 0)
      {
        cout << "No elixirs left." << endl;
      }
      else
      {
        cout << "Elixir used. Health has been fully restored!" << endl;
        p1->SetHpElixir(p1->GetMaxHp());
        cout << "Your health is " << p1->GetCurrentHp() << endl;
        p1->ElixirUse();
        cout << p1->GetElixirAmount() << " elixir(s) left." << endl;
      }
    }
    return 0;
  }
  else if (option == "3")
  {
    p1->ElixirShop();
    return 0;
  }
  return 0;
}

// game loop against a basic enemy
void BasicGameLoop(Character *player, Basic_Enemy enemy)
{
  int damage = 0;
  cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
  while (player->GetCurrentHp() > 0 || enemy.GetCurrentHP() > 0)
  {                      // while neither hp is <= 0
    PlayerDeath(player); // if player dies, exits game loop
    if (player->GetSpeed() >= enemy.GetSpeed())
    { // if the player's speed >= enemy speed, player moves first
      if (BasicEnemyDeath(player, enemy))
      { // if the enemy dies, exits game loop
        break;
      }
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = PlayerTurn(player, enemy);
      // if damage = 0 (no damage done by player) the player gets another turn. other wise, game loop continues
      while (damage == 0)
      { // player turn 1
        damage = PlayerTurn(player, enemy);
        enemy.SetCurrentHP(damage); // damage calculation for how much hp enemy has left after player attack
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
      }
      enemy.SetCurrentHP(damage);
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      cout << enemy.GetName() << " attacked for " << enemy.BasicAttack() - player->GetDefense() << " damage!" << endl; // enemy basic attack
      cout << "-------------------------------------------" << endl;
      cout << endl;
      // damage calculation for how much hp player has left after enemy attack
      player->SetCurrentHp(enemy.BasicAttack() - player->GetDefense());
      PlayerDeath(player);
      // output player's remaining hp after enemy attack
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      // output enemy's remaining hp after player attack
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 2
        damage = PlayerTurn(player, enemy);
        enemy.SetCurrentHP(damage);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
      }
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      cout << "-------------------------------------------" << endl;
      cout << endl;
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      enemy.BeginningChargeAttack(); // enemy charges an attack. they do no damage for 2 turns
      // warns player of how much damage charge attack will do
      cout << "Warning! This attack will do " << (2 * enemy.GetAttack()) - player->GetDefense() << " damage!" << endl;
      cout << "-------------------------------------------" << endl;
      cout << endl;
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 3
        damage = PlayerTurn(player, enemy);
        enemy.SetCurrentHP(damage);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
        cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl; // enemy hp
        cout << "-------------------------------------------" << endl;
        cout << endl;
      }
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      enemy.OneTurnChargeAttack(); // last turn of charge up by enemy
      cout << "Warning! This attack will do " << (enemy.UnleashChargeAttack() - player->GetDefense()) << " damage!" << endl;
      cout << "-------------------------------------------" << endl;
      cout << endl;
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 4
        damage = PlayerTurn(player, enemy);
        enemy.SetCurrentHP(damage);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
        cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
        cout << endl;
        cout << "-------------------------------------------" << endl;
      }
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      cout << enemy.GetName() << " attacked for " << enemy.UnleashChargeAttack() - player->GetDefense() << " damage!" << endl; // enemy charged attack
      player->SetCurrentHp(enemy.UnleashChargeAttack() - player->GetDefense());
      PlayerDeath(player);
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
    }
    else
    {                                                                                                                  // game loop that runs if the enemy's speed > player's speed
      cout << enemy.GetName() << " attacked for " << enemy.BasicAttack() - player->GetDefense() << " damage!" << endl; // enemy basic attack
      cout << endl;
      cout << "-------------------------------------------" << endl;
      player->SetCurrentHp(enemy.GetAttack() - player->GetDefense());
      PlayerDeath(player);
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 1
        damage = PlayerTurn(player, enemy);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
      }
      enemy.SetCurrentHP(damage);
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      enemy.BeginningChargeAttack(); // enemy begins charging
      cout << "Warning! This attack will do " << (enemy.UnleashChargeAttack() - player->GetDefense()) << " damage!" << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 2
        damage = PlayerTurn(player, enemy);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
        enemy.SetCurrentHP(damage);
      }
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      enemy.OneTurnChargeAttack(); // one turn before enemy does charge attack
      cout << "Warning! This attack will do " << (enemy.UnleashChargeAttack() - player->GetDefense()) << " damage!" << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 3
        damage = PlayerTurn(player, enemy);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
      }
      enemy.SetCurrentHP(damage);
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
      enemy.UnleashChargeAttack(); // enemy uses charge attack
      cout << enemy.GetName() << " attacked for " << enemy.UnleashChargeAttack() - player->GetDefense() << " damage!" << endl;
      player->SetCurrentHp(enemy.UnleashChargeAttack() - player->GetDefense());
      PlayerDeath(player);
      cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
      cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
      damage = 0;
      while (damage == 0)
      { // player turn 4
        damage = PlayerTurn(player, enemy);
        if (damage > 0)
        {
          if (BasicEnemyDeath(player, enemy))
          {
            break;
          }
        }
      }
      enemy.SetCurrentHP(damage);
      if (BasicEnemyDeath(player, enemy))
      {
        Victory(enemy);
        break;
      }
    }
  }
}

// game loop against the dragon
void FinalGameLoop(Character *p, Final_Boss f)
{
  f.IntroductoryDialogue();
  cout << endl;
  cout << "-------------------------------------------" << endl;
  int damage = 0;
  cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
  while (p->GetCurrentHp() > 0 || f.GetCurrentHP() > 0)
  {                 // while dragon and player > 0 game loop runs
    PlayerDeath(p); // checks if player dies
    if (FinalEnemyDeath(p, f))
    { // checks if dragon dies
      break;
    }
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    cout << endl;
    damage = FPlayerTurn(p, f);
    // 0 damage done means player gets another turn
    while (damage == 0)
    { // player turn 1
      damage = FPlayerTurn(p, f);
      f.SetCurrentHP(damage);
      if (damage > 0)
      {
        if (FinalEnemyDeath(p, f))
        {
          break;
        }
      }
    }
    f.SetCurrentHP(damage);
    if (FinalEnemyDeath(p, f))
    { // breaks out while loop and outputs victory dialogue
      f.VictoryDialogue();
      break;
    }
    // dragon basic attack
    cout << "The Dragon attacked for " << f.BasicAttack() - p->GetDefense() << " damage!" << endl;
    p->SetCurrentHp(f.BasicAttack() - p->GetDefense());
    cout << endl;
    cout << "-------------------------------------------" << endl;
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    // dragon's double attack. warns player how much damage it will do
    cout << "The Dragon will do its double attack next turn for " << f.DoubleAttack() - p->GetDefense() << " damage next turn!" << endl;
    damage = 0;
    while (damage == 0)
    { // player turn 2
      damage = FPlayerTurn(p, f);
      f.SetCurrentHP(damage);
      if (damage > 0)
      {
        if (FinalEnemyDeath(p, f))
        {
          break;
        }
      }
    }
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    if (FinalEnemyDeath(p, f))
    {
      f.VictoryDialogue();
      break;
    }

    f.DoubleAttack(); // dialogue for double attack
    p->SetCurrentHp(f.DoubleAttack() - p->GetDefense());
    // dragon does double attack
    cout << "The Dragon double attacked for " << f.DoubleAttack() - p->GetDefense() << " damage!" << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0)
    { // player turn 2
      damage = FPlayerTurn(p, f);
      f.SetCurrentHP(damage);
      if (damage > 0)
      {
        if (FinalEnemyDeath(p, f))
        {
          break;
        }
      }
    }
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    if (FinalEnemyDeath(p, f))
    {
      f.VictoryDialogue();
      break;
    }
    f.PreparingChargeAttack(); // dragon charges an attack that will be unleashed in 2 turns
    // warning of how much damage dragon will do
    cout << "Warning! This attack will do " << (f.DoingChargeAttack() - p->GetDefense()) << " damage!" << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0)
    { // player turn 3
      damage = FPlayerTurn(p, f);
      f.SetCurrentHP(damage);
      if (damage > 0)
      {
        if (FinalEnemyDeath(p, f))
        {
          break;
        }
      }
      cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl; // enemy hp
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;
    if (FinalEnemyDeath(p, f))
    {
      f.VictoryDialogue();
      break;
    }
    f.AlmostDoneChargeAttack(); // 1 turn until charged attack is unleashed
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0)
    { // player turn 4
      damage = FPlayerTurn(p, f);
      f.SetCurrentHP(damage);
      if (damage > 0)
      {
        if (FinalEnemyDeath(p, f))
        {
          break;
        }
      }
      cout << "The Dragon has " << f.GetCurrentHP() << "HP remaining." << endl; // enemy hp
      cout << endl;
      cout << "-------------------------------------------" << endl;
    }
    if (FinalEnemyDeath(p, f))
    {
      f.VictoryDialogue();
      break;
    }
    // dragon unleashes charged attack
    cout << "The Dragon finished charging its attack and did " << f.DoingChargeAttack() - p->GetDefense() << " damage!" << endl;
    p->SetCurrentHp(f.DoingChargeAttack() - p->GetDefense());
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
  }
}

int main()
{
  string returning = "";
  Character *character;
  Basic_Enemy a = Basic_Enemy(30, 30, 7, 10, 4); // max hp , current hp, atk, spd, def
  a.SetName("Fear");                             // name for basic enemy on fl1
  Basic_Enemy b = Basic_Enemy(35, 35, 9, 0, 8);
  b.SetName("Midway"); // name for basic enemy on fl2
  Basic_Enemy c = Basic_Enemy(40, 40, 11, 6, 6);
  c.SetName("Gatekeeper");                           // name for basic enemy on fl3
  Final_Boss Dragon = Final_Boss(50, 50, 13, 13, 7); // max hp, current hp, atk, spd, def
  ReturningPlayer();
  cin >> returning;
  // if returning = a || A, creates new character
  if (returning == "a" || returning == "A")
  {
    string a = NewGameIntros();
    // a returned by NewGameIntros() function
    if (a == "1")
    {
      Character *lord = new Lord;
      character = lord;
      character = static_cast<Lord *>(character);
      character->SaveGame();
    }
    else if (a == "2")
    {
      Character *paladin = new Paladin;
      character = paladin;
      character = static_cast<Paladin *>(character);
      character->SaveGame();
    }
    else
    {
      Character *tactician = new Tactician;
      character = tactician;
      character = static_cast<Tactician *>(character);
      character->SaveGame();
    }
  }
  // if return != a || returning != A, loads a save
  else
  {
    string quality;
    int stageNumInput;
    int lvlInput;
    int cHpInput;
    int mHpInput;
    int atkInput;
    int defInput;
    int spdInput;
    int expInput;
    int goldInput;
    int elixirInput;
    cout << "What is the save you are looking for?" << endl;
    cout << "Please type the name of the save file you are looking for." << endl;
    string fileName;
    cin >> fileName;
    ifstream fin(fileName);
    // if save cant be found, program terminates
    if (!fin.is_open())
    {
      cout << "Couldn't find the file you're looking for." << endl;
      cout << "Please run the program again with a different input." << endl;
      exit(0);
    }
    fin >> quality;
    // loads in file depending on first line of file, which is the class
    if (quality == "Lord")
    {
      Character *lord2 = new Lord;
      character = lord2;
      character = static_cast<Lord *>(character);
      fin >> stageNumInput;
      character->SetStageNum(stageNumInput);
      fin >> lvlInput;
      character->SetInputLevel(lvlInput);
      fin >> cHpInput;
      character->SetCurrentHpInput(cHpInput);
      fin >> mHpInput;
      character->SetMaxHp(mHpInput);
      fin >> atkInput;
      character->SetAttack(atkInput);
      fin >> defInput;
      character->SetDefense(defInput);
      fin >> spdInput;
      character->SetSpeed(spdInput);
      fin >> expInput;
      character->SetExpInput(expInput);
      fin >> goldInput;
      character->SetGold(goldInput);
      fin >> elixirInput;
      character->SetElixirAmount(elixirInput);
    }
    else if (quality == "Paladin")
    {
      Character *paladin2 = new Paladin;
      character = paladin2;
      character = static_cast<Paladin *>(character);
      fin >> stageNumInput;
      character->SetStageNum(stageNumInput);
      fin >> lvlInput;
      character->SetInputLevel(lvlInput);
      fin >> cHpInput;
      character->SetCurrentHpInput(cHpInput);
      fin >> mHpInput;
      character->SetMaxHp(mHpInput);
      fin >> atkInput;
      character->SetAttack(atkInput);
      fin >> defInput;
      character->SetDefense(defInput);
      fin >> spdInput;
      character->SetSpeed(spdInput);
      fin >> expInput;
      character->SetExpInput(expInput);
      fin >> goldInput;
      character->SetGold(goldInput);
      fin >> elixirInput;
      character->SetElixirAmount(elixirInput);
    }
    else
    {
      Character *tactician2 = new Tactician;
      character = tactician2;
      character = static_cast<Tactician *>(character);
      fin >> stageNumInput;
      character->SetStageNum(stageNumInput);
      fin >> lvlInput;
      character->SetInputLevel(lvlInput);
      fin >> cHpInput;
      character->SetCurrentHpInput(cHpInput);
      fin >> mHpInput;
      character->SetMaxHp(mHpInput);
      fin >> atkInput;
      character->SetAttack(atkInput);
      fin >> defInput;
      character->SetDefense(defInput);
      fin >> spdInput;
      character->SetSpeed(spdInput);
      fin >> expInput;
      character->SetExpInput(expInput);
      fin >> goldInput;
      character->SetGold(goldInput);
      fin >> elixirInput;
      character->SetElixirAmount(elixirInput);
    }
  }
  // loads a different set of stages depending on stage number in the file
  if (character->GetStageNum() == 1)
  {
    BasicGameLoop(character, a);
    // function that increments stage level by 1
    character->AfterLevelStageNum(1);
    // function that heals player to full hp after a stage
    character->SetHpAfterBattle(character->GetMaxHp());
    // function that adds 2000 gold to player's inventory
    character->SetGoldEnemyDefeat(2000);
    // function that grants player a strong weapon
    character->SetWeapon(2);
    // function that saves the game after obtaining all rewards from beating a floor
    character->SaveGame();
    BasicGameLoop(character, b);
    character->AfterLevelStageNum(1);
    character->SetHpAfterBattle(character->GetMaxHp());
    character->SetGoldEnemyDefeat(2000);
    character->SetWeapon(3);
    character->SaveGame();
    BasicGameLoop(character, c);
    character->AfterLevelStageNum(1);
    character->SetHpAfterBattle(character->GetMaxHp());
    character->SetGoldEnemyDefeat(2000);
    character->SetWeapon(4);
    character->SaveGame();
    FinalGameLoop(character, Dragon);
  }

  if (character->GetStageNum() == 2)
  {
    character->SetWeapon(2);
    BasicGameLoop(character, b);
    character->AfterLevelStageNum(1);
    character->SetHpAfterBattle(character->GetMaxHp());
    character->SetGoldEnemyDefeat(2000);
    character->SetWeapon(3);
    character->SaveGame();
    BasicGameLoop(character, c);
    character->AfterLevelStageNum(1);
    character->SetHpAfterBattle(character->GetMaxHp());
    character->SetGoldEnemyDefeat(2000);
    character->SetWeapon(4);
    character->SaveGame();
    FinalGameLoop(character, Dragon);
  }

  if (character->GetStageNum() == 3)
  {
    character->SetWeapon(3);
    BasicGameLoop(character, c);
    character->AfterLevelStageNum(1);
    character->SetHpAfterBattle(character->GetMaxHp());
    character->SetGoldEnemyDefeat(2000);
    character->SetWeapon(4);
    character->SaveGame();
    FinalGameLoop(character, Dragon);
  }

  else
  {
    character->SetWeapon(4);
    FinalGameLoop(character, Dragon);
  }
  delete character; // deletes character pointer
  return 0;
}