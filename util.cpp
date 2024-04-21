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

std::vector<std::vector<cv::Point2f>> get_homography_points(std::vector<cv::Mat> mats) {
    std::vector<std::vector<cv::Point2f>> point_vector;
    for (int i = 0; i < mats.size(); i++) {
        std::vector<cv::Point2f> vec;

    }
}

void compute_homography(int aruco_id, std::unordered_map<int, std::vector<cv::Point2f>> marker_map, std::vector<cv::Point2f> img_pts, cv::Mat hex_mat, cv::Mat frame, cv::Mat out) {
    if (marker_map.count(aruco_id) && marker_map.count(aruco_id + 1) && marker_map.count(aruco_id + 2) && marker_map.count(aruco_id) + 3) { // check all needed markers are present
        std::vector<cv::Point2f> frame_corners; // corners of points to make a box for image
        frame_corners.push_back(marker_map.at(aruco_id)[0]);
        frame_corners.push_back(marker_map.at(aruco_id + 1)[1]);
        frame_corners.push_back(marker_map.at(aruco_id + 3)[2]);
        frame_corners.push_back(marker_map.at(aruco_id + 2)[3]);

        // get warped version of card image to match the board
        cv::Mat homography = cv::findHomography(img_pts, frame_corners); // uses entire card image because the image is only of the card
        cv::Mat warped;
        cv::warpPerspective(hex_mat, warped, homography, frame.size());

        // need a mask to only copy over the relative pixels to the final output
        cv::Mat mask = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC1);
        std::vector<cv::Point> converted; // need to convert to avoid error in fillConvexPoly requiring CV_32S
        cv::Mat(frame_corners).convertTo(converted, CV_32S);
        cv::fillConvexPoly(mask, converted, cv::Scalar(255, 255, 255));

        warped.copyTo(out, mask);
    }
}

