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


    std::vector<cv::Point3f> sheep_points = {cv::Point3f(0.0,0.0,0.0), cv::Point3f(0.04,0.0,0.0), cv::Point3f(0.04,0.04,0.0), cv::Point3f(0.0,0.04,0.0), cv::Point3f(0.12,0.0,0.0), cv::Point3f(0.16,0.0,0.0), cv::Point3f(0.16,0.04,0.0), cv::Point3f(0.12,0.04,0.0), // sheep's anatomical bottom left
                                             cv::Point3f(0.12,0.08,0.0), cv::Point3f(0.16,0.08,0.0), cv::Point3f(0.16,0.12,0.0), cv::Point3f(0.12,0.12,0.0), cv::Point3f(0.0,0.08,0.0), cv::Point3f(0.04,0.08,0.0), cv::Point3f(0.04,0.12,0.0), cv::Point3f(0.00,0.12,0.0), // sheep's anatomical bottom right
                                             cv::Point3f(0.0,0.0,0.06), cv::Point3f(0.04,0.0,0.06), cv::Point3f(0.04,0.04,0.06), cv::Point3f(0.0,0.04,0.06), cv::Point3f(0.12,0.0,0.06), cv::Point3f(0.16,0.0,0.06), cv::Point3f(0.16,0.04,0.06), cv::Point3f(0.12,0.04,0.06), // sheep's anatomical middle layer left
                                             cv::Point3f(0.12,0.08,0.06), cv::Point3f(0.16,0.08,0.06), cv::Point3f(0.16,0.12,0.06), cv::Point3f(0.12,0.12,0.06), cv::Point3f(0.0,0.08,0.06), cv::Point3f(0.04,0.08,0.06), cv::Point3f(0.04,0.12,0.06), cv::Point3f(0.00,0.12,0.06), // sheep's anatomical middle layer right
            // top square of sheep body
                                             cv::Point3f(0.0,0.0,0.12), cv::Point3f(0.16,0.0,0.12), cv::Point3f(0.16,0.12,0.12), cv::Point3f(0.0,0.12,0.12),
            // head bottom
                                             cv::Point3f(.16,.04,.06), cv::Point3f(.2,.04,.06), cv::Point3f(.2,.08,.06), cv::Point3f(.16,.08,.06),
            // head top
                                             cv::Point3f(.16,.04,.12), cv::Point3f(.2,.04,.12), cv::Point3f(.2,.08,.12), cv::Point3f(.16,.08,.12),

    };

    float w = 0.04; // the sword is built using multiples of .04 for distances between points
    std::vector<cv::Point3f> knight_points = {
            cv::Point3f(1.5 * w, 0.5 * w, 0.0 * w), // the point at the bottom

            // middle pieces
            cv::Point3f(1.0 * w, 0.0 * w, 0.5 * w), cv::Point3f(2.0 * w, 0.0 * w, 0.5 * w), cv::Point3f(1.0 * w, 1.0 * w, 0.5 * w), cv::Point3f(2.0 * w, 1.0 * w, 0.5 * w), // first square layer, connects to bottom
            cv::Point3f(1.0 * w, 0.0 * w, 2.0 * w), cv::Point3f(2.0 * w, 0.0 * w, 2.0 * w), cv::Point3f(1.0 * w, 1.0 * w, 2.0 * w), cv::Point3f(2.0 * w, 1.0 * w, 2.0 * w), // end of sword part of sword, middle
            cv::Point3f(1.0 * w, 0.0 * w, 3.0 * w), cv::Point3f(2.0 * w, 0.0 * w, 3.0 * w), cv::Point3f(1.0 * w, 1.0 * w, 3.0 * w), cv::Point3f(2.0 * w, 1.0 * w, 3.0 * w), // top middle of handle guard piece
            cv::Point3f(1.0 * w, 0.0 * w, 3.5 * w), cv::Point3f(2.0 * w, 0.0 * w, 3.5 * w), cv::Point3f(1.0 * w, 1.0 * w, 3.5 * w), cv::Point3f(2.0 * w, 1.0 * w, 3.5 * w), // handle top, middle piece

            // side pieces
            cv::Point3f(0.0 * w, 0.0 * w, 2.0 * w), cv::Point3f(3.0 * w, 0.0 * w, 2.0 * w), cv::Point3f(0.0 * w, 1.0 * w, 2.0 * w), cv::Point3f(3.0 * w, 1.0 * w, 2.0 * w), // corners of beginning of handle
            cv::Point3f(0.0 * w, 0.0 * w, 3.0 * w), cv::Point3f(3.0 * w, 0.0 * w, 3.0 * w), cv::Point3f(0.0 * w, 1.0 * w, 3.0 * w), cv::Point3f(3.0 * w, 1.0 * w, 3.0 * w), // top sides of handle guard piece
    };


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
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::ArucoDetector detector(dictionary, detector_params);


    cv::Mat desert_hex_mat = cv::imread("res/hexes/desert_hex.png");
    cv::Mat wheat_hex_mat = cv::imread("res/hexes/wheat_hex.png");
    cv::Mat ore_hex_mat = cv::imread("res/hexes/ore_hex.png");
    cv::Mat wood_hex_mat = cv::imread("res/hexes/wood_hex.png");
    cv::Mat sheep_hex_mat = cv::imread("res/hexes/sheep_hex.png");
    cv::Mat brick_hex_mat = cv::imread("res/hexes/brick_hex.png");


    std::vector<cv::Mat> mats;
    mats.push_back(desert_hex_mat);
    mats.push_back(wheat_hex_mat);
    mats.push_back(ore_hex_mat);
    mats.push_back(wood_hex_mat);
    mats.push_back(sheep_hex_mat);
    mats.push_back(brick_hex_mat);


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

    brick_hex_pts.push_back(cv::Point2f(0.00,0));
    brick_hex_pts.push_back(cv::Point2f(brick_hex_mat.cols - 1.00,0.00));
    brick_hex_pts.push_back(cv::Point2f(brick_hex_mat.cols - 1.00,brick_hex_mat.rows - 1.00));
    brick_hex_pts.push_back(cv::Point2f(0.00,brick_hex_mat.rows - 1.00));




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
            cv::aruco::drawDetectedMarkers(out, marker_corners, marker_ids);
            //std::vector<int> brick_check;

            for (int i = 0; i < marker_ids.size(); i++) {
                if (marker_ids.at(i) >= 43 && marker_ids.at(i) < 49) {
                    //brick_check.push_back(marker_ids.at(i));
                    marker_maps["brick_map"][marker_ids.at(i)] = marker_corners.at(i);
                }
            }

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

            // do homography first and draw on top of the resulting frame for the shapes
            for (int i = 1; i < 32; i++) { // can skip through a bunch of markers and iterate by 5
                if (i % 5 != 5 && i != 1) { // skip if not 1, 6, etc
                    continue;
                } else {
                    switch (i) {
                        // hex homography
                        // desert, wheat ore, wood, sheep, brick
                        case 1:
                            compute_homography(1, marker_maps["desert_map"], homography_points.at(0), wheat_hex_mat, frame, out);
                        case 6:
                            compute_homography(6, marker_maps["wheat_map_1"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 11:
                            compute_homography(11, marker_maps["wheat_map_2"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 16:
                            compute_homography(16, marker_maps["ore_map"], homography_points.at(2), ore_hex_mat, frame, out);
                        case 21:
                            compute_homography(21, marker_maps["sheep_mat"], homography_points.at(4), sheep_hex_mat, frame, out);
                        case 26:
                            compute_homography(26, marker_maps["wood_map"], homography_points.at(3), wood_hex_mat, frame, out);
                        case 31:
                            compute_homography(31, marker_maps["brick_map"], homography_points.at(5), brick_hex_mat, frame, out);
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
                            compute_homography(36, marker_maps["wheat_map_1_res"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 41:
                            compute_homography(41, marker_maps["wheat_map_2_res"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 46:
                            compute_homography(46, marker_maps["ore_map_res"], homography_points.at(2), ore_hex_mat, frame, out);
                        case 51:
                            compute_homography(51, marker_maps["sheep_mat_res"], homography_points.at(4), sheep_hex_mat, frame, out);
                        case 56:
                            compute_homography(56, marker_maps["wood_map_res"], homography_points.at(3), wood_hex_mat, frame, out);
                        case 61:
                            compute_homography(61, marker_maps["brick_map_res"], homography_points.at(5), brick_hex_mat, frame, out);
                    }
                }
            }
            for (int i = 66; i < 91; i++) { // same as above for resource cards
                /*
                marker_maps["knight_map"] = knight_map;
                marker_maps["vp_map"] = vp_map;
                marker_maps["monopoly_map"] = monopoly_map;
                marker_maps["road_building_map"] = road_building_map;
                marker_maps["yop_map"] = yop_map;
                 */

                if (i % 5 != 5) { // 36, 41, etc. else skip iteration
                    continue;
                } else {
                    switch (i) {
                        // res card homography
                        case 36:
                            compute_homography(36, marker_maps["knight_map"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 41:
                            compute_homography(41, marker_maps["wheat_map_2_res"], homography_points.at(1), wheat_hex_mat, frame, out);
                        case 46:
                            compute_homography(46, marker_maps["ore_map_res"], homography_points.at(2), ore_hex_mat, frame, out);
                        case 51:
                            compute_homography(51, marker_maps["sheep_mat_res"], homography_points.at(4), sheep_hex_mat, frame, out);
                        case 56:
                            compute_homography(56, marker_maps["wood_map_res"], homography_points.at(3), wood_hex_mat, frame, out);
                        case 61:
                            compute_homography(61, marker_maps["brick_map_res"], homography_points.at(5), brick_hex_mat, frame, out);
                    }
                }
            }


            for (int j = 0; j < marker_ids.size(); j++) {


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

            }

            for (int j = 0; j < marker_ids.size(); j++) {
                if (marker_ids.at(j) == 49) {
                    std::vector<cv::Point2f> img_points; // 2D calculated points to draw
                    cv::projectPoints(knight_points, rvecs.at(j), tvecs.at(j), cameraMatrix, distCoeffs, img_points);
                    draw_knight(out, img_points);
                }
            }

        }

        // various key presses below
        char key = cv::waitKey(10);

        if (key == 'q') {
            break;
        }

        if (key == 'r') {
            int roll = roll_dice();
            num_rolls.at(roll - 2) += 1;
            print_turn(player_scores, player_roads, roll);
        }


        cv::imshow("Camera", out); // show frame output


    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
