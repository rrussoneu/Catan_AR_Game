//
// Created by Raphael Russo on 4/17/24.
//

#include <iostream>
#include "util.h"


int print_turn(std::vector<int> scores, std::vector<int> roads, int dice_roll) {
    std::cout << "Blue Points: " << scores.at(0) << "\n Blue roads: \n" << roads.at(0)
            << "Green Points: " << scores.at(1) << "\n Green roads: \n" << roads.at(1)
            << "Red Points: " << scores.at(2) << "\n Red roads: \n" << roads.at(2)
            << "Brown Points: " << scores.at(3) << "\n Brown roads: " << roads.at(3) << std::endl;
    std::cout << "Dice roll: " << dice_roll << std::endl;
}


int roll_dice() {
    // Two rolls out of 6 to simulate dice
    int roll_one = rand() % 6 + 1;
    int roll_two = rand() % 6 + 1;
    return roll_one + roll_two;
}