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
    return marker_maps;
}
