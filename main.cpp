#include <iostream>

#include "util.h"
#include <opencv2/opencv.hpp>
#include "draw_shapes.h"
#include "organize_markers.h"

int main() {

    // get the calibration settings
    cv::Mat cameraMatrix = cv::Mat(3, 3, CV_64FC1);
    std::vector<double> distCoeffs;
    cv::FileStorage fs("camera_calibration_setting.xml", cv::FileStorage::READ);
    if (!fs.isOpened()) {
        return -1;
    }
    fs["camera_matrix"] >> cameraMatrix;
    fs["distortion_coefficients"] >> distCoeffs;
    fs.release();

    std::unordered_map<std::string, std::vector<cv::Point3f>> object_map = generate_3d_points(); // generate 3D object representations

    /*
    // Stored in order Blue, Green, Red, Brown
    std::vector<int> player_scores;
    std::vector<int> player_roads;

    std::vector<int> num_rolls; // keep track of number of time each roll occurs for stats

    for (int i = 0; i < 4; i++) {
        player_scores.push_back(0);
        player_roads.push_back(0);
    }

    for (int i = 0; i < 11; i++) {
        num_rolls.push_back(0);
    }
     */


    cv::VideoCapture *videoCapture; // capture for webcam

    videoCapture = new cv::VideoCapture(0);
    if (!videoCapture->isOpened()) {
        std::cout << "Unable to open video device";
        return -1;
    }

    cv::Size refS( (int) videoCapture->get(cv::CAP_PROP_FRAME_WIDTH),
                   (int) videoCapture->get(cv::CAP_PROP_FRAME_HEIGHT)); // set size for capture

    std::cout << "Expected Size: " << refS.width << refS.height << std::endl;
    cv::namedWindow("Video Window", 1); // window for viewing webcam
    cv::Mat frame; // frame to receive from camera

    // init necessary open cv objects for marker detection
    cv::aruco::DetectorParameters detector_params = cv::aruco::DetectorParameters();
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_1000);
    cv::aruco::ArucoDetector detector(dictionary, detector_params);

    // read appropriate images, could swap them out for others if better looking ones are available
    std::vector<cv::Mat> mats = get_images();



    std::vector<std::vector<cv::Point2f>> homography_points = get_homography_points(mats);
    std::vector<cv::Point2f> brick_hex_pts = homography_points.at(5);

    /*
    Row: 5Col: 175
    Row: 100 Col: 5
    Row: 100 Col: 350
    Row: 280 Col: 5
    Row: 280Col: 350
    Row: 365 Col: 175
     */
    //brick_hex_pts.push_back(cv::Point2f(5.0, 175.0));
    //brick_hex_pts.push_back(cv::Point2f(100.0, 5.0));
    //brick_hex_pts.push_back(cv::Point2f(100.0, 350.0));
    //brick_hex_pts.push_back(cv::Point2f(280.0, 5.0));
    //brick_hex_pts.push_back(cv::Point2f(280.0, 350.0));
    //brick_hex_pts.push_back(cv::Point2f(365.0, 175.0));

    //brick_hex_pts.push_back(cv::Point2f(175.0, 5.0));
    //brick_hex_pts.push_back(cv::Point2f(5.0, 100.0));
    //brick_hex_pts.push_back(cv::Point2f(350.0, 100.0));
    //brick_hex_pts.push_back(cv::Point2f(5.0, 280.0));
    //brick_hex_pts.push_back(cv::Point2f(350.0, 280.0));
    //brick_hex_pts.push_back(cv::Point2f(175.0, 365.0));

    //brick_hex_pts.push_back(cv::Point2f(0.00,0));
    //brick_hex_pts.push_back(cv::Point2f(brick_hex_mat.cols - 1.00,0.00));
    //brick_hex_pts.push_back(cv::Point2f(brick_hex_mat.cols - 1.00,brick_hex_mat.rows - 1.00));
    //brick_hex_pts.push_back(cv::Point2f(0.00,brick_hex_mat.rows - 1.00));




    for (;;) {

        *videoCapture >> frame;



        if (frame.empty()) {
            std::cout << "Frame is empty" << std::endl;
            break;
        }

        cv::Mat out = frame.clone(); // output image



        // store marker data
        std::vector<int> marker_ids;
        std::vector<std::vector<cv::Point2f>> marker_corners;
        std::vector<std::vector<cv::Point2f>> rejected_candidates;
        cv::Mat curr_corners;
        cv::Mat curr_ids;
        std::vector<cv::Point3f> curr_obj_points;
        std::vector<cv::Point2f> curr_img_points;

        //std::vector<int> brick_ids;
        //brick_ids.push_back(43);
        //brick_ids.push_back(44);
        //brick_ids.push_back(45);
        //brick_ids.push_back(46);
        //brick_ids.push_back(47);
        //brick_ids.push_back(48);
        //brick_ids.push_back(49);

        std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps = make_maps();
        std::cout << "post map" << std::endl;
        int size_check = marker_maps.size();
        /*
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
        */
        detector.detectMarkers(frame, marker_corners, marker_ids, rejected_candidates);



        // visualize for testing
        if (!marker_ids.empty() && !marker_corners.empty()) {
            //cv::aruco::drawDetectedMarkers(out, marker_corners, marker_ids);
            //std::vector<int> brick_check;

            if (size_check == 31) {
                marker_maps = map_markers(marker_ids, marker_corners, marker_maps); // group markers and points together
                std::cout << "post mapping" << std::endl;

                // coords
                cv::Mat obj_points(4, 1, CV_32FC3);
                float marker_length = .027;
                obj_points.ptr<cv::Vec3f>(0)[0] = cv::Vec3f(-marker_length/2.f, marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[1] = cv::Vec3f(marker_length/2.f, marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[2] = cv::Vec3f(marker_length/2.f, -marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[3] = cv::Vec3f(-marker_length/2.f, -marker_length/2.f, 0);


                std::vector<cv::Vec3d> rvecs(marker_corners.size()), tvecs(marker_corners.size());

                for (int i = 0; i < marker_corners.size(); i++) {
                    solvePnP(obj_points, marker_corners.at(i), cameraMatrix, distCoeffs, rvecs.at(i), tvecs.at(i), cv::SOLVEPNP_ITERATIVE);
                    cv::drawFrameAxes(out, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], marker_length, 2);


                }

                handle_homography(marker_maps, homography_points, mats, frame, out);
                std::cout << "post homography" << std::endl;

                solve_and_draw(marker_ids, rvecs, tvecs, object_map, distCoeffs, cameraMatrix, out);

            }

            /*
            for (int i = 0; i < marker_ids.size(); i++) {
                if (marker_ids.at(i) >= 43 && marker_ids.at(i) < 49) {
                    //brick_check.push_back(marker_ids.at(i));
                    marker_maps["brick_map"][marker_ids.at(i)] = marker_corners.at(i);
                }
            }
             */



            // do homography first and draw on top of the resulting frame for the shapes
            /*
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
                        // FIX HOMOGRAPHY POINTS

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
            for (int i = 66; i < 91; i++) { // same as above for resource cards
                if (i % 5 != 5) { // 36, 41, etc. else skip iteration
                    continue;
                } else {
                    switch (i) {
                        // res card homography

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
            */

            //for (int j = 0; j < marker_ids.size(); j++) {


                /*
                if (marker_ids.at(j) == 44) {
                    if (brick_check.size() == 6) {
                        std::vector<cv::Point2f> frame_corners; // 0, 3, 23, 20, corners of points on board to make a box for image
                        //frame_corners.push_back(brick_map.at(43)[0]);
                        frame_corners.push_back(brick_map.at(44)[0]);
                        frame_corners.push_back(brick_map.at(45)[1]);
                        frame_corners.push_back(brick_map.at(47)[2]);
                        frame_corners.push_back(brick_map.at(46)[3]);

                        //frame_corners.push_back(brick_map.at(48)[0]);

                        // get warped version of card image to match the board
                        cv::Mat homography = cv::findHomography(brick_hex_pts, frame_corners); // uses entire card image because the image is only of the card
                        cv::Mat warped;
                        cv::warpPerspective(brick_hex_mat, warped, homography, frame.size());

                        // need a mask to only copy over the relative pixels to the final output
                        cv::Mat mask = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC1);
                        std::vector<cv::Point> converted; // need to convert to avoid error in fillConvexPoly requiring CV_32S
                        cv::Mat(frame_corners).convertTo(converted, CV_32S);
                        cv::fillConvexPoly(mask, converted, cv::Scalar(255, 255, 255));

                        warped.copyTo(out, mask);
                    }
                }
                 */

            //}



            /*
            for (int j = 0; j < marker_ids.size(); j++) {
                if (marker_ids.at(j) == 49) {
                    std::vector<cv::Point2f> img_points; // 2D calculated points to draw
                    cv::projectPoints(knight_points, rvecs.at(j), tvecs.at(j), cameraMatrix, distCoeffs, img_points);
                    draw_knight(out, img_points);
                }
            }
             */

        }

        // various key presses below
        char key = cv::waitKey(10);

        if (key == 'q') {
            break;
        }

        if (key == 'r') {
            int roll = roll_dice();
            //num_rolls.at(roll - 2) += 1;
            //print_turn(player_scores, player_roads, roll);
        }


        cv::imshow("Camera", out); // show frame output


    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
