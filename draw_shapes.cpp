//
// Utility functions related to 3D models and their rendering
//

#include "draw_shapes.h"

/**
 * Generates a map of vectors of 3d points for drawing objects
 * @return the map
 */
std::unordered_map<std::string, std::vector<cv::Point3f>> generate_3d_points() {
    std::unordered_map<std::string, std::vector<cv::Point3f>> object_map; // store the models

    // The points for hexagon models
    std::vector<cv::Point3f> wood_hex_points = {cv::Point3f(-0.02,0.0,0.0), cv::Point3f(0.02,0.0,0.0),  cv::Point3f(0.02,-0.04,0.0), cv::Point3f(-0.02,-.04,0.0),// square base
                                                cv::Point3f(-.02,0.0,0.05), cv::Point3f(0.02,0.0,0.05), cv::Point3f(0.02,-.04,0.05), cv::Point3f(-0.02,-.04,0.05),  // top of tree trunk
                                                cv::Point3f(-0.04, 0.0, 0.05), cv::Point3f(.04, 0.0, 0.05), cv::Point3f(.04, -.04, 0.05), cv::Point3f(-0.04, -0.04, 0.05),  // leaves base
                                                cv::Point3f(-0.04, 0.0, 0.07), cv::Point3f(.04, 0.0, 0.07),cv::Point3f(.04, -.04, 0.07), cv::Point3f(-0.04, -.04, 0.07),  // leaves level 2
                                                cv::Point3f(-0.01, 0.0, 0.09), cv::Point3f(.01, 0.0, 0.09), cv::Point3f(.01, -.04, 0.09), cv::Point3f(-0.01, -.04, 0.09),  // leaves level 3
                                                cv::Point3f(0.0, 0.0, 0.1), cv::Point3f(0.0, -.04, 0.1) // top of leaves

    };
    object_map["wood_hex"] = wood_hex_points;

    std::vector<cv::Point3f> wheat_points = {cv::Point3f(-.015, 0.0,0.0), cv::Point3f(.015, 0.0,0.00), cv::Point3f(.015, -0.015, 0.00), cv::Point3f(-.015, -0.015, 0.00), // base
                                             cv::Point3f(-.015, 0.0,0.04), cv::Point3f(.015, 0.0,0.04), cv::Point3f(0.015, -0.015, 0.04), cv::Point3f(-0.015, -0.015, 0.04), // middle
                                             cv::Point3f(-.015, 0.0,0.06), cv::Point3f(.015, 0.0,0.06), cv::Point3f(0.015, -0.015, 0.06), cv::Point3f(-0.015, -0.015, 0.06), // middle
                                             cv::Point3f(-.055, 0.0,0.06), cv::Point3f(-.025, 0.0,0.06), cv::Point3f(-.025, -0.015, 0.06), cv::Point3f(-.055, -0.015, 0.06), // top left
                                             cv::Point3f(.025, 0.0,0.06), cv::Point3f(0.055, 0.0,0.06), cv::Point3f(0.055, -0.015, 0.06), cv::Point3f(.025, -.015, 0.06) // top right
    };
    object_map["wheat_hex"] = wheat_points;
    object_map["wheat_res"] = wheat_points;



    std::vector<cv::Point3f> sheep_points = {cv::Point3f(-0.03,0.0,0.0), cv::Point3f(-.015,0.0,0.0), cv::Point3f(-.015,.015,0.0), cv::Point3f(-0.03,.015,0.0), cv::Point3f(0.01,0.0,0.0), cv::Point3f(.025,0.0,0.0), cv::Point3f(.025,0.015,0.0), cv::Point3f(.01,.015,0.0), // sheep's anatomical bottom left
                                             cv::Point3f(.01,0.08/3,0.0), cv::Point3f(.025,0.08/3,0.0), cv::Point3f(0.025,0.04,0.0), cv::Point3f(.01,0.12/3,0.0), cv::Point3f(-0.03,0.08/3,0.0), cv::Point3f(-0.015,0.08/3,0.0), cv::Point3f(-0.015,0.12/3,0.0), cv::Point3f(-0.03,0.12/3,0.0), // sheep's anatomical bottom right
                                             cv::Point3f(-0.03,0.0,0.06/3), cv::Point3f(-0.015,0.0,0.06/3), cv::Point3f(-0.015,0.04/3,0.06/3), cv::Point3f(-0.03,0.04/3,0.06/3), cv::Point3f(.01,0.0,0.06/3), cv::Point3f(.025,0.0,0.06/3), cv::Point3f(.025,0.04/3,0.06/3), cv::Point3f(.01,0.04/3,0.06/3), // sheep's anatomical middle layer left
                                             cv::Point3f(.01,0.08/3,0.06/3), cv::Point3f(.025,0.08/3,0.06/3), cv::Point3f(.025,0.12/3,0.06/3), cv::Point3f(0.01,0.12/3,0.06/3), cv::Point3f(-0.03,0.08/3,0.06/3), cv::Point3f(-.015,0.08/3,0.06/3), cv::Point3f(-.015,0.12/3,0.06/3), cv::Point3f(-0.03,0.12/3,0.06/3), // sheep's anatomical middle layer right
            // top square of sheep body
                                             cv::Point3f(-0.03,0.0,0.12/3), cv::Point3f(0.025,0.0,0.12/3), cv::Point3f(0.025,0.12/3,0.12/3), cv::Point3f(-0.03,0.12/3,0.12/3),
            // head bottom
                                             cv::Point3f(0.025,.04/3,.06/3), cv::Point3f(0.035,.04/3,.06/3), cv::Point3f(0.035,.08/3,.06/3), cv::Point3f(0.025,.08/3,.06/3),
            // head top
                                             cv::Point3f(0.025,.04/3,.12/3), cv::Point3f(0.035,.04/3,.12/3), cv::Point3f(0.035,.08/3,.12/3), cv::Point3f(0.025,.08/3,.12/3),

    };
    object_map["sheep_hex"] = sheep_points;
    object_map["sheep_res"] = sheep_points;


    std::vector<cv::Point3f> ore_hex_points = {cv::Point3f(-0.04,0.0,0.0), cv::Point3f(-0.04,0.04/1.5,0.0),cv::Point3f(-0.02,0.08/1.5,0.0), cv::Point3f(0.02,0.08/1.5,0.0), cv::Point3f(0.04,0.04/1.5,0.0),cv::Point3f(0.04,0.0,0.0), // base outside
                                               cv::Point3f(-0.02,0.04/1.5,0.0), cv::Point3f(0.02,0.04/1.5,0.0),  cv::Point3f(0.02, 0.0,0.0), cv::Point3f(-0.02, 0.0,0.0), // base inside

                                               cv::Point3f(-0.04,0.0,0.04), cv::Point3f(-0.04,0.04/1.5,0.04),cv::Point3f(-0.02,0.08/1.5,0.04), cv::Point3f(0.02,0.08/1.5,0.04), cv::Point3f(0.04,0.04/1.5,0.04),cv::Point3f(0.04,0.0,0.04), // layer 2 outside
                                               cv::Point3f(-0.02,0.04/1.5,0.04), cv::Point3f(0.02,0.04/1.5,0.04),  cv::Point3f(0.02, 0.0,0.04), cv::Point3f(-0.02, 0.0,0.04), // layer 2 inside

                                               cv::Point3f(-.03, 0.08/1.5/2, .06), cv::Point3f(.03, 0.08/1.5/2, .06), cv::Point3f(-.03, 0.02/1.5/2, .06), cv::Point3f(.03, 0.02/1.5/2, .06) // mountain peaks
    };
    object_map["ore_hex"] = ore_hex_points;

    std::vector<cv::Point3f> brick_hex_points = { cv::Point3f(-.09/2, .02/2, 0.0), cv::Point3f(-.03/2, .02/2, 0.0), cv::Point3f(.03/2, .02/2, 0.0), cv::Point3f(.09/2, .02/2, 0.0), // back of bottom
                                                  cv::Point3f(.09/2, -.04/2, 0.0),  cv::Point3f(.03/2, -.04/2, 0.0),  cv::Point3f(-.03/2, -.04/2, 0.0), cv::Point3f(-.09/2, -.04/2, 0.0), // front of bottom
                                                  cv::Point3f(-.09/2, .02/2, 0.035), cv::Point3f(-.03/2, .02/2, 0.035), cv::Point3f(.03/2, .02/2, 0.035), cv::Point3f(.09/2, .02/2, 0.035), // back of middle
                                                  cv::Point3f(.09/2, -.04/2, 0.035),  cv::Point3f(.03/2, -.04/2, 0.035),  cv::Point3f(-.03/2, -.04/2, 0.035), cv::Point3f(-.09/2, -.04/2, 0.035), // front of middle

    };
    object_map["brick_hex"] = brick_hex_points;

    // Points for the 3D models of resource cards
    std::vector<cv::Point3f> wood_points = {cv::Point3f(1/20.0,1/20.0, 0.0), cv::Point3f(1.5/20.0,1/20.0, 0.0), cv::Point3f(.5/20.0,2/20.0, 0.0), cv::Point3f(2/20.0,2/20.0, 0.0),cv::Point3f(1/20.0,3/20.0, 0.0), cv::Point3f(1.5/20.0,3/20.0, 0.0),
                                            cv::Point3f(1/20.0,1/20.0,-2/10.0), cv::Point3f(1.5/20.0,1/20.0,-2/10.0), cv::Point3f(.5/20.0,2/20.0,-2/10.0), cv::Point3f(2/20.0,2/20.0,-2/10.0),cv::Point3f(1/20.0,3/20.0,-2/10.0), cv::Point3f(1.5/20.0,3/20.0,-2/10.0)};




    std::vector<cv::Point3f> brick_res_points = {cv::Point3f(-0.03, 0.0, 0.0), cv::Point3f(0.03, 0.0, 0.0), cv::Point3f(0.03, -0.03, 0.0), cv::Point3f(-0.03, -0.03, 0.0),
                                             cv::Point3f(-0.03, 0.0, 0.03), cv::Point3f(0.03, 0.0, 0.03), cv::Point3f(0.03, -0.03, 0.03), cv::Point3f(-0.03, -0.03, 0.03),};


    object_map["brick_res"] = brick_res_points;

    std::vector<cv::Point3f> ore_res_points = {cv::Point3f(-0.025,0.00,0.0), cv::Point3f(0.025, 0.00,0.00), cv::Point3f(0.00, 0.05, 0.00), cv::Point3f(0.0, 0.025, .025)};
    object_map["ore_res"] = ore_res_points;

    std::vector<cv::Point3f> wood_res_points = {

            cv::Point3f(-0.005, -0.03, 0.0), cv::Point3f(0.005, -0.03, 0.0), cv::Point3f(0.005, 0.03, 0.0), cv::Point3f(-0.005, 0.03, 0.0),
            cv::Point3f(-0.01, -0.03, 0.01), cv::Point3f(0.01, -0.03, 0.01), cv::Point3f(0.01, 0.03, 0.01), cv::Point3f(-0.01, 0.03, 0.01),
            cv::Point3f(-0.01, -0.03, 0.02), cv::Point3f(0.01, -0.03, 0.02), cv::Point3f(0.01, 0.03, 0.02), cv::Point3f(-0.01, 0.03, 0.02),
            cv::Point3f(-0.005, -0.03, 0.03), cv::Point3f(0.005, -0.03, 0.03), cv::Point3f(0.005, 0.03, 0.03), cv::Point3f(-0.005, 0.03, 0.03),

    };

    object_map["wood_res"] = wood_res_points;

    // Dev cards

    // giant plus, isn't really a great representation
    std::vector<cv::Point3f> yop_points = { cv::Point3f(0.0,0.0,0.0), cv::Point3f(-.04,0.0,0.05), cv::Point3f(0.04, 0.0, 0.05), cv::Point3f(0.0,0.0,0.1)};
    object_map["yop"] = yop_points;

    // money sign
    std::vector<cv::Point3f> monopoly_points = { cv::Point3f(-.02, 0.0, 0.01), // 0
                                                 cv::Point3f(.01, 0.0, 0.01), // 1
                                                 cv::Point3f(.02, 0.0, 0.015), // 2
                                                 cv::Point3f(.01, 0.0, 0.02),  // 3
                                                 cv::Point3f(-.01, 0.0, 0.04),  // 4
                                                 cv::Point3f(-.02, 0.0, 0.045), // 5
                                                 cv::Point3f(-.01, 0.0, 0.05), // 6
                                                 cv::Point3f(.02, 0.0, 0.05), // 7
                                                 cv::Point3f(-.01, 0.0, 0.06), // 8
                                                 cv::Point3f(-.01, 0.0, 0.00), // 9
                                                 cv::Point3f(.01, 0.0, 0.06), // 10
                                                 cv::Point3f(.01, 0.0, 0.00), // 11
    };
    object_map["monopoly"] = monopoly_points;

    // shovel
    std::vector<cv::Point3f> road_building_points = {
            cv::Point3f(0.01,0.0,0.0), // tip
            cv::Point3f(-0.01,0.0,0.01), // bottom metal
            cv::Point3f(0.03,0.0,0.01), // bottom metal
            cv::Point3f(-0.01,0.0,0.03), // top metal
            cv::Point3f(0.03,0.0,0.03), // top metal
            cv::Point3f(0.01,0.0,0.03), // start of handle
            cv::Point3f(0.01,0.0,0.06), // top of handle
            cv::Point3f(-0.01,0.0,0.06), // top left handle
            cv::Point3f(0.03,0.0,0.06), // top right handle

    };
    object_map["road_building"] = road_building_points;

    // road is simple, a thick line looks better than a rectangle
    std::vector<cv::Point3f> road_points = {cv::Point3f(-0.02, 0.0, 0.01), cv::Point3f(.02, 0.0, 0.01)};
    object_map["road"] = road_points;

    // chalice
    std::vector<cv::Point3f> vp_points {
                                        // bottom
                                        cv::Point3f(-.015, 0.0, 0.0), cv::Point3f(-.005,-0.01, 0.0), cv::Point3f(.005, -0.01, 0.0), cv::Point3f(.015, 0.0, 0.0),
                                        cv::Point3f(.015, 0.01, 0.0),cv::Point3f(.005, 0.02, 0.0), cv::Point3f(-.005,0.02, 0.0), cv::Point3f(-0.015, 0.01, 0.0),

                                        // middle of cup
                                        cv::Point3f(-.015, 0.0, 0.035), cv::Point3f(-.005,-0.01, 0.035), cv::Point3f(.005, -0.01, 0.035), cv::Point3f(.015, 0.0, 0.035),
                                        cv::Point3f(.015, 0.01, 0.035),cv::Point3f(.005, 0.02, 0.035), cv::Point3f(-.005,0.02, 0.035), cv::Point3f(-0.015, 0.01, 0.035),

                                        cv::Point3f(-.015, 0.0, 0.05), cv::Point3f(-.005,-0.01, 0.05), cv::Point3f(.005, -0.01, 0.05), cv::Point3f(.015, 0.0, 0.05),
                                        cv::Point3f(.015, 0.01, 0.05),cv::Point3f(.005, 0.02, 0.05), cv::Point3f(-.005,0.02, 0.05), cv::Point3f(-0.015, 0.01, 0.05),

                                        // handle top
                                        cv::Point3f(0.0,0.0,0.02),
                                        // handle bottom
                                        cv::Point3f(0.0,0.0,0.01)

    };
    object_map["vp"] = vp_points;

    // Game pieces
    std::vector<cv::Point3f> robber_points = {cv::Point3f(0.00,0.00,0.0), cv::Point3f(0.0, 0.00,0.035), cv::Point3f(0.0, 0.0, 0.05), cv::Point3f(0.005, 0.0, 0.035), cv::Point3f(-0.005,0.0,0.035)};
    object_map["robber"] = robber_points;

    std::vector<cv::Point3f> settlement_points = {  // bottom
                                                    cv::Point3f(-0.015, 0.0, 0.0), cv::Point3f(0.015, 0.0, 0.0), cv::Point3f(0.015, -0.015, 0.0), cv::Point3f(-0.015,-0.015,0.0),
                                                    // middle
                                                    cv::Point3f(-0.015, 0.0, 0.02), cv::Point3f(0.015, 0.0, 0.02), cv::Point3f(0.015, -0.015, 0.02), cv::Point3f(-0.015,-0.015,0.02),
                                                    // top
                                                    cv::Point3f(-0.005, -0.0075, 0.03),
                                                    cv::Point3f(0.005, -0.0075, 0.03),



    };
    object_map["settlement"] = settlement_points;

    std::vector<cv::Point3f> city_points = {

            // bottom
            cv::Point3f(-0.015, 0.0, 0.0), cv::Point3f(0.005, 0.0, 0.0), cv::Point3f(0.005, -0.015, 0.0), cv::Point3f(-0.015,-0.015,0.0),
            // middle
            cv::Point3f(-0.015, 0.0, 0.02), cv::Point3f(0.005, 0.0, 0.02), cv::Point3f(0.005, -0.015, 0.02), cv::Point3f(-0.015,-0.015,0.02),

            // base bottom
            cv::Point3f(-0.015, 0.0, 0.0), cv::Point3f(0.005, 0.0, 0.0), cv::Point3f(0.005, -0.015, 0.0), cv::Point3f(-0.015,-0.015,0.0),
            cv::Point3f(0.015, 0.0, 0.0), cv::Point3f(0.015, -0.015, 0.0),

            // base middle
            cv::Point3f(-0.015, 0.0, 0.02), cv::Point3f(0.015, 0.0, 0.02), cv::Point3f(0.015, -0.015, 0.02), cv::Point3f(-0.015,-0.015,0.02),
            cv::Point3f(0.015, 0.0, 0.02), cv::Point3f(0.015, -0.015, 0.02),

            // top
            cv::Point3f(-0.005, -0.0075, 0.03),
            cv::Point3f(0.005, -0.0075, 0.03),



    };
    object_map["city"] = city_points;



    return object_map;


}



