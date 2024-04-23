// A program to calibrate and save camera settings
// While 5 are required, the more images the more accurate, with aruco markers for the game this greatly helps

#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/aruco/aruco_calib.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect/charuco_detector.hpp>

int main() {

    // Board creation
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::CharucoBoard board = cv::aruco::CharucoBoard(cv::Size(5, 7), 0.0285f, 0.014f, dictionary);
    cv::aruco::CharucoDetector detector = cv::aruco::CharucoDetector(board);

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

    // hold all the board data for calibration
    std::vector<cv::Mat> all_marker_corners;
    std::vector<cv::Mat> all_marker_ids;
    std::vector<std::vector<cv::Point2f>> all_image_points;
    std::vector<std::vector<cv::Point3f>> all_object_points;

    for (;;) {

        *videoCapture >> frame;
        cv::Mat editedFrame; // mat to hold the edited frame
        if (frame.empty()) {
            std::cout << "Frame is empty" << std::endl;
            break;
        }

        // store frame board data
        std::vector<int> marker_ids;
        std::vector<std::vector<cv::Point2f>> marker_corners;
        cv::Mat curr_corners;
        cv::Mat curr_ids;
        std::vector<cv::Point3f> curr_obj_points;
        std::vector<cv::Point2f> curr_img_points;

        // detect and draw the board corners
        detector.detectBoard(frame, curr_corners, curr_ids, marker_corners, marker_ids);

        // draw the found markers and corners of board
        if(!marker_ids.empty()) {
            cv::aruco::drawDetectedMarkers(frame, marker_corners, marker_ids);
        }

        if(curr_corners.total() > 3) {
            cv::aruco::drawDetectedCornersCharuco(frame, curr_corners, curr_ids);
        }

        cv::imshow("Camera", frame); // show frame output

        // various key presses below
        char key = cv::waitKey(10);

        if (key == 'q') {
            break;
        }
        else if (key == 's'){ // save an image as calibration image

            if (!curr_ids.empty()) {
                board.matchImagePoints(curr_corners, curr_ids, curr_obj_points, curr_img_points);

                if(!curr_img_points.empty() & !curr_obj_points.empty()) {
                    std::cout << "Saved Image" << std::endl;
                    all_marker_corners.push_back(curr_corners);
                    all_marker_ids.push_back(curr_ids);
                    all_image_points.push_back(curr_img_points);
                    all_object_points.push_back(curr_obj_points);
                } else {
                    std::cout << "Unable to save image" << std::endl;
                }
            }
        }

    }

    if (all_object_points.size() >= 5) { // need at least five images saved to calibrate
        cv::Mat camera_matrix = cv::Mat(3, 3, CV_64FC1); // init vals for camera matrix
        camera_matrix.at<double>(0,0) = 1;
        camera_matrix.at<double>(0,1) = 0;
        camera_matrix.at<double>(0,2) = frame.cols / 2;
        camera_matrix.at<double>(1,0) = 0;
        camera_matrix.at<double>(1,1) = 1;
        camera_matrix.at<double>(1,2) = frame.rows/2;
        camera_matrix.at<double>(2,0) = 0;
        camera_matrix.at<double>(2,1) = 0;
        camera_matrix.at<double>(2,2) = 1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j++) {
                std::cout << camera_matrix.at<double>(i,j) << std::endl;
            }
        }
        std::vector<double> dist_coeffs;
        for (int i = 0; i < 8; i++) { // push 8 0's
            dist_coeffs.push_back(0.00);
        }

        // calibrate camera and get the reprojection error
        double repError = calibrateCamera(all_object_points, all_image_points, frame.size(), camera_matrix, dist_coeffs, cv::noArray(), cv::noArray(), cv::noArray(), cv::noArray(), cv::noArray(), cv::CALIB_FIX_ASPECT_RATIO);

        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j++) {
                std::cout << camera_matrix.at<double>(i,j) << std::endl;
            }
        }
        std::cout << "Reprojection error: " << repError << "\n";
        cv::FileStorage fs("camera_calibration_setting.xml", cv::FileStorage::WRITE);
        if (!fs.isOpened()) {
            return -1;
        }
        fs << "camera_matrix" << camera_matrix;
        fs << "distortion_coefficients" << dist_coeffs;
        fs << "reprojection_error" << repError;
        fs.release();
    } else {
        std::cout << "Need at least 5 images to calibrate camera";
    }

    delete videoCapture;
    return 0;
}
