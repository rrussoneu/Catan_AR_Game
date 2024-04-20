//
// Created by Raphael Russo on 4/19/24.
//
#include <opencv2/objdetect/aruco_detector.hpp>
#include <opencv2/opencv.hpp>

int main() {
    /*
     * change values based on how many cards you are making, but for a full game with 20 of each resource card
     * you need approx 855 markers which fits within the aruco dict
     * */

    int hex = 7 * 7; // 7 per hexagon, 7 sample hexagons
    int rob = 1; // one for the robber piece
    int pieces = 4 * 3; // 4 colors and 1 sample road, 1 sample settlement, one city per color
    int res = 6 * 5; // 6 sample resource cards, 5 resource card
    int dev = 5 * 5; // 5 sample dev cards, 5 per card
    int total_markers = rob + hex + pieces + res + dev;

    /*
     *
     * robber = marker 0
     * wheat hex = markers 1,2,3,4,5,6 and 7 with seven as marker for the object and the rest for homography
     * wheat hex 2 = markers 8, 9, 10, 11, 12, 13, and 14 same as above
     * ore hex = 15, 16, ... and so on for the markers until the last is 43 - 49
     * wheat resource = markers 50, 51, 52, 53, and 54 with 55 as marker for object
     * wheat resource 2 = + 5 to all previous and so on
     * dev cards start at 85 and follow same pattern
     * pieces start at 110
     */

    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_1000);
    for (int i = 0; i < total_markers; i++) {
        cv::Mat marker_mat;
        cv::aruco::generateImageMarker(dictionary, i, 100, marker_mat, 1);
        std::string path;

        // determine the name of the file based on the marker id
        if (i == 0) {
            path = "pieces/robber_";
        }
        else if (i >= 1 and i < 8) {
            path = "hex/desert_";
        }
        else if (i >= 8 and i < 15) {
            path = "hex/wheat_1_";
        }
        else if (i >= 15 and i < 22) {
            path = "hex/wheat_2_";
        }
        else if (i >= 22 and i < 29) {
            path = "hex/ore_";
        }
        else if (i >= 29 and i < 36) {
            path = "hex/sheep_";
        }
        else if (i >= 36 and i < 43) {
            path = "hex/wood_";
        }
        else if (i >= 43 and i < 50) {
            path = "hex/brick_";
        }
        else if (i >= 50 and i < 55) {
            path = "resource/wheat_1_";
        }
        else if (i >= 55 and i < 60) {
            path = "resource/wheat_2_";
        }
        else if (i >= 60 and i < 65) {
            path = "resource/ore_";
        }
        else if (i >= 65 and i < 70) {
            path = "resource/sheep_";
        }
        else if (i >= 70 and i < 75) {
            path = "resource/wood_";
        }
        else if (i >= 75 and i < 80) {
            path = "resource/brick_";
        }
        else if (i >= 80 and i < 85) {
            path = "dev/knight_";
        }
        else if (i >= 85 and i < 90) {
            path = "dev/victory_point_";
        }
        else if (i >= 90 and i < 95) {
            path = "dev/road_building_";
        }
        else if (i >= 95 and i < 100) {
            path = "dev/monopoly_";
        }
        else if (i >= 100 and i < 105) {
            path = "dev/year_of_plenty_";
        }
        else if (i == 105) {
            path = "pieces/red/road_";
        }
        else if (i == 106) {
            path = "pieces/red/settlement_";
        }
        else if (i == 107) {
            path = "pieces/red/city_";
        }
        else if (i == 108) {
            path = "pieces/blue/road_";
        }
        else if (i == 109) {
            path = "pieces/blue/settlement_";
        }
        else if (i == 110) {
            path = "pieces/blue/city_";
        }
        else if (i == 111) {
            path = "pieces/green/road_";
        }
        else if (i == 112) {
            path = "pieces/green/settlement_";
        }
        else if (i == 113) {
            path = "pieces/green/city_";
        }
        else if (i == 114) {
            path = "pieces/brown/road_";
        }
        else if (i == 115) {
            path = "pieces/brown/settlement_";
        }
        else if (i ==116) {
            path = "pieces/brown/city_";
        }
        std::string full_path = "res/markers/" + path + std::to_string(i) + ".png";
        cv::imwrite(full_path, marker_mat);
    }
    return 1;
}