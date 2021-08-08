#include <bits/stdc++.h>
using namespace std;

int bank_money;
int pocket_money;
const char *search_places[4] = {"dumpster", "bushes", "cab", "house"};
const char *search_dumpster[2] = {"You earned the money but is this worth getting into the dumpster", "You Fucking stink, go take a bath "};
const char *search_bushes[2] = {"from the wallet a couple dropped after having fun,watchout for the white stuff on the wallet", "A couple was their having fun , No money + beating , be careful next time"};
const char *search_cab[2] = {"You fucking stole wallet of poor driver, Now he doesn't get food tonight. Happy?", "Driver caught you nosing around in the cab, he shoved a stick in your ass"};
const char *search_house[2] = {"Heeey fucker, robbing in a house of elder people now, Stop there thats the limit ", "A grandpa with a gun in hand caught you snooping around , but you tricked him and got away"};

void print_man()
{
     cout << "Commands Manual:" << endl;
     cout << "Command For Gamble : gam 'amount' " << endl;
     cout << "Command For Search for money : search " << endl;
     cout << "Command For Begging for money : beg " << endl;
     cout << "Command For checking money in pocket and bank : bal " << endl;
     cout << "Command For depositing money from pocket to bank : dep 'amount' " << endl;
     cout << "Command For withdrawing money bank : withd 'amount' " << endl;
     cout << "Command For Ending the game : end " << endl;
}

void gambling(int gamble_money)
{
     int roll_player;
     int roll_computer;
     roll_player = rand() % 10;
     roll_computer = rand() % 20;

     cout << "You have rolled " << roll_player << endl;
     cout << "REM has rolled " << roll_computer << endl;

     if (roll_computer < roll_player)
     {
          cout << "Looks like The fairy of Good luck is on Your side." << endl
               << "You've won the bet, You earned " << gamble_money << "Rs" << endl;
          pocket_money += gamble_money;
     }

     else if (roll_computer > roll_player)
     {
          cout << "Booo... Your Good Luck is just like ghost, Both doesn't exist" << endl
               << "You've lost the bet, You lost " << gamble_money << "Rs" << endl;
          pocket_money -= gamble_money;
     }

     else
     {
          cout << "Match Tied";
     }
}

//-------------------------------------------------------------------------------------------------------------

void search_rant(const char *rant_arr[2])
{
     srand(time(0));
     int num = rand();
     if (num % 2 == 0)
     {
          int money_found = 100 + rand() % 200;
          cout << "You found " << money_found << " Rs, " << rant_arr[0] << endl;
          pocket_money += money_found;
     }
     else if (num % 2 != 0)
     {
          cout << "You didn't found anything, " << rant_arr[1] << endl;
     }
}

// ------------------------------------------------------------------------------------------------------------

void search()
{
     srand(time(0));
     cout << "Choose any number from 1 to 4 according to search choices " << endl;
     for (int i = 0; i < 4; i++)
     {
          cout << i + 1 << " " << search_places[i] << endl;
     }

     int place_choice;
     cin >> place_choice;
     if (!place_choice >= 1 && !place_choice <= 4)
     {
          cout << "Choose correct number , " << place_choice << "is not on the list you dumb fucker , Dont waste my time" << endl;
          return;
     }
     if (place_choice == 1)
          search_rant(search_dumpster);
     if (place_choice == 2)
          search_rant(search_bushes);
     if (place_choice == 3)
          search_rant(search_cab);

     if (place_choice == 4)
          search_rant(search_house);
}

// ------------------------------------------------------------------------------------------------------------

void beg()
{
     srand(time(0));
     int num = rand() % 5;
     if (num == 0)
     {
          int money_begged;
          money_begged = 100 + rand() % 100;
          cout << "Jhonny sins gave you " << money_begged << " Rs ,But he was continously staring at you ass, be careful" << endl;
          pocket_money += money_begged;
     }

     if (num == 1)
     {
          int money_begged;
          money_begged = 100 + rand() % 100;
          cout << "Dani Daniels gave you " << money_begged << " Rs. .......Out of pity you lil shit , dont get ahead of youselves" << endl;
          pocket_money += money_begged;
     }

     if (num == 2)
     {
          int money_begged;
          money_begged = 100 + rand() % 100;
          cout << "A dark web hacker gave you " << money_begged << " Rs and took a photo of you" << endl;
          pocket_money += money_begged;
     }

     if (num == 3)
     {
          cout << "You got nothing, Everyone was running after watching your face, You need plastic surgery if you want to continue in this profession" << endl;
     }

     if (num == 4)
     {
          cout << "You really should stop begging and put you lazy ass to some work" << endl;
     }
}

int main()
{
     cout << "Press man to get list of commands ";
     while (1)
     {
          string command;
          cout << "Enter a command :" << endl;
          cin >> command;
          if (command == "man")
          {
               print_man();
          }

          if (command == "gam")
          {
               int money_gamble;
               cin >> money_gamble;
               if (money_gamble > pocket_money)
                    cout << "Earn some money first you lazy assed fucker" << endl;

               else
               {
                    gambling(money_gamble);
               }
          }

          if (command == "search")
          {
               search();
          }

          if (command == "beg")
          {
               beg();
          }

          if (command == "bal")
          {
               cout << "Your pocket has " << pocket_money << " Rs " << endl;
               cout << "Your Bank balance is " << bank_money << " Rs" << endl;
               if (bank_money < 500 && pocket_money < 500)
               {
                    cout << "Isnt it sad that you cant earn money even in a game" << endl;
               }
          }

          if (command == "dep")
          {
               int money;
               cin >> money;
               pocket_money -= money;
               bank_money += money;
          }

          if (command == "withd")
          {
               int amount;
               cin >> amount;
               pocket_money += amount;
               bank_money -= amount;
          }

          if (command == "end")
          {
               break;
          }
     }
}