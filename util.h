//
// Created by Raphael Russo on 4/17/24.
//

#ifndef CATAN_AR_GAME_UTIL_H
#define CATAN_AR_GAME_UTIL_H

#include <vector>

/**
 * Prints an update of the game scores, roads, and a random number for a dice roll to begin a new turn
 * @param scores Blue, Green, Red, Brown scores in that order
 * @param roads Blue, Green, Red, Brown number of roads in that order
 * @param dice_roll The number rolled
 * @return on success
 */
int print_turn(std::vector<int> scores, std::vector<int> roads, int dice_roll);

/**
 * Gets a dice roll result
 * @return
 */
int roll_dice();

#endif //CATAN_AR_GAME_UTIL_H
