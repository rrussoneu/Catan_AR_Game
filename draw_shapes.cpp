//
// Created by Raphael Russo on 4/17/24.
//

#include "draw_shapes.h"

/**
 * Draws a brick from image points - just a rectangular box
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_brick(cv::Mat &frame, std::vector<cv::Point2f> img_pts) {
    cv::line(frame, img_pts.at(0), img_pts.at(1), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(1), img_pts.at(2), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(2), img_pts.at(3), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(3), img_pts.at(0), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(0), img_pts.at(4), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(1), img_pts.at(5), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(2), img_pts.at(6), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(3), img_pts.at(7), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(4), img_pts.at(5), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(5), img_pts.at(6), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(6), img_pts.at(7), cv::Scalar(60,74,178), 5);
    cv::line(frame, img_pts.at(7), img_pts.at(4), cv::Scalar(60,74,178), 5);

    return 0;
}

/**
 * Draws a sheep from image points. There are some photos included in the report of the drawings/ planning for this
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_sheep(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    // start off drawing all the feet, body base, top of body, and connecting them
    for (int g = 0; g < 32; g++) {
        if (g < 16) {
            cv::line(frame, img_points.at(g), img_points.at(g + 16), cv::Scalar(0,255,0),5); // connect feet to bottom of body
        }
        // draw each square
        if (g % 4 != 3) {
            cv::line(frame, img_points.at(g), img_points.at(g + 1), cv::Scalar(0,255,0),5);
        }
        else {
            cv::line(frame, img_points.at(g), img_points.at(g - 3), cv::Scalar(0,255,0),5);
        }
    }

    // draw top of body square
    for (int g = 32; g < 36; g++) {
        if (g % 4 != 3) {
            cv::line(frame, img_points.at(g), img_points.at(g + 1), cv::Scalar(0,255,0),5);
        } else {
            cv::line(frame, img_points.at(g), img_points.at(g - 3), cv::Scalar(0,255,0),5);
        }
    }

    cv::line(frame, img_points.at(32), img_points.at(16), cv::Scalar(0,255,0),5); // need to draw the body middle and top connections manually, numbers don't line up
    cv::line(frame, img_points.at(33), img_points.at(21), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(34), img_points.at(26), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(35), img_points.at(31), cv::Scalar(0,255,0),5);

    // head
    for (int g = 36; g < 44; g++) {
        if (g < 40) {
            cv::line(frame, img_points.at(g), img_points.at(g + 4), cv::Scalar(0,255,0),5);
        }
        if (g % 4 != 3) {
            cv::line(frame, img_points.at(g), img_points.at(g + 1), cv::Scalar(0,255,0),5);
        } else {
            cv::line(frame, img_points.at(g), img_points.at(g - 3), cv::Scalar(0,255,0),5);
        }
    }


    // some other ones easier manually around the bottom part of body
    cv::line(frame, img_points.at(17), img_points.at(20), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(18), img_points.at(23), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(18), img_points.at(29), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(23), img_points.at(24), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(29), img_points.at(24), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(22), img_points.at(25), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(27), img_points.at(30), cv::Scalar(0,255,0),5);
    cv::line(frame, img_points.at(28), img_points.at(19), cv::Scalar(0,255,0),5);

    return 0;
}

/**
 * Draws ore from image points. Ends up a pyramid
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_ore(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(0), img_points.at(2), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(1), img_points.at(2), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(0), img_points.at(3), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(1), img_points.at(3), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(2), img_points.at(3), cv::Scalar(80,80,80),5);

    return 0;
}

/**
 * Draws wheat from image points. There are some photos included in the report of the drawings/ planning for this. Forms a trident like shape
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
int draw_wheat(cv::Mat &frame, std::vector<cv::Point2f> img_points) {

    for (int g = 0; g < img_points.size(); g++) { // draw squares and vertical lines
        if (g < 8) {
            cv::line(frame, img_points.at(g), img_points.at(g + 4), cv::Scalar(0,255,255),5);
        }
        if (g % 4 != 3) {
            cv::line(frame, img_points.at(g), img_points.at(g + 1), cv::Scalar(0,255,255),5);
        }
        else {
            cv::line(frame, img_points.at(g), img_points.at(g - 3), cv::Scalar(0,255,255),5);
        }
    }

    for (int g = 4; g < 8; g++) { // connect top sides to middle trunk
        cv::line(frame, img_points.at(g), img_points.at(g + 8), cv::Scalar(0,255,255),5);
        cv::line(frame, img_points.at(g), img_points.at(g + 12), cv::Scalar(0,255,255),5);
    }

    return 0;
}

int draw_wood(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    // bottom connecting
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(1), img_points.at(3), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(3), img_points.at(5), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(4), img_points.at(5), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(4), img_points.at(2), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(2), img_points.at(0), cv::Scalar(20,70,140), 5);

    // bottom to top
    cv::line(frame, img_points.at(0), img_points.at(6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(1), img_points.at(7), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(3), img_points.at(9), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(5), img_points.at(11), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(4), img_points.at(10), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(2), img_points.at(8), cv::Scalar(20,70,140), 5);

    // top connecting
    cv::line(frame, img_points.at(0 + 6), img_points.at(1 + 6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(1 + 6), img_points.at(3 + 6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(3 + 6), img_points.at(5 + 6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(4 + 6), img_points.at(5 + 6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(4 + 6), img_points.at(2 + 6), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(2 + 6), img_points.at(0 + 6), cv::Scalar(20,70,140), 5);

    return 0;
}

int draw_knight(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 1; i < 5; i++) {
        // z axis oriented lines for middle
        cv::line(frame, img_points.at(0), img_points.at(i), cv::Scalar(80,80,80), 5); // sword metal grey
        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(80,80,80), 5); // still sword metal
        cv::line(frame, img_points.at(i + 4), img_points.at(i + 8), cv::Scalar(20,70,140), 5); // handle guard brown
        cv::line(frame, img_points.at(i + 8), img_points.at(i + 12), cv::Scalar(80,80,80), 5); // handle grey
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i + (4 * j);
            // if this is one of the odd middle points, so we can draw lines along x from 1->2, 3->4, 5->6, etc.
            if ((idx % 4) % 2 == 1 ) {
                cv::line(frame, img_points.at(idx), img_points.at(idx + 1), cv::Scalar(80,80,80), 5);
            }
            // does y axis lines like 3->1, 4 -> 2 for the middle pieces
            if (idx % 4> 2) {
                cv::line(frame, img_points.at(idx), img_points.at(idx - 2), cv::Scalar(80,80,80), 5);
            }
        }
    }

    // connects the middle piece out to the sides of the handle
    for (int i = 5; i < 9; i++) {
        cv::line(frame, img_points.at(i), img_points.at(i +12), cv::Scalar(20,70,140), 5);
        cv::line(frame, img_points.at(i + 4), img_points.at(i + 4 + 12), cv::Scalar(20,70,140), 5);
    }

    // connects the sides of the handle all together
    for (int i = 17; i < 21; i++) {
        // connect vertically/ z axis
        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(20,70,140), 5);

        // connect along y
        if (i < 19) {
            cv::line(frame, img_points.at(i), img_points.at(i + 2), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 4 + 2), cv::Scalar(20,70,140), 5);

        }
    }



}