/**
 * Draws a sheep from image points
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
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(80,80,80),15);
    cv::line(frame, img_points.at(0), img_points.at(2), cv::Scalar(80,80,80),15);
    cv::line(frame, img_points.at(1), img_points.at(2), cv::Scalar(80,80,80),15);
    cv::line(frame, img_points.at(0), img_points.at(3), cv::Scalar(80,80,80),15);
    cv::line(frame, img_points.at(1), img_points.at(3), cv::Scalar(80,80,80),15);
    cv::line(frame, img_points.at(2), img_points.at(3), cv::Scalar(80,80,80),15);

    return 0;
}

/**
 * Draws wheat from image points
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

/**
 * Draws a sword to represent knight in AR
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_robber(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(80,80,80), 10);
    cv::line(frame, img_points.at(1), img_points.at(2), cv::Scalar(20,70,140), 5);
    cv::line(frame, img_points.at(3), img_points.at(4), cv::Scalar(20,70,140), 5);
}

void draw_wood_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 0; i < 4; i++) { // handle rectangular connections for the diffrent levels
        if (i != 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 8), cv::Scalar(0,255,0), 5); // green for leaf connections
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), cv::Scalar(20,70,140), 5);

        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 4 -3), cv::Scalar(20,70,140), 5);

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(20,70,140), 5);
        cv::line(frame, img_points.at(i + 8), img_points.at(i + 12), cv::Scalar(0,255,0), 5);
        cv::line(frame, img_points.at(i + 12), img_points.at(i + 16), cv::Scalar(0,255,0), 5);

    }

    // handle irregular leaf connections
    cv::line(frame, img_points.at(8), img_points.at(11), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(7), img_points.at(11), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(9), img_points.at(10), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(12), img_points.at(15), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(13), img_points.at(14), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(16), img_points.at(19), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(17), img_points.at(18), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(16), img_points.at(20), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(17), img_points.at(20), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(18), img_points.at(21), cv::Scalar(0,255,0), 5);
    cv::line(frame, img_points.at(19), img_points.at(21), cv::Scalar(0,255,0), 5);

}

void draw_ore_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for(int i = 0; i < 5; i++) {
        cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(80,80,80),5); // connect base
        cv::line(frame, img_points.at(i + 10), img_points.at(i + 11), cv::Scalar(80,80,80),5); // connect middle
        cv::line(frame, img_points.at(i), img_points.at(i + 10), cv::Scalar(80,80,80),5); // connect base to middle
    }
    cv::line(frame, img_points.at(5), img_points.at(15), cv::Scalar(80,80,80),5); // connect middle


    cv::line(frame, img_points.at(0), img_points.at(9), cv::Scalar(80,80,80),5); // connect outside front
    cv::line(frame, img_points.at(5), img_points.at(8), cv::Scalar(80,80,80),5); // connect outside front
    cv::line(frame, img_points.at(10), img_points.at(19), cv::Scalar(80,80,80),5); // connect outside front
    cv::line(frame, img_points.at(15), img_points.at(18), cv::Scalar(80,80,80),5); // connect outside front

    cv::line(frame, img_points.at(9), img_points.at(19), cv::Scalar(80,80,80),5); // connect outside front
    cv::line(frame, img_points.at(8), img_points.at(18), cv::Scalar(80,80,80),5); // connect outside front

    for (int i = 6; i < 8; i++) {
        if (i == 6) {
            cv::line(frame, img_points.at(i), img_points.at(i + 3), cv::Scalar(80,80,80),5); // connect inside part of base
            cv::line(frame, img_points.at(i + 10), img_points.at(i + 13), cv::Scalar(80,80,80),5); // connect inside part of base

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(80,80,80),5); // connect inside part of base
        cv::line(frame, img_points.at(i + 10), img_points.at(i + 11), cv::Scalar(80,80,80),5); // connect inside part of base
        cv::line(frame, img_points.at(i), img_points.at(i + 10), cv::Scalar(80,80,80),5); // connect inside base to middle inside
    }


    // connect peaks

    cv::line(frame, img_points.at(20), img_points.at(20 - 9), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(20), img_points.at(20 - 8), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(20), img_points.at(20 - 4), cv::Scalar(80,80,80),5);

    cv::line(frame, img_points.at(22), img_points.at(11), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(22), img_points.at(16), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(22), img_points.at(10), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(22), img_points.at(19), cv::Scalar(80,80,80),5);

    cv::line(frame, img_points.at(21), img_points.at(13), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(21), img_points.at(17), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(21), img_points.at(14), cv::Scalar(80,80,80),5);

    cv::line(frame, img_points.at(23), img_points.at(17), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(23), img_points.at(14), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(23), img_points.at(15), cv::Scalar(80,80,80),5);
    cv::line(frame, img_points.at(23), img_points.at(18), cv::Scalar(80,80,80),5);

}

/**
 * Draws a brick shape for brick tile
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_brick_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 0; i < 8; i++) {
        if (i < 7) { // connect pieces inside layer
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 9), cv::Scalar(60,74,178), 5);

        } else { // left side connections
            cv::line(frame, img_points.at(i), img_points.at(i - 7), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 1), cv::Scalar(60,74,178), 5);
        }
        if (i == 1) { // extra middle brick line
            cv::line(frame, img_points.at(i), img_points.at(i + 5), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 13), cv::Scalar(60,74,178), 5);

        }
        if (i==2) { // extra middle brick line
            cv::line(frame, img_points.at(i), img_points.at(i + 3), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 8 ), img_points.at(i + 11), cv::Scalar(60,74,178), 5);

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 8), cv::Scalar(60,74,178), 5);


    }
}

/**
 * Draws year of plenty plus symbol
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_yop(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // giant plus
    cv::line(frame, img_points.at(0), img_points.at(3), cv::Scalar(0,255,0), 50);
    cv::line(frame, img_points.at(1), img_points.at(2), cv::Scalar(0,255,0), 50);

}

/**
 * Draws a dollar sign to represent monopoly card
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_monopoly(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // money sign
    for (int i = 0; i < 11; i++) {
        if (i != 7 && i != 9) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(0,255,0), 20);
        }
    }
}

/**
 * Draws a shovel to represent road building
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_road_building(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // shovel
    // first the bottom metal piece
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(0), img_points.at(2), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(1), img_points.at(3), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(3), img_points.at(4), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(2), img_points.at(4), cv::Scalar(60,74,178), 30);
    // handle of shovel
    cv::line(frame, img_points.at(5), img_points.at(6), cv::Scalar(20,70,140), 30);
    cv::line(frame, img_points.at(7), img_points.at(8), cv::Scalar(20,70,140), 30);
}

/**
 * Draws a road
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_road(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color) {
    cv::line(frame, img_points.at(0), img_points.at(1), color, 30);
}

/**
 * Draws a chalice to represent victory point
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_vp(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i =0; i < 8; i++) { // connect the octagons of the chalice
        if (i < 7) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(50,170,210), 10);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 9), cv::Scalar(50,170,210), 10);
            cv::line(frame, img_points.at(i + 16), img_points.at(i + 17), cv::Scalar(50,170,210), 10);


        }
        // handle connections
        cv::line(frame, img_points.at(i), img_points.at(img_points.size()-1), cv::Scalar(50,170,210), 10);
        cv::line(frame, img_points.at(i+8), img_points.at(img_points.size()-2), cv::Scalar(50,170,210), 10);
        cv::line(frame, img_points.at(i+8), img_points.at(i + 16), cv::Scalar(50,170,210), 10);


        if (i == 0) { // make vertical connections
            cv::line(frame, img_points.at(i), img_points.at(i + 7), cv::Scalar(50,170,210), 10);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 15), cv::Scalar(50,170,210), 10);
            cv::line(frame, img_points.at(i + 16), img_points.at(i + 23), cv::Scalar(50,170,210), 10);


        }
    }
    // connect handle
    cv::line(frame, img_points.at(img_points.size()-1), img_points.at(img_points.size()-2), cv::Scalar(50,170,210), 10);

}

/**
 * Draws a settlement
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_settlement(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color) {
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), color, 5); // connect rectangle
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), color, 5); // connect rectangle


        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), color, 5); // connect left most
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 1), color, 5); // connect left most

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 4), color, 5); // connect rectangles

    }
    cv::line(frame, img_points.at(4), img_points.at(8), color, 5); // connect top
    cv::line(frame, img_points.at(7), img_points.at(8), color, 5); // connect top
    cv::line(frame, img_points.at(5), img_points.at(9), color, 5); // connect top
    cv::line(frame, img_points.at(6), img_points.at(9), color, 5); // connect top

    cv::line(frame, img_points.at(img_points.size()-1), img_points.at(img_points.size()-2), color, 5); // connect top to itself
}

/**
 * Draws a city
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color for red, green, blue, brown player
 */
void draw_city(cv::Mat &frame, std::vector<cv::Point2f> img_points, cv::Scalar color) {
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), color, 5); // connect rectangle
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), color, 5); // connect rectangle


        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), color, 5); // connect left most
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 1), color, 5); // connect left most

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 4), color, 5); // connect rectangles

    }

    for (int i = 8; i < 14; i++) {
        if (i < 11) { // middle layer connections
            cv::line(frame, img_points.at(i), img_points.at(i + 1), color, 5); // connect rectangle to itself
            cv::line(frame, img_points.at(i + 6), img_points.at(i + 7), color, 5); // connect rectangle to itself

        }
        if (i == 11) {
            cv::line(frame, img_points.at(i), img_points.at(8), color, 5);
        }
        if (i == 12) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), color, 5);
            cv::line(frame, img_points.at(i), img_points.at(i + 6), color, 5);
            cv::line(frame, img_points.at(i+1), img_points.at(i + 7), color, 5);

        }

    }
    cv::line(frame, img_points.at(9), img_points.at(12), color, 5); // connect rectangle
    cv::line(frame, img_points.at(10), img_points.at(13), color, 5); // connect rectangle
    cv::line(frame, img_points.at(9+6), img_points.at(12+6), color, 5); // connect rectangle
    cv::line(frame, img_points.at(10+6), img_points.at(13+6), color, 5); // connect rectangle

    for (int i = 14; i < 18; i++) {
        cv::line(frame, img_points.at(i-10), img_points.at(i), color, 5); // connect rectangle
    }
    cv::line(frame, img_points.at(4), img_points.at(img_points.size()-2), color, 5); // connect top
    cv::line(frame, img_points.at(7), img_points.at(img_points.size()-2), color, 5); // connect top
    cv::line(frame, img_points.at(5), img_points.at(img_points.size()-1), color, 5); // connect top
    cv::line(frame, img_points.at(6), img_points.at(img_points.size()-1), color, 5); // connect top

    cv::line(frame, img_points.at(img_points.size()-1), img_points.at(img_points.size()-2), color, 5); // connect top to itself
}

