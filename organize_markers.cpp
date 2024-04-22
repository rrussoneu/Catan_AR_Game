//
// Created by Raphael Russo on 4/21/24.
//

#include "organize_markers.h"

std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> make_maps() {
    std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps;


    // maps for the resource tiles
    std::unordered_map<int, std::vector<cv::Point2f>> desert_map;
    std::unordered_map<int, std::vector<cv::Point2f>> wheat_map_1;
    std::unordered_map<int, std::vector<cv::Point2f>> wheat_map_2;
    std::unordered_map<int, std::vector<cv::Point2f>> ore_map;
    std::unordered_map<int, std::vector<cv::Point2f>> wood_map;
    std::unordered_map<int, std::vector<cv::Point2f>> sheep_mat;
    std::unordered_map<int, std::vector<cv::Point2f>> brick_map;
    marker_maps["desert_map"] = desert_map;
    marker_maps["wheat_map_1"] = wheat_map_1;
    marker_maps["wheat_map_2"] = wheat_map_2;
    marker_maps["ore_map"] = ore_map;
    marker_maps["wood_map"] = wood_map;
    marker_maps["sheep_mat"] = sheep_mat;
    marker_maps["brick_map"] = brick_map;

    // resource card maps
    std::unordered_map<int, std::vector<cv::Point2f>> wheat_map_1_res;
    std::unordered_map<int, std::vector<cv::Point2f>> wheat_map_2_res;
    std::unordered_map<int, std::vector<cv::Point2f>> ore_map_res;
    std::unordered_map<int, std::vector<cv::Point2f>> wood_map_res;
    std::unordered_map<int, std::vector<cv::Point2f>> sheep_mat_res;
    std::unordered_map<int, std::vector<cv::Point2f>> brick_map_res;

    marker_maps["wheat_map_1_res"] = wheat_map_1_res;
    marker_maps["wheat_map_2_res"] = wheat_map_2_res;
    marker_maps["ore_map_res"] = ore_map_res;
    marker_maps["wood_map_res"] = wood_map_res;
    marker_maps["sheep_mat_res"] = sheep_mat_res;
    marker_maps["brick_map_res"] = brick_map_res;

    // dev card maps
    std::unordered_map<int, std::vector<cv::Point2f>> knight_map;
    std::unordered_map<int, std::vector<cv::Point2f>> vp_map;
    std::unordered_map<int, std::vector<cv::Point2f>> monopoly_map;
    std::unordered_map<int, std::vector<cv::Point2f>> road_building_map;
    std::unordered_map<int, std::vector<cv::Point2f>> yop_map;
    marker_maps["knight_map"] = knight_map;
    marker_maps["vp_map"] = vp_map;
    marker_maps["monopoly_map"] = monopoly_map;
    marker_maps["road_building_map"] = road_building_map;
    marker_maps["yop_map"] = yop_map;

    // piece maps
    std::unordered_map<int, std::vector<cv::Point2f>> robber_map;
    marker_maps["robber_map"] = robber_map;

    std::unordered_map<int, std::vector<cv::Point2f>> red_road_map;
    std::unordered_map<int, std::vector<cv::Point2f>> red_settlement_map;
    std::unordered_map<int, std::vector<cv::Point2f>> red_city_map;
    marker_maps["red_road_map"] = red_road_map;
    marker_maps["red_settlement_map"] = red_settlement_map;
    marker_maps["red_city_map"] = red_city_map;

    std::unordered_map<int, std::vector<cv::Point2f>> green_road_map;
    std::unordered_map<int, std::vector<cv::Point2f>> green_settlement_map;
    std::unordered_map<int, std::vector<cv::Point2f>> green_city_map;
    marker_maps["green_road_map"] = green_road_map;
    marker_maps["green_settlement_map"] = green_settlement_map;
    marker_maps["green_city_map"] = green_city_map;

    std::unordered_map<int, std::vector<cv::Point2f>> blue_road_map;
    std::unordered_map<int, std::vector<cv::Point2f>> blue_settlement_map;
    std::unordered_map<int, std::vector<cv::Point2f>> blue_city_map;
    marker_maps["blue_road_map"] = blue_road_map;
    marker_maps["blue_settlement_map"] = blue_settlement_map;
    marker_maps["blue_city_map"] = blue_city_map;

    std::unordered_map<int, std::vector<cv::Point2f>> brown_road_map;
    std::unordered_map<int, std::vector<cv::Point2f>> brown_settlement_map;
    std::unordered_map<int, std::vector<cv::Point2f>> brown_city_map;
    marker_maps["brown_road_map"] = brown_road_map;
    marker_maps["brown_settlement_map"] = brown_settlement_map;
    marker_maps["brown_city_map"] = brown_city_map;



    return marker_maps;
}

