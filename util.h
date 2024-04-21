//
// Created by Raphael Russo on 4/17/24.
//

#ifndef CATAN_AR_GAME_UTIL_H
#define CATAN_AR_GAME_UTIL_H

#include <vector>
#include <opencv2/opencv.hpp>

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

/**
 * Gets points for homography calculation for a vector of cv mats
 * @param mats the mats
 * @return the newly created vector
 */
std::vector<std::vector<cv::Point2f>> get_homography_points(std::vector<cv::Mat> mats);

void compute_homography(int aruco_id, std::unordered_map<int, std::vector<cv::Point2f>> marker_map, std::vector<cv::Point2f> img_pts, cv::Mat hex_mat, cv::Mat frame, cv::Mat out);

#endif //CATAN_AR_GAME_UTIL_H
