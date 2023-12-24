#include <iomanip>
#include <chrono>
#include <thread>
#include "Character.cpp"
#include "Lord.cpp"
#include "Paladin.cpp"
#include "Tactician.cpp"
#include "Enemy.h"
#include "Basic_Enemy.cpp"
#include "Final_Boss.cpp"
using namespace std;

void ClassText() 
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
}

// function that displays classes if the input by user is invalid.
// loop terminates when there is a valid input
// returns a string used to determine the class created
string CharacterSelection()
{
  string userNum = "0";
  cin >> userNum;
  while (userNum < "1" || userNum > "3"){
    cout << "Please enter a valid option!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    ClassText();
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
  ClassText();
  option = CharacterSelection();
  ProceedLine();
  cin >> confirmation;
  if (confirmation == "a" || confirmation == "A"){
    cout << "Good choice. That class suits you well." << endl;
    return option;
  }
  else {
    ClassText();
    option = CharacterSelection();
    ProceedLine();
    cin >> confirmation;
    if (confirmation == "a" || confirmation == "A"){ // user confirmation for class they chose
      cout << "Good choice. That class suits you well." << endl;
      return option;
    }
    while (confirmation != "a" || confirmation != "A"){ // loops until the player confirms a class
      ClassText();
      CharacterSelection();
      ProceedLine();
      cin >> confirmation;
      if (confirmation == "a" || confirmation == "A"){
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

int DamageCalculator(int attack, int defense)
{
  if (attack <= defense){
    return 0;
  }
  else {
    return attack-defense;
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

// checks if basic enemy's HP is <= 0. they die if it is
template<typename T> bool Death(T enemy)
{
  if (enemy.GetCurrentHP() <= 0){
    return true;
  }
  return false;
}

// sees if player's HP is <= 0. they die if it is and program terminates
void PlayerDeath(Character *player)
{
  if (player->GetCurrentHp() <= 0){
    cout << "You died." << endl;
    exit(0);
  }
}

// function that runs all the functionalities of the player
// returns a value used for determining whether the player has done damage to a basic enemy or not
template<typename T> int PlayerActions(Character* &p1, T enemy)
{
  string option = "";
  string elixirOption = "";
  CurrentTurn(p1);
  cin >> option;
  if (option == "1"){ // attack
    int randValue = p1->RandomValue();
    int player_damage = 0;
    int critRate = p1->GetBaseCrit() + p1->GetClassCrit();
    if (randValue <= critRate){
      cout << "Critical hit!" << endl;
      player_damage = DamageCalculator((2 * p1->GetAttack()) + p1->GetWeaponMight(p1->GetWeaponType()), enemy.GetDefense());
    }
    else {
      player_damage = DamageCalculator(p1->GetAttack() + p1->GetWeaponMight(p1->GetWeaponType()), enemy.GetDefense());
    }
    cout << "You did " << player_damage << " damage with " << p1->GetWeaponType() << "." << endl;
    p1->SetExp(25);
    p1->StatLevel();
    p1->LevelUp();
    return player_damage;
  }
  else if (option == "2"){ // heal
    cout << "Would you like to use an elixir?" << endl;
    cout << "Press a or A if you would like to use one." << endl;
    cin >> elixirOption;
    if (elixirOption == "a" || elixirOption == "A"){
      if (p1->GetElixirAmount() == 0){
        cout << "No elixirs left." << endl;
      }
      else {
        if (p1->GetCurrentHp() == p1->GetMaxHp()){
          cout << "Elixir had no effect." << endl;
        }
        else {
          cout << "Elixir used. Health has been fully restored!" << endl;
          p1->SetHpElixir(p1->GetMaxHp());
          cout << "Your health is " << p1->GetCurrentHp() << endl;
          p1->ElixirUse();
          cout << p1->GetElixirAmount() << " elixir(s) left." << endl;
        }
      }
    }
    else {
      cout << "Decided not to use an elixir." << endl;
    }
    return 0;
  }
  else if (option == "3"){ // purchase elixir
    p1->ElixirShop();
    return 0;
  }
  return 0;
}

void BasicCombat(Character *player, Basic_Enemy& enemy, int turnNumber)
{
  if (Death(enemy)){
    return;
  }
  cout << "You have " << player->GetCurrentHp() << "HP remaining." << endl;
  cout << enemy.GetName() << " has " << enemy.GetCurrentHP() << "HP remaining." << endl;
  int damage = 0;
  while (damage == 0){ // player turn
    damage = PlayerActions<Basic_Enemy>(player, enemy);
    enemy.SetCurrentHP(damage); // damage calculation for how much HP enemy has left after player attack
  }

  if (Death(enemy)){
    return;
  }

  if (turnNumber == 1){
    cout << enemy.GetName() << " attacked for " << DamageCalculator(enemy.GetAttack(), player->GetDefense()) << " damage!" << endl; // enemy basic attack
    cout << "-------------------------------------------" << endl;
    cout << endl;
    // damage calculation for how much HP player has left after enemy attack
    player->SetCurrentHp(DamageCalculator(enemy.BasicAttack(), player->GetDefense()));
    PlayerDeath(player);
  }
  else if (turnNumber == 2){
    enemy.BeginningChargeAttack(); // enemy charges an attack. they do no damage for 2 turns
    // warns player of how much damage charge attack will do
    cout << "Warning! This attack will do " << DamageCalculator(2 * enemy.GetAttack(), player->GetDefense()) << " damage!" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
  }
  else if (turnNumber == 3){
    enemy.OneTurnChargeAttack(); // last turn of charge up by enemy
    cout << "Warning! This attack will do " << DamageCalculator(enemy.UnleashChargeAttack(), player->GetDefense()) << " damage!" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
  }

  else {
    cout << enemy.GetName() << " attacked for " << DamageCalculator(enemy.UnleashChargeAttack(), player->GetDefense()) << " damage!" << endl; // enemy charged attack
    player->SetCurrentHp(DamageCalculator(enemy.UnleashChargeAttack(), player->GetDefense()));
    PlayerDeath(player);
  }
}

// game loop against a basic enemy
void BasicGameLoop(Character *player, Basic_Enemy enemy)
{
  if (player->GetSpeed() >= enemy.GetSpeed()){ // if the player's speed >= enemy speed, player moves first
    while (true){
      BasicCombat(player, enemy, 1);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 2);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 3);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 4);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
    }
  }
  else {  // if enemy's speed > player's speed, enemy moves first
    cout << enemy.GetName() << " attacked for " << DamageCalculator(enemy.BasicAttack(), player->GetDefense()) << " damage!" << endl; // enemy basic attack
    cout << endl;
    cout << "-------------------------------------------" << endl;
    player->SetCurrentHp(DamageCalculator(enemy.GetAttack(), player->GetDefense()));
    while (true){
      PlayerDeath(player);
      BasicCombat(player, enemy, 2);
      if (Death<Basic_Enemy>(enemy)) {
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 3);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 4);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
      BasicCombat(player, enemy, 1);
      if (Death<Basic_Enemy>(enemy)){
        enemy.Victory();
        return;
      }
    }
  }
}

// game loop against the dragon
void FinalGameLoop(Character *p, Final_Boss drag)
{
  drag.IntroductoryDialogue();
  cout << endl;
  cout << "-------------------------------------------" << endl;
  int damage = 0;
  cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
  while (p->GetCurrentHp() > 0 || drag.GetCurrentHP() > 0){ // while dragon and player HP > 0 game loop runs
    PlayerDeath(p);
    if (Death<Final_Boss>(drag)){ // checks if dragon dies
      break;
    }
    cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl;
    cout << endl;
    damage = 0;
    // 0 damage done means player gets another turn
    while (damage == 0){ // player turn 1
      damage = PlayerActions<Final_Boss>(p, drag);
      drag.SetCurrentHP(damage);
      if (damage > 0) {
        if (Death<Final_Boss>(drag)){
          break;
        }
      }
    }
    drag.SetCurrentHP(damage);
    if (Death<Final_Boss>(drag)){
      drag.VictoryDialogue();
      return;
    }
    // dragon basic attack
    cout << "The Dragon attacked for " << DamageCalculator(drag.BasicAttack(), p->GetDefense()) << " damage!" << endl;
    p->SetCurrentHp(DamageCalculator(drag.BasicAttack(), p->GetDefense()));
    cout << endl;
    cout << "-------------------------------------------" << endl;
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl;
    // dragon's double attack. warns player how much damage it will do
    cout << "The Dragon will do its double attack this turn for " << DamageCalculator(drag.DoubleAttack(), p->GetDefense()) << " damage next turn!" << endl;
    damage = 0;
    while (damage == 0){ // player turn 2
      damage = PlayerActions<Final_Boss>(p, drag);
      drag.SetCurrentHP(damage);
      if (damage > 0) {
        if (Death<Final_Boss>(drag)){
          break;
        }
      }
      cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl; // enemy HP
      cout << endl;
      cout << "-------------------------------------------" << endl;
    }
    if (Death<Final_Boss>(drag)){
      drag.VictoryDialogue();
      return;
    }

    drag.DoubleAttack(); // dialogue for double attack
    p->SetCurrentHp(drag.DoubleAttack() - p->GetDefense());
    // dragon does double attack
    cout << "The Dragon double attacked for " << drag.DoubleAttack() - p->GetDefense() << " damage!" << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0){ // player turn 3
      damage = PlayerActions<Final_Boss>(p, drag);
      drag.SetCurrentHP(damage);
      if (damage > 0){
        if (Death<Final_Boss>(drag)){
          break;
        }
      }
      cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl;
      cout << endl;
      cout << "-------------------------------------------" << endl;
    }
    if (Death<Final_Boss>(drag)){
      drag.VictoryDialogue();
      break;
    }
    drag.PreparingChargeAttack(); // dragon charges an attack that will be unleashed in 2 turns
    // warning of how much damage dragon will do
    cout << "Warning! This attack will do " << (drag.DoingChargeAttack() - p->GetDefense()) << " damage!" << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0){ // player turn 4
      damage = PlayerActions<Final_Boss>(p, drag);
      drag.SetCurrentHP(damage);
      if (damage > 0){
        if (Death<Final_Boss>(drag)){
          break;
        }
      }
      cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl; // enemy HP
      cout << endl;
      cout << "-------------------------------------------" << endl;
    }
    if (Death<Final_Boss>(drag)){
      drag.VictoryDialogue();
      break;
    }
    drag.AlmostDoneChargeAttack(); // 1 turn until charged attack is unleashed
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
    cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl;
    damage = 0;
    while (damage == 0){ // player turn 5
      damage = PlayerActions<Final_Boss>(p, drag);
      drag.SetCurrentHP(damage);
      if (damage > 0){
        if (Death<Final_Boss>(drag)){
          break;
        }
      }
      cout << "The Dragon has " << drag.GetCurrentHP() << "HP remaining." << endl; // enemy HP
      cout << endl;
      cout << "-------------------------------------------" << endl;
    }
    if (Death<Final_Boss>(drag)){
      drag.VictoryDialogue();
      return;
    }
    // dragon unleashes charged attack
    cout << "The Dragon finished charging its attack and did " << DamageCalculator(drag.DoingChargeAttack(), p->GetDefense()) << " damage!" << endl;
    p->SetCurrentHp(DamageCalculator(drag.DoingChargeAttack(), p->GetDefense()));
    PlayerDeath(p);
    cout << "You have " << p->GetCurrentHp() << "HP remaining." << endl;
  }
}

int ParseFile(string fileLine)
{
  fileLine = fileLine.substr(fileLine.find(':')+2);
  return stoi(fileLine);
}

template<typename T> T* LoadSave(T* character, string fileName)
{
  string skippedLine;
  string characterParameter;
  ifstream fin(fileName);
  getline(fin, skippedLine);
  fin.ignore();
  if (character == NULL){
    cout << "Character doesn't exist!";
    exit(1);
  }
  getline(fin, characterParameter);
  character->SetStageNum(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetInputLevel(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetCurrentHpInput(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetMaxHp(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetAttack(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetDefense(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetSpeed(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetExp(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetGold(ParseFile(characterParameter));
  fin.ignore();

  getline(fin, characterParameter);
  character->SetElixirAmount(ParseFile(characterParameter));
  fin.ignore();
  return character;
}

template<typename T> T* UpdateCharacter(T* character, int stageNum)
{
  character->AfterLevelStageNum(1); // function that increments stage level by 1
  character->SetHpAfterBattle(character->GetMaxHp()); // function that heals player to full HP after a stage
  character->SetGoldEnemyDefeat(2000); // function that adds 2000 gold to player's inventory
  character->SetWeapon(stageNum); // function that grants player a new weapon
  character->SaveGame();
  return character;
}

int main()
{
  string returning = "";
  Basic_Enemy fear = Basic_Enemy(30, 30, 7, 7, 4); // max HP , current HP, atk, spd, def on fl1
  fear.SetName("Fear");                             // name for basic enemy on fl1
  Basic_Enemy midway = Basic_Enemy(35, 35, 9, 0, 8); //max HP , current HP, atk, spd, def on fl2
  midway.SetName("Midway"); // name for basic enemy on fl2
  Basic_Enemy gatekeeper = Basic_Enemy(40, 40, 11, 6, 6);
  gatekeeper.SetName("Gatekeeper");                           // name for basic enemy on fl3
  Final_Boss Dragon = Final_Boss(50, 50, 13, 13, 7); // max HP, current HP, atk, spd, def
  ReturningPlayer();
  Lord lord;
  Paladin paladin;
  Tactician tactician;
  Character* character = dynamic_cast<Character*>(&lord);
  cin >> returning;
  // if returning = a || A, creates new character
  if (returning == "a" || returning == "A"){
    string classType = NewGameIntros();
    // class type returned by NewGameIntros() function
    if (classType == "1"){
      Character *lord = new Lord;
      character = lord;
      character = static_cast<Lord *>(character);
    }
    else if (classType == "2"){
      Character *paladin = new Paladin;
      character = paladin;
      character = static_cast<Paladin *>(character);
    }
    else {
      Character *tactician = new Tactician;
      character = tactician;
      character = static_cast<Tactician *>(character);
    }
    character->SaveGame();
  }

  // loads a save
  else {
    string quality;
    cout << "What is the save you are looking for?" << endl;
    cout << "Please type the name of the save file you are looking for." << endl;
    string fileName;
    cin >> fileName; //add .txt to the input
    ifstream fin(fileName);

    // if save cant be found, program terminates
    if (!fin.is_open()){
      cout << "Couldn't find the file you're looking for." << endl;
      cout << "Please run the program again with a different input." << endl;
      exit(0);
    }
    fin >> quality;
    fin.close();

    // loads in file depending on first line of file, which is the class
    if (quality == "Lord"){
      Lord* l2 = dynamic_cast<Lord*>(character);    
      character = LoadSave<Lord>(l2, fileName);
    }
    else if (quality == "Paladin"){
      character = dynamic_cast<Character*>(&paladin);
      Paladin* p2 = dynamic_cast<Paladin*>(character);    
      character = LoadSave<Paladin>(p2, fileName);

    }
    else {
      character = dynamic_cast<Character*>(&tactician);
      Tactician* t2 = dynamic_cast<Tactician*>(character);    
      character = LoadSave<Tactician>(t2, fileName);
    }
  }
  
  // loads a different set of stages depending on stage number in the file
  if (character->GetStageNum() == 1){
    BasicGameLoop(character, fear);
    character = UpdateCharacter(character, 2);
    BasicGameLoop(character, midway);
    character = UpdateCharacter(character, 3);
    BasicGameLoop(character, gatekeeper);
    character = UpdateCharacter(character, 4);
    FinalGameLoop(character, Dragon);
  }

  else if (character->GetStageNum() == 2){
    character->SetWeapon(2);
    BasicGameLoop(character, midway);
    character = UpdateCharacter(character, 3);
    BasicGameLoop(character, gatekeeper);
    character = UpdateCharacter(character, 4);
    FinalGameLoop(character, Dragon);
  }

  else if (character->GetStageNum() == 3){
    character->SetWeapon(3);
    BasicGameLoop(character, gatekeeper);
    character = UpdateCharacter(character, 4);
    FinalGameLoop(character, Dragon);
  }

  else {
    character->SetWeapon(4);
    FinalGameLoop(character, Dragon);
  }
  delete character; // deallocates memory of character object
  return 0;
}