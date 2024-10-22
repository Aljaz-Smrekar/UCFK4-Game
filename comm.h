/** @file   comm.h
    @author L Sumnner, A Smrekar
    @date   18 October 2022
    @brief  Communication between boards
    @note   Sends and recieves choices from both player and opponent.
*/

#ifndef COMM_H
#define COMM_H

// Function to send the player's choice to the opponent using IR communication
void send_choice(void);

// Function to receive the opponent's choice via IR communication
void receive_choice(void);

#endif 
