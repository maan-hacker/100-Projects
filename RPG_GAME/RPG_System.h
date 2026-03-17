#include "Player.cpp"

#ifndef RPG_SYSTEM_H
#define RPG_SYSTEM_H

#include <iostream>
#include <string>
using namespace std;

void battle (Player &player);                      // Function for battle between player and monster
void bossBattles (Player &player);                 // Fucntion for battle between player and Boss monster

void explore (Player &player);                      // Function to Explore
void shop (Player &player);                         // Function for the shop
void showHealthBar (int current, int maximum);      // Function to show Health Bar


#endif
