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

    int hex = 7 * 5; // 5 per hexagon given issues with 6 point homography, 7 sample hexagons
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
        else if (i >= 1 and i < 6) {
            path = "hex/desert_";
        }
        else if (i >= 6 and i < 11) {
            path = "hex/wheat_1_";
        }
        else if (i >= 11 and i < 16) {
            path = "hex/wheat_2_";
        }
        else if (i >= 16 and i < 21) {
            path = "hex/ore_";
        }
        else if (i >= 21 and i < 26) {
            path = "hex/sheep_";
        }
        else if (i >= 26 and i < 31) {
            path = "hex/wood_";
        }
        else if (i >= 31 and i < 36) {
            path = "hex/brick_";
        }
        else if (i >= 36 and i < 41) {
            path = "resource/wheat_1_";
        }
        else if (i >= 41 and i < 46) {
            path = "resource/wheat_2_";
        }
        else if (i >= 46 and i < 51) {
            path = "resource/ore_";
        }
        else if (i >= 51 and i < 56) {
            path = "resource/sheep_";
        }
        else if (i >= 56 and i < 61) {
            path = "resource/wood_";
        }
        else if (i >= 61 and i < 66) {
            path = "resource/brick_";
        }
        else if (i >= 66 and i < 71) {
            path = "dev/knight_";
        }
        else if (i >= 71 and i < 76) {
            path = "dev/victory_point_";
        }
        else if (i >= 76 and i < 81) {
            path = "dev/road_building_";
        }
        else if (i >= 81 and i < 86) {
            path = "dev/monopoly_";
        }
        else if (i >= 86 and i < 91) {
            path = "dev/year_of_plenty_";
        }
        else if (i == 91) {
            path = "pieces/red/road_";
        }
        else if (i == 92) {
            path = "pieces/red/settlement_";
        }
        else if (i == 93) {
            path = "pieces/red/city_";
        }
        else if (i == 94) {
            path = "pieces/blue/road_";
        }
        else if (i == 95) {
            path = "pieces/blue/settlement_";
        }
        else if (i == 96) {
            path = "pieces/blue/city_";
        }
        else if (i == 97) {
            path = "pieces/green/road_";
        }
        else if (i == 98) {
            path = "pieces/green/settlement_";
        }
        else if (i == 99) {
            path = "pieces/green/city_";
        }
        else if (i == 100) {
            path = "pieces/brown/road_";
        }
        else if (i == 101) {
            path = "pieces/brown/settlement_";
        }
        else if (i ==102) {
            path = "pieces/brown/city_";
        }
        std::string full_path = "res/markers/" + path + std::to_string(i) + ".png";
        cv::imwrite(full_path, marker_mat);
    }
    return 1;
}