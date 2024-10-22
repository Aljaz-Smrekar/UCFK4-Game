/** @file   game_display.c
    @author L Sumnner, A Smrekar
    @date   12 October 2022
    @brief  Display letters on screen
    @note   Select chosen letter and determine if player has won.
*/

#include "tinygl.h"
#include "display.h"
#include "game_logic.h"

void display_choice(Choice choice)
// Displays the choice of the player
{
    char display_char = ' ';
    switch (choice) {
        case PAPER:
            display_char = 'P';
            break;
        case SCISSORS:
            display_char = 'S';
            break;
        case ROCK:
            display_char = 'R';
            break;
    }
    tinygl_text(&display_char);
}

void display_result(void)
// Once called displays the results of the game
{
    if (player_choice == hold) {
        return tinygl_text("DRAW");
    } else if ((player_choice == PAPER && hold == ROCK) ||
               (player_choice == SCISSORS && hold == PAPER) ||
               (player_choice == ROCK && hold == SCISSORS)) {
        return tinygl_text("WIN");
    } else {
        return tinygl_text("LOSE");
    }

}