//
// Utility functions related to 3D models and their rendering
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
 * Draws a sheep from image points
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
 * Draws wheat from image points
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_wheat(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a sword to represent knight in AR
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_robber(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a tree to represent wood tile in AR
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_wood_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a mountain shape to represent ore tile
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_ore_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a brick shape for brick tile
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_brick_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws year of plenty plus symbol
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_yop(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a dollar sign to represent monopoly card
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_monopoly(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a shovel to represent road building
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_road_building(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a road
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_road(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color);

/**
 * Draws a chalice to represent victory point
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_vp(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a settlement
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_settlement(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color);

/**
 * Draws a city
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_city(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color);

/**
 * Draws a log for wood resource card
 * @param frame frame to draw on
 * @param img_points points to connecct
 */
void draw_wood_res(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a small brick for brick resource
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_brick_res(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws various shapes based on marker poses and id's
 * @param marker_ids the marker ids
 * @param rvecs rotation vectors for markers
 * @param tvecs translation vectors for markers
 * @param object_map map of object 3D points
 * @param distortion_coefficients lens distortion coefficients
 * @param camera_matrix intrinsic camera matrix
 * @param output_frame frame to output
 */
void solve_and_draw(std::vector<int> marker_ids, std::vector<cv::Vec3d> rvecs, std::vector<cv::Vec3d> tvecs, std::unordered_map<std::string, std::vector<cv::Point3f>> object_map, std::vector<double> distortion_coefficients, cv::Mat camera_matrix, cv::Mat output_frame);
#endif //CATAN_AR_GAME_DRAW_SHAPES_H
