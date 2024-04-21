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
        vec.push_back(cv::Point2f(0.00,0.00));
        vec.push_back(cv::Point2f(mats.at(i).cols - 1.00,0.00));
        vec.push_back(cv::Point2f(mats.at(i).cols - 1.00,mats.at(i).rows - 1.00));
        vec.push_back(cv::Point2f(0.00,mats.at(i).rows - 1.00));
        point_vector.push_back(vec);
    }

    return point_vector;
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


void handle_homography(std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps, std::vector<std::vector<cv::Point2f>> homography_points, std::vector<cv::Mat> mats, cv::Mat frame, cv::Mat out) {
    for (int i = 1; i < 32; i++) { // can skip through a bunch of markers and iterate by 5
        if (i % 5 != 5 && i != 1) { // skip if not 1, 6, etc
            continue;
        } else {
            switch (i) {
                // hex homography
                // desert, wheat ore, wood, sheep, brick
                case 1:
                    compute_homography(1, marker_maps["desert_map"], homography_points.at(0), mats.at(0), frame, out);
                case 6:
                    compute_homography(6, marker_maps["wheat_map_1"], homography_points.at(1), mats.at(0), frame, out);
                case 11:
                    compute_homography(11, marker_maps["wheat_map_2"], homography_points.at(1), mats.at(1), frame, out);
                case 16:
                    compute_homography(16, marker_maps["ore_map"], homography_points.at(2), mats.at(2), frame, out);
                case 21:
                    compute_homography(21, marker_maps["sheep_mat"], homography_points.at(4), mats.at(4), frame, out);
                case 26:
                    compute_homography(26, marker_maps["wood_map"], homography_points.at(3), mats.at(3), frame, out);
                case 31:
                    compute_homography(31, marker_maps["brick_map"], homography_points.at(5), mats.at(5), frame, out);
            }
        }
    }
    for (int i = 36; i < 62; i++) { // same as above for resource cards
        if (i % 5 != 5) { // 36, 41, etc. else skip iteration
            continue;
        } else {
            switch (i) {
                // res card homography

                case 36:
                    compute_homography(36, marker_maps["wheat_map_1_res"], homography_points.at(6), mats.at(6), frame, out);
                case 41:
                    compute_homography(41, marker_maps["wheat_map_2_res"], homography_points.at(6), mats.at(6), frame, out);
                case 46:
                    compute_homography(46, marker_maps["ore_map_res"], homography_points.at(7), mats.at(7), frame, out);
                case 51:
                    compute_homography(51, marker_maps["sheep_mat_res"], homography_points.at(9), mats.at(9), frame, out);
                case 56:
                    compute_homography(56, marker_maps["wood_map_res"], homography_points.at(8), mats.at(8), frame, out);
                case 61:
                    compute_homography(61, marker_maps["brick_map_res"], homography_points.at(10), mats.at(10), frame, out);
            }
        }
    }
    for (int i = 66; i < 91; i++) {
        if (i % 5 != 5) {
            continue;
        } else {
            switch (i) {
                // dev card homography

                case 66:
                    compute_homography(66, marker_maps["knight_map"], homography_points.at(12), mats.at(12), frame, out);
                case 71:
                    compute_homography(71, marker_maps["vp_map"], homography_points.at(11), mats.at(11), frame, out);
                case 81:
                    compute_homography(81, marker_maps["monopoly_map"], homography_points.at(13), mats.at(13), frame, out);
                case 76:
                    compute_homography(76, marker_maps["road_building_map"], homography_points.at(15), mats.at(15), frame, out);
                case 86:
                    compute_homography(86, marker_maps["yop_map"], homography_points.at(14), mats.at(14), frame, out);

            }
        }
    }
}


