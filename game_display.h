/** @file   game_display.h
    @author L Sumnner, A Smrekar
    @date   12 October 2022
    @brief  Display letters on screen
    @note   Select chosen letter and determine if player has won.
*/

#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include "game_logic.h"

// Function to display the player's current selection (P, S, R)
void display_choice(Choice choice);

// Function to display the result (WIN/LOSE/DRAW)
void display_result(void);

#endif