std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> map_markers(std::vector<int> marker_ids, std::vector<std::vector<cv::Point2f>> marker_corners, std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps) {
    for (int i = 0; i < marker_ids.size(); i++) { // group each marker into its proper map of marker and coordinate based on game pieces
        if (marker_ids.at(i) == 0) {
            marker_maps["robber_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        // hexes
        if (marker_ids.at(i) >= 1 && marker_ids.at(i) < 6) {
            marker_maps["desert_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 6 && marker_ids.at(i) < 11) {
            marker_maps["wheat_map_1"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 11 && marker_ids.at(i) < 16) {
            marker_maps["wheat_map_2"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 16 && marker_ids.at(i) < 21) {
            marker_maps["ore_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 21 && marker_ids.at(i) < 26) {
            marker_maps["sheep_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 26 && marker_ids.at(i) < 31) {
            marker_maps["wood_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 31 && marker_ids.at(i) < 36) {
            marker_maps["brick_map"][marker_ids.at(i)] = marker_corners.at(i);
        }

        // res cards
        if (marker_ids.at(i) >= 36 && marker_ids.at(i) < 41) {
            marker_maps["wheat_map_1_res"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 41 && marker_ids.at(i) < 46) {
            marker_maps["wheat_map_2_res"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 46 && marker_ids.at(i) < 51) {
            marker_maps["ore_map_res"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 51 && marker_ids.at(i) < 16) {
            marker_maps["sheep_map_res"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 56 && marker_ids.at(i) < 61) {
            marker_maps["wood_map_res"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 61 && marker_ids.at(i) < 66) {
            marker_maps["brick_map_res"][marker_ids.at(i)] = marker_corners.at(i);
        }

        // dev cards
        if (marker_ids.at(i) >= 66 && marker_ids.at(i) < 71) {
            marker_maps["knight_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 71 && marker_ids.at(i) < 76) {
            marker_maps["vp_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 76 && marker_ids.at(i) < 81) {
            marker_maps["road_building_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 81 && marker_ids.at(i) < 86) {
            marker_maps["monopoly_map"][marker_ids.at(i)] = marker_corners.at(i);
        }
        if (marker_ids.at(i) >= 86 && marker_ids.at(i) < 91) {
            marker_maps["yop_map"][marker_ids.at(i)] = marker_corners.at(i);
        }

        // other pieces
        if (marker_ids.at(i) == 91) {
            marker_maps["red_road_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 92) {
            marker_maps["red_settlement_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 93) {
            marker_maps["red_city_map"][marker_ids.at(i)] == marker_corners.at(i);
        }

        if (marker_ids.at(i) == 94) {
            marker_maps["blue_road_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 95) {
            marker_maps["blue_settlement_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 96) {
            marker_maps["blue_city_map"][marker_ids.at(i)] == marker_corners.at(i);
        }

        if (marker_ids.at(i) == 97) {
            marker_maps["green_road_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 98) {
            marker_maps["green_settlement_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 99) {
            marker_maps["green_city_map"][marker_ids.at(i)] == marker_corners.at(i);
        }

        if (marker_ids.at(i) == 100) {
            marker_maps["brown_road_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 101) {
            marker_maps["brown_settlement_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
        if (marker_ids.at(i) == 102) {
            marker_maps["brown_city_map"][marker_ids.at(i)] == marker_corners.at(i);
        }
    }

    return marker_maps;
}

