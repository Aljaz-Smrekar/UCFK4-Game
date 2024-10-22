/** @file   game_logic.h
    @author L Sumnner, A Smrekar
    @date   12 October 2022
    @brief  Game logic variables
    @note   variables that hold the game states of the players.
*/

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdbool.h>

typedef enum {
    PAPER,
    SCISSORS,
    ROCK
} Choice;

// Variables for player and opponent states
extern Choice player_choice;
extern char opponent_choice;
extern Choice hold;
extern bool player_selection_made;
extern bool opponent_selection_made;

#endif 
