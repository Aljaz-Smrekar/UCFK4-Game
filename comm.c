/** @file   comm.c
    @author L Sumnner, A Smrekar
    @date   14 October 2022
    @brief  Communication between boards
    @note   Sends and recieves choices from player and opponent.
*/

#include "ir_uart.h"
#include "game_logic.h"

void send_choice(void)
// Sends the players choice to the opponent
{
    if (player_choice == ROCK) {
        ir_uart_putc('R');
    } else if (player_choice == SCISSORS) {
        ir_uart_putc('S');
    } else {
        ir_uart_putc('P');
    }
}

void receive_choice(void)
// Recieves the choice of the opponent
{
    if (ir_uart_read_ready_p()) {
        opponent_selection_made = true;
        opponent_choice = ir_uart_getc();
        if (opponent_choice == 82) {
            hold = ROCK;
        } else if (opponent_choice == 83) {
            hold = SCISSORS;
        } else {
            hold = PAPER;
        }
    }
}
