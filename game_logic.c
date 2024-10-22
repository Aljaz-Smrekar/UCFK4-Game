/** @file   game_logic.c
    @author L Sumnner, A Smrekar
    @date   12 October 2022
    @brief  Game logic variables
    @note   variables that hold the game states of the players.
*/

#include "game_logic.h"

// Define the variables declared in game_logic.h
Choice player_choice;
char opponent_choice;
Choice hold;
bool player_selection_made = false;  // Initialised to false
bool opponent_selection_made = false; // Initialised to false
