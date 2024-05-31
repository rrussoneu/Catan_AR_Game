//
// Utility functions for general game purposes and homography
//

#ifndef CATAN_AR_GAME_UTIL_H
#define CATAN_AR_GAME_UTIL_H

#include <vector>
#include <opencv2/opencv.hpp>

/**
 * Gets a dice roll result
 * @return the roll
 */
int roll_dice();

/**
 * Handles different cases where homography is needed to display an image
 * @param marker_maps map of aruco markers
 * @param homography_points mat points for calculation
 * @param mats mats to use
 * @param frame camera frame as input
 * @param out output frame to draw on
 */
void handle_homography(std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps, std::vector<std::vector<cv::Point2f>> homography_points, std::vector<cv::Mat> mats, cv::Mat frame, cv::Mat out);

/**
 * Gets points for homography calculation for a vector of cv mats
 * @param mats the mats
 * @return the newly created vector
 */
std::vector<std::vector<cv::Point2f>> get_homography_points(std::vector<cv::Mat> mats);

/**
 * Uses markers and images to compute homography and overlay a game's component onto the markers in the frame
 * @param aruco_id id of aruco marker serving as top left
 * @param marker_map markers' points
 * @param img_pts points in image to use for planar homography
 * @param hex_mat mat of image to overlay
 * @param frame input frame
 * @param out output frame
 */
void compute_homography(int aruco_id, std::unordered_map<int, std::vector<cv::Point2f>> marker_map, std::vector<cv::Point2f> img_pts, cv::Mat hex_mat, cv::Mat frame, cv::Mat out);

/**
 * Reads image files for game
 * @return vector of mats with the image data
 */
std::vector<cv::Mat> get_images();

#endif //CATAN_AR_GAME_UTIL_H
