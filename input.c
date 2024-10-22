/** @file   input.c
    @author L Sumnner, A Smrekar
    @date   12 October 2022
    @brief  Navswitch input contorl
    @note   Player selects hand to play based on scrolling with the navswitch
*/

#include "navswitch.h"
#include "input.h"

void update_choice(void)
// Logic for selecting the hand
{
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        if (player_choice == PAPER) {
            player_choice = SCISSORS;
        } else if (player_choice == SCISSORS) {
            player_choice = ROCK;
        } else {
            player_choice = PAPER;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        if (player_choice == PAPER) {
            player_choice = ROCK;
        } else if (player_choice == ROCK) {
            player_choice = SCISSORS;
        } else {
            player_choice = PAPER;
        }
    }
}
