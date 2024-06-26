//
// Utility functions for aruco marker organization
//

#ifndef CATAN_AR_GAME_ORGANIZE_MARKERS_H
#define CATAN_AR_GAME_ORGANIZE_MARKERS_H

#include <unordered_map>
#include <opencv2/core/types.hpp>

/**
 * Makes a series of maps for aruco marker ids
 * @return a hashmap of hashmaps for the ids
 */
std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> make_maps();

/**
 * Puts aruco marker ids into the appropriate maps
 * @param marker_ids aruco marker ids
 * @param maps maps for the markers
 */
std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> map_markers(std::vector<int> marker_ids, std::vector<std::vector<cv::Point2f>> marker_corners, std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> maps);


#endif //CATAN_AR_GAME_ORGANIZE_MARKERS_H