/**
 * Draws a log for wood resource card
 * @param frame frame to draw on
 * @param img_points points to connecct
 */
void draw_wood_res(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 0; i < 4; i++) {
        // connects series of rectangles to themselves and each other into a log shape
        if (i != 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 9), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 12), img_points.at(i + 13), cv::Scalar(20,70,140), 5);

        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 4 -3), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 8), img_points.at(i + 8 -3), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 12), img_points.at(i + 12 -3), cv::Scalar(20,70,140), 5);



        }
        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(20,70,140), 5);
        cv::line(frame, img_points.at(i + 4), img_points.at(i + 8), cv::Scalar(20,70,140), 5);
        cv::line(frame, img_points.at(i + 8), img_points.at(i + 12), cv::Scalar(20,70,140), 5);
    }
}

/**
 * Draws a small brick for brick resource
 * @param frame frame to draw on
 * @param img_points points to connect
 */
void draw_brick_res(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 0; i < 4; i++) {
        if (i != 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), cv::Scalar(60,74,178), 5);

        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), cv::Scalar(60,74,178), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 1), cv::Scalar(60,74,178), 5);
        }

        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(60,74,178), 5);
    }
}

/**
 * Draws various shapes based on marker poses and id's
 * @param marker_ids the marker ids
 * @param rvecs rotation vectors for markers
 * @param tvecs translation vectors for markers
 * @param object_map map of object 3D points
 * @param distortion_coefficients lens distortion coefficients
 * @param camera_matrix intrinsic camera matrix
 * @param output_frame frame to output
 */
void solve_and_draw(std::vector<int> marker_ids, std::vector<cv::Vec3d> rvecs, std::vector<cv::Vec3d> tvecs, std::unordered_map<std::string, std::vector<cv::Point3f>> object_map, std::vector<double> distortion_coefficients, cv::Mat camera_matrix, cv::Mat output_frame) {
    for (int i=0; i < marker_ids.size(); i++) {
        std::vector<cv::Point2f> img_points; // 2D calculated points to draw
        if (marker_ids.at(i) == 0) {
            cv::projectPoints(object_map["robber"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_robber(output_frame, img_points);
        }
        if (marker_ids.at(i) == 10 || marker_ids.at(i) == 15) {
            cv::projectPoints(object_map["wheat_hex"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_wheat(output_frame, img_points);
        }

        if (marker_ids.at(i) == 20) {
            cv::projectPoints(object_map["ore_hex"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_ore_hex(output_frame, img_points);
        }
        if (marker_ids.at(i) == 25) {
            cv::projectPoints(object_map["sheep_hex"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_sheep(output_frame, img_points);
        }
        if (marker_ids.at(i) == 30) {
            cv::projectPoints(object_map["wood_hex"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_wood_hex(output_frame, img_points);
        }
        if (marker_ids.at(i) == 35) {
            cv::projectPoints(object_map["brick_hex"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_brick_hex(output_frame, img_points);
        }
        if (marker_ids.at(i) == 40 || marker_ids.at(i) == 45) {
            cv::projectPoints(object_map["wheat_res"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_wheat(output_frame, img_points);
        }
        if (marker_ids.at(i) == 50) {
            cv::projectPoints(object_map["ore_res"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_ore(output_frame, img_points);
        }
        if (marker_ids.at(i) == 55) {
            cv::projectPoints(object_map["sheep_res"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_sheep(output_frame, img_points);
        }
        if (marker_ids.at(i) == 60) {
            cv::projectPoints(object_map["wood_res"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_wood_res(output_frame, img_points);
        }
        if (marker_ids.at(i) == 65) {
            cv::projectPoints(object_map["brick_res"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_brick_res(output_frame, img_points);
        }
        if (marker_ids.at(i) == 70) {
            cv::projectPoints(object_map["robber"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_robber(output_frame, img_points);
        }
        if (marker_ids.at(i) == 75) {
            cv::projectPoints(object_map["vp"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_vp(output_frame, img_points);
        }
        if (marker_ids.at(i) == 80) {
            cv::projectPoints(object_map["road_building"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road_building(output_frame, img_points);
        }
        if (marker_ids.at(i) == 85) {
            cv::projectPoints(object_map["monopoly"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_monopoly(output_frame, img_points);
        }
        if (marker_ids.at(i) == 90) {
            cv::projectPoints(object_map["yop"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_yop(output_frame, img_points);
        }

        if (marker_ids.at(i) == 91) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, cv::Scalar(0,0,255));
        }

        if (marker_ids.at(i) == 92) {
            cv::projectPoints(object_map["settlement"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_settlement(output_frame, img_points, cv::Scalar(0,0,255));
        }
        if (marker_ids.at(i) == 93) {
            cv::projectPoints(object_map["city"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_city(output_frame, img_points, cv::Scalar(0,0,255));
        }
        if (marker_ids.at(i) == 94) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, cv::Scalar(255,0,0));
        }
        if (marker_ids.at(i) == 95) {
            cv::projectPoints(object_map["settlement"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_settlement(output_frame, img_points, cv::Scalar(255,0,0));
        }
        if (marker_ids.at(i) == 96) {
            cv::projectPoints(object_map["city"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_city(output_frame, img_points, cv::Scalar(255,0,0));
        }

        if (marker_ids.at(i) == 97) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, cv::Scalar(0,255,0));
        }
        if (marker_ids.at(i) == 98) {
            cv::projectPoints(object_map["settlement"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_settlement(output_frame, img_points, cv::Scalar(0,255,0));
        }
        if (marker_ids.at(i) == 99) {
            cv::projectPoints(object_map["city"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_city(output_frame, img_points, cv::Scalar(0,255,0));
        }
        if (marker_ids.at(i) == 100) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, cv::Scalar(20,70,140));
        }

        if (marker_ids.at(i) == 101) {
            cv::projectPoints(object_map["settlement"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_settlement(output_frame, img_points, cv::Scalar(20,70,140));
        }
        if (marker_ids.at(i) == 102) {
            cv::projectPoints(object_map["city"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_city(output_frame, img_points, cv::Scalar(20,70,140));
        }
    }
}
