#include <iostream>

#include "util.h"
#include <opencv2/opencv.hpp>
#include "draw_shapes.h"
#include "organize_markers.h"

int main() {

    // get the calibration settings
    cv::Mat camera_matrix = cv::Mat(3, 3, CV_64FC1);
    std::vector<double> dist_coeffs;
    cv::FileStorage fs("camera_calibration_setting.xml", cv::FileStorage::READ);
    if (!fs.isOpened()) {
        return -1;
    }
    fs["camera_matrix"] >> camera_matrix;
    fs["distortion_coefficients"] >> dist_coeffs;
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
        //std::vector<cv::Point3f> curr_obj_points;
        //std::vector<cv::Point2f> curr_img_points;

        std::unordered_map<std::string, std::unordered_map<int, std::vector < cv::Point2f>>> marker_maps = make_maps();

        int size_check = marker_maps.size(); // check that the marker maps were generated with correct size

        // find markers
        detector.detectMarkers(frame, marker_corners, marker_ids, rejected_candidates);

        // if markers are in view
        if (!marker_ids.empty() && !marker_corners.empty()) {

            if (size_check == 31) { // make sure marker map is full and ready for look up
                marker_maps = map_markers(marker_ids, marker_corners, marker_maps); // group markers and points together

                // coords
                cv::Mat obj_points(4, 1, CV_32FC3);
                float marker_length = .027; // measured on printed markers
                obj_points.ptr<cv::Vec3f>(0)[0] = cv::Vec3f(-marker_length/2.f, marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[1] = cv::Vec3f(marker_length/2.f, marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[2] = cv::Vec3f(marker_length/2.f, -marker_length/2.f, 0);
                obj_points.ptr<cv::Vec3f>(0)[3] = cv::Vec3f(-marker_length/2.f, -marker_length/2.f, 0);


                std::vector<cv::Vec3d> rvecs(marker_corners.size()), tvecs(marker_corners.size()); // rotation, translation vectors

                for (int i = 0; i < marker_corners.size(); i++) { // pose estimation for markers
                    solvePnP(obj_points, marker_corners.at(i), camera_matrix, dist_coeffs, rvecs.at(i), tvecs.at(i), cv::SOLVEPNP_ITERATIVE); // iterative providing best results with individual markers
                    // uncomment to view axes
                    //cv::drawFrameAxes(out, camera_matrix, dist_coeffs, rvecs[i], tvecs[i], marker_length, 2);
                }

                // compute the homography for the game tiles and cards and overlay them using sets of markers
                handle_homography(marker_maps, homography_points, mats, frame, out);

                // use markers to draw objects after homography so objects are on top
                solve_and_draw(marker_ids, rvecs, tvecs, object_map, dist_coeffs, camera_matrix, out);

            }
        }

        // key presses below
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

    return 0;
}
