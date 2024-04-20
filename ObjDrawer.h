//
// Created by Raphael Russo on 4/18/24.
//

#ifndef CATAN_AR_GAME_OBJDRAWER_H
#define CATAN_AR_GAME_OBJDRAWER_H
#include "util.h"
#include <opencv2/opencv.hpp>

class ObjDrawer {
protected:
    // All the points for the 3D models of cards
    std::vector<cv::Point3f> wood_points = {cv::Point3f(1/20.0,1/20.0, 0.0), cv::Point3f(1.5/20.0,1/20.0, 0.0), cv::Point3f(.5/20.0,2/20.0, 0.0), cv::Point3f(2/20.0,2/20.0, 0.0),cv::Point3f(1/20.0,3/20.0, 0.0), cv::Point3f(1.5/20.0,3/20.0, 0.0),
                                            cv::Point3f(1/20.0,1/20.0,-2/10.0), cv::Point3f(1.5/20.0,1/20.0,-2/10.0), cv::Point3f(.5/20.0,2/20.0,-2/10.0), cv::Point3f(2/20.0,2/20.0,-2/10.0),cv::Point3f(1/20.0,3/20.0,-2/10.0), cv::Point3f(1.5/20.0,3/20.0,-2/10.0)};

    std::vector<cv::Point3f> sheep_points = {cv::Point3f(0.0,0.0,0.0), cv::Point3f(0.04,0.0,0.0), cv::Point3f(0.04,0.04,0.0), cv::Point3f(0.0,0.04,0.0), cv::Point3f(0.12,0.0,0.0), cv::Point3f(0.16,0.0,0.0), cv::Point3f(0.16,0.04,0.0), cv::Point3f(0.12,0.04,0.0), // sheep's anatomical bottom left
                                             cv::Point3f(0.12,0.08,0.0), cv::Point3f(0.16,0.08,0.0), cv::Point3f(0.16,0.12,0.0), cv::Point3f(0.12,0.12,0.0), cv::Point3f(0.0,0.08,0.0), cv::Point3f(0.04,0.08,0.0), cv::Point3f(0.04,0.12,0.0), cv::Point3f(0.00,0.12,0.0), // sheep's anatomical bottom right
                                             cv::Point3f(0.0,0.0,-0.06), cv::Point3f(0.04,0.0,-0.06), cv::Point3f(0.04,0.04,-0.06), cv::Point3f(0.0,0.04,-0.06), cv::Point3f(0.12,0.0,-0.06), cv::Point3f(0.16,0.0,-0.06), cv::Point3f(0.16,0.04,-0.06), cv::Point3f(0.12,0.04,-0.06), // sheep's anatomical middle layer left
                                             cv::Point3f(0.12,0.08,-0.06), cv::Point3f(0.16,0.08,-0.06), cv::Point3f(0.16,0.12,-0.06), cv::Point3f(0.12,0.12,-0.06), cv::Point3f(0.0,0.08,-0.06), cv::Point3f(0.04,0.08,-0.06), cv::Point3f(0.04,0.12,-0.06), cv::Point3f(0.00,0.12,-0.06), // sheep's anatomical middle layer right
            // top square of sheep body
                                             cv::Point3f(0.0,0.0,-0.12), cv::Point3f(0.16,0.0,-0.12), cv::Point3f(0.16,0.12,-0.12), cv::Point3f(0.0,0.12,-0.12),
            // head bottom
                                             cv::Point3f(.16,.04,-.06), cv::Point3f(.2,.04,-.06), cv::Point3f(.2,.08,-.06), cv::Point3f(.16,.08,-.06),
            // head top
                                             cv::Point3f(.16,.04,-.12), cv::Point3f(.2,.04,-.12), cv::Point3f(.2,.08,-.12), cv::Point3f(.16,.08,-.12),

    };


    std::vector<cv::Point3f> brick_points = {cv::Point3f(0.0, 0.0, 0.0), cv::Point3f(0.10, 0.0, 0.0), cv::Point3f(0.10, 0.05, 0.0), cv::Point3f(0.0, 0.05, 0.0),
                                             cv::Point3f(0.0, 0.0, -0.05), cv::Point3f(0.10, 0.0, -0.05), cv::Point3f(0.10, 0.05, -0.05), cv::Point3f(0.0, 0.05, -0.05),};

    std::vector<cv::Point3f> ore_points = {cv::Point3f(0.00,0.00,0.0), cv::Point3f(0.1, 0.00,0.00), cv::Point3f(0.05, 0.1, 0.00), cv::Point3f(0.05, 0.05, -.1)};

    std::vector<cv::Point3f> wheat_points = {cv::Point3f(0.06+ .02, 0.0,0.0), cv::Point3f(0.1 + .02, 0.0,0.00), cv::Point3f(0.1+ .02, 0.04, 0.00), cv::Point3f(0.08, 0.04, 0.00), // base
                                             cv::Point3f(0.06+ .02, 0.0,-0.06), cv::Point3f(0.1+ .02, 0.0,-0.06), cv::Point3f(0.1+ .02, 0.04, -0.06), cv::Point3f(0.06+ .02, 0.04, -0.06), // middle
                                             cv::Point3f(0.06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .02, 0.0,-0.12), cv::Point3f(0.1+ .02, 0.04, -0.12), cv::Point3f(0.06+ .02, 0.04, -0.12), // top middle
                                             cv::Point3f(0.06 - .06, 0.0,-0.12), cv::Point3f(0.1- .06, 0.0,-0.12), cv::Point3f(0.1- .06, 0.04, -0.12), cv::Point3f(0.06 - .06, 0.04, -0.12), // top left
                                             cv::Point3f(0.06 + .06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .06+ .02, 0.04, -0.12), cv::Point3f(0.06 + .06+ .02, 0.04, -0.12) // top right
    };

    int w = 0.04; // the sword is built using multiples of .04 for distances between points
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
public:
    ObjDrawer() {}
    ~ObjDrawer() = default;
    /**
 * Draws a brick from image points - just a rectangular box
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
    int draw_brick(cv::Mat &frame, std::vector<cv::Point2f> img_pts);

/**
 * Draws a sheep from image points. There are some photos included in the report of the drawings/ planning for this
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
    int draw_sheep(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws ore from image points. Ends up a pyramid
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
    int draw_ore(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws wheat from image points. There are some photos included in the report of the drawings/ planning for this. Forms a trident like shape
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
    int draw_wheat(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws wheat from image points
 * @param frame frame to draw on
 * @param img_pts points to connect
 * @return on success
 */
    int draw_wood(cv::Mat &frame, std::vector<cv::Point2f> img_points);

/**
 * Draws a sword to represent knight in AR
 * @param frame frame to draw on
 * @param img_points points to connect
 * @return on success
 */
    int draw_knight(cv::Mat &frame, std::vector<cv::Point2f> img_points);
};


#endif //CATAN_AR_GAME_OBJDRAWER_H
