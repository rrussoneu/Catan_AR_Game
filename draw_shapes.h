//
// Created by Raphael Russo on 4/17/24.
//

#ifndef CATAN_AR_GAME_DRAW_SHAPES_H
#define CATAN_AR_GAME_DRAW_SHAPES_H

#include <opencv2/opencv.hpp>

void solve_and_draw(std::vector<int> marker_ids, std::vector<cv::Vec3d> rvecs, std::vector<cv::Vec3d> tvecs, std::unordered_map<std::string, std::vector<cv::Point3f>> object_map, std::vector<double> distortion_coefficients, cv::Mat camera_matrix, cv::Mat output_frame);

/**
 * Generates a map of vectors of 3d points for drawing objects
 * @return the map
 */
std::unordered_map<std::string, std::vector<cv::Point3f>> generate_3d_points();

/**
 * Draws a brick from image points - just a rectangular box
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_brick(cv::Mat &frame, std::vector<cv::Point2f> img_pts);

/**
 * Draws a sheep from image points. There are some photos included in the report of the drawings/ planning for this
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_sheep(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws ore from image points. Ends up a pyramid
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_ore(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws wheat from image points. There are some photos included in the report of the drawings/ planning for this. Forms a trident like shape
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_wheat(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws wheat from image points
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_wood(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a sword to represent knight in AR
 * @param frame frame to draw on
 * @param img_points points to connect
 * @return on success
 */
int draw_knight(cv::Mat &frame, std::vector<cv::Point2f> img_points);

#endif //CATAN_AR_GAME_DRAW_SHAPES_H
