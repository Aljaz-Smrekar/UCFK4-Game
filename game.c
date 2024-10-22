
/** @file   game.c
    @author L Sumnner, A Smrekar
    @date   18 October 2022
    @brief  initilises and runs the game
    @note   Runs the logic of the game
*/

#include "system.h"
#include "navswitch.h"
#include "ledmat.h"
#include "pacer.h"
#include "tinygl.h"
#include "ir_uart.h"
#include "display.h"
#include "game_display.h"
#include "input.h"
#include "comm.h"
#include "game_logic.h"
#include "../fonts/font5x7_1.h"

#define PACER_RATE 500
#define MESSAGE_RATE 100

int main(void)
{
    // Initilises the components / APIs
    system_init();
    navswitch_init();
    ledmat_init();
    ir_uart_init(); 

    pacer_init(PACER_RATE);
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);

    while (1)
    {
        tinygl_update();
        navswitch_update();

        if (!player_selection_made) {
            // Update player's choice and display it
            update_choice();
            display_choice(player_choice);

            // If the player presses down, they confirm their choice
            if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
                send_choice();
                player_selection_made = true;
            }
        }
        if (!opponent_selection_made) {
            // Wait for the opponent's choice
            receive_choice();
        }

        if (player_selection_made && !opponent_selection_made) {
            // Displays "?" if the player has made a selection and awaiting for opponents selection
            tinygl_text("?");
        }

        if (opponent_selection_made && player_selection_made) {
            // Displays the results once both the player and opponent have selected and locked in their choices
            display_result();
        }

        // Updates the display
        tinygl_update();
    }
}
