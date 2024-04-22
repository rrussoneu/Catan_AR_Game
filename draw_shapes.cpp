//
// Created by Raphael Russo on 4/17/24.
//

#include "draw_shapes.h"

std::unordered_map<std::string, std::vector<cv::Point3f>> generate_3d_points() {
    std::unordered_map<std::string, std::vector<cv::Point3f>> object_map;
    // The points for hexagon models
    std::vector<cv::Point3f> wood_hex_points = {cv::Point3f(-0.02,0.0,0.0), cv::Point3f(0.02,0.0,0.0),  cv::Point3f(0.02,-0.04,0.0), cv::Point3f(-0.02,-.04,0.0),// square base
                                                cv::Point3f(-.02,0.0,0.05), cv::Point3f(0.02,0.0,0.05), cv::Point3f(0.02,-.04,0.05), cv::Point3f(-0.02,-.04,0.05),  // top of tree trunk
                                                cv::Point3f(-0.04, 0.0, 0.05), cv::Point3f(.04, 0.0, 0.05), cv::Point3f(.04, -.04, 0.05), cv::Point3f(-0.04, -0.04, 0.05),  // leaves base
                                                cv::Point3f(-0.04, 0.0, 0.07), cv::Point3f(.04, 0.0, 0.07),cv::Point3f(.04, -.04, 0.07), cv::Point3f(-0.04, -.04, 0.07),  // leaves level 2
                                                cv::Point3f(-0.01, 0.0, 0.09), cv::Point3f(.01, 0.0, 0.09), cv::Point3f(.01, -.04, 0.09), cv::Point3f(-0.01, -.04, 0.09),  // leaves level 3
                                                cv::Point3f(0.0, 0.0, 0.1), cv::Point3f(0.0, -.04, 0.1) // top of leaves

    };
    object_map["wood_hex"] = wood_hex_points;

    /*
    std::vector<cv::Point3f> wheat_points = {cv::Point3f(0.06+ .02, 0.0,0.0), cv::Point3f(0.1 + .02, 0.0,0.00), cv::Point3f(0.1+ .02, 0.04, 0.00), cv::Point3f(0.08, 0.04, 0.00), // base
                                             cv::Point3f(0.06+ .02, 0.0,-0.06), cv::Point3f(0.1+ .02, 0.0,-0.06), cv::Point3f(0.1+ .02, 0.04, -0.06), cv::Point3f(0.06+ .02, 0.04, -0.06), // middle
                                             cv::Point3f(0.06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .02, 0.0,-0.12), cv::Point3f(0.1+ .02, 0.04, -0.12), cv::Point3f(0.06+ .02, 0.04, -0.12), // top middle
                                             cv::Point3f(0.06 - .06, 0.0,-0.12), cv::Point3f(0.1- .06, 0.0,-0.12), cv::Point3f(0.1- .06, 0.04, -0.12), cv::Point3f(0.06 - .06, 0.04, -0.12), // top left
                                             cv::Point3f(0.06 + .06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .06+ .02, 0.0,-0.12), cv::Point3f(0.1+ .06+ .02, 0.04, -0.12), cv::Point3f(0.06 + .06+ .02, 0.04, -0.12) // top right
    };
     */
    std::vector<cv::Point3f> wheat_points = {cv::Point3f(-.015, 0.0,0.0), cv::Point3f(.015, 0.0,0.00), cv::Point3f(.015, -0.015, 0.00), cv::Point3f(-.015, -0.015, 0.00), // base
                                             cv::Point3f(-.015, 0.0,0.04), cv::Point3f(.015, 0.0,0.04), cv::Point3f(0.015, -0.015, 0.04), cv::Point3f(-0.015, -0.015, 0.04), // middle
                                             cv::Point3f(-.015, 0.0,0.06), cv::Point3f(.015, 0.0,0.06), cv::Point3f(0.015, -0.015, 0.06), cv::Point3f(-0.015, -0.015, 0.06), // middle
                                             cv::Point3f(-.055, 0.0,0.06), cv::Point3f(-.025, 0.0,0.06), cv::Point3f(-.025, -0.015, 0.06), cv::Point3f(-.055, -0.015, 0.06), // top left
                                             cv::Point3f(.025, 0.0,0.06), cv::Point3f(0.055, 0.0,0.06), cv::Point3f(0.055, -0.015, 0.06), cv::Point3f(.025, -.015, 0.06) // top right
    };

    object_map["wheat_hex"] = wheat_points;
    object_map["wheat_res"] = wheat_points;
    /*
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
    */
    float sheep_w = .02;
    std::vector<cv::Point3f> sheep_points = {cv::Point3f(-0.04,0.0 +sheep_w ,0.0), cv::Point3f(-0.02,0.0+sheep_w,0.0), cv::Point3f(-0.02,-0.02+sheep_w,0.0), cv::Point3f(-0.04,-.02+sheep_w,0.0), cv::Point3f(0.02,0.0+sheep_w,0.0), cv::Point3f(0.04,0.0+sheep_w,0.0), cv::Point3f(0.04,-.02+sheep_w,0.0), cv::Point3f(0.02,-0.02+sheep_w,0.0), // sheep's anatomical bottom left
                                             cv::Point3f(sheep_w,(-3*sheep_w) + sheep_w ,0.0), cv::Point3f(sheep_w*2,(-3*sheep_w) + sheep_w,0.0), cv::Point3f(sheep_w*2,(-4*sheep_w) + sheep_w,0.0), cv::Point3f(sheep_w,-3*sheep_w + sheep_w,0.0), cv::Point3f(-2*sheep_w,-2*sheep_w + sheep_w,0.0), cv::Point3f(-sheep_w,-2*sheep_w + sheep_w,0.0), cv::Point3f(-sheep_w,-3*sheep_w + sheep_w,0.0), cv::Point3f(-2*sheep_w,-3*sheep_w + sheep_w,0.0), // sheep's anatomical bottom right
                                             cv::Point3f(-0.04,0.0 +sheep_w ,0.0), cv::Point3f(-0.02,0.0+sheep_w,0.0), cv::Point3f(-0.02,-0.02+sheep_w,0.0), cv::Point3f(-0.04,-.02+sheep_w,0.0), cv::Point3f(0.02,0.0+sheep_w,0.0), cv::Point3f(0.04,0.0+sheep_w,0.0), cv::Point3f(0.04,-.02+sheep_w,0.0), cv::Point3f(0.02,-0.02+sheep_w,0.0), // sheep's anatomical bottom left
                                             cv::Point3f(sheep_w,(-3*sheep_w) + sheep_w ,0.0), cv::Point3f(sheep_w*2,(-3*sheep_w) + sheep_w,0.0), cv::Point3f(sheep_w*2,(-4*sheep_w) + sheep_w,0.0), cv::Point3f(sheep_w,-3*sheep_w + sheep_w,0.0), cv::Point3f(-2*sheep_w,-2*sheep_w + sheep_w,0.0), cv::Point3f(-sheep_w,-2*sheep_w + sheep_w,0.0), cv::Point3f(-sheep_w,-3*sheep_w + sheep_w,0.0), cv::Point3f(-2*sheep_w,-3*sheep_w + sheep_w,0.0), // sheep's anatomical bottom right
            // top square of sheep body
                                             cv::Point3f(0.0,0.0,0.12), cv::Point3f(0.16,0.0,0.12), cv::Point3f(0.16,0.12,0.12), cv::Point3f(0.0,0.12,0.12),
            // head bottom
                                             cv::Point3f(.16,.04,.06), cv::Point3f(.2,.04,.06), cv::Point3f(.2,.08,.06), cv::Point3f(.16,.08,.06),
            // head top
                                             cv::Point3f(.16,.04,.12), cv::Point3f(.2,.04,.12), cv::Point3f(.2,.08,.12), cv::Point3f(.16,.08,.12),

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

    // All the points for the 3D models of resource cards
    std::vector<cv::Point3f> wood_points = {cv::Point3f(1/20.0,1/20.0, 0.0), cv::Point3f(1.5/20.0,1/20.0, 0.0), cv::Point3f(.5/20.0,2/20.0, 0.0), cv::Point3f(2/20.0,2/20.0, 0.0),cv::Point3f(1/20.0,3/20.0, 0.0), cv::Point3f(1.5/20.0,3/20.0, 0.0),
                                            cv::Point3f(1/20.0,1/20.0,-2/10.0), cv::Point3f(1.5/20.0,1/20.0,-2/10.0), cv::Point3f(.5/20.0,2/20.0,-2/10.0), cv::Point3f(2/20.0,2/20.0,-2/10.0),cv::Point3f(1/20.0,3/20.0,-2/10.0), cv::Point3f(1.5/20.0,3/20.0,-2/10.0)};




    std::vector<cv::Point3f> brick_points = {cv::Point3f(0.0, 0.0, 0.0), cv::Point3f(0.10, 0.0, 0.0), cv::Point3f(0.10, 0.05, 0.0), cv::Point3f(0.0, 0.05, 0.0),
                                             cv::Point3f(0.0, 0.0, -0.05), cv::Point3f(0.10, 0.0, -0.05), cv::Point3f(0.10, 0.05, -0.05), cv::Point3f(0.0, 0.05, -0.05),};

    std::vector<cv::Point3f> ore_points = {cv::Point3f(0.00,0.00,0.0), cv::Point3f(0.1, 0.00,0.00), cv::Point3f(0.05, 0.1, 0.00), cv::Point3f(0.05, 0.05, -.1)};


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

    return object_map;


}


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

void draw_wood_hex(cv::Mat &frame, std::vector<cv::Point2f> img_points) {
    for (int i = 0; i < 4; i++) {
        if (i != 3) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 8), cv::Scalar(0,255,0), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 5), cv::Scalar(20,70,140), 5);

        } else {
            cv::line(frame, img_points.at(i), img_points.at(i - 3), cv::Scalar(20,70,140), 5);
            cv::line(frame, img_points.at(i + 4), img_points.at(i + 4 -3), cv::Scalar(20,70,140), 5);

        }
        cv::line(frame, img_points.at(i), img_points.at(i + 4), cv::Scalar(20,70,140), 5);
        cv::line(frame, img_points.at(i + 8), img_points.at(i + 12), cv::Scalar(0,255,0), 5);
        cv::line(frame, img_points.at(i + 12), img_points.at(i + 16), cv::Scalar(0,255,0), 5);

    }
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

void draw_yop(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // giant plus
    cv::line(frame, img_points.at(0), img_points.at(3), cv::Scalar(0,255,0), 50);
    cv::line(frame, img_points.at(1), img_points.at(2), cv::Scalar(0,255,0), 50);

}

void draw_monopoly(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // money sign
    for (int i = 0; i < 11; i++) {
        if (i != 7 && i != 9) {
            cv::line(frame, img_points.at(i), img_points.at(i + 1), cv::Scalar(0,255,0), 20);
        }
    }
}

void draw_road_building(cv::Mat &frame, std::vector<cv::Point2f> img_points) { // shovel
    cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(0), img_points.at(2), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(1), img_points.at(3), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(3), img_points.at(4), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(2), img_points.at(4), cv::Scalar(60,74,178), 30);
    cv::line(frame, img_points.at(5), img_points.at(6), cv::Scalar(20,70,140), 30);
    cv::line(frame, img_points.at(7), img_points.at(8), cv::Scalar(20,70,140), 30);
}

/**
 * Draws a road
 * @param frame frame to draw on
 * @param img_points points to connect
 * @param color 91, 94, 97, 100 for red, green, blue, brown
 */
void draw_road(cv::Mat &frame, std::vector<cv::Point2f> img_points, int color) {
    if (color == 91) {
        cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(0,0,255), 50);
    }
    if (color == 94) {
        cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(255,0,0), 50);
    }
    if (color == 97) {
        cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(0,255,0), 50);
    }
    if (color == 100) {
        cv::line(frame, img_points.at(0), img_points.at(1), cv::Scalar(20,70,140), 50);
    }
}

void solve_and_draw(std::vector<int> marker_ids, std::vector<cv::Vec3d> rvecs, std::vector<cv::Vec3d> tvecs, std::unordered_map<std::string, std::vector<cv::Point3f>> object_map, std::vector<double> distortion_coefficients, cv::Mat camera_matrix, cv::Mat output_frame) {
    for (int i=0; i < marker_ids.size(); i++) {
        std::vector<cv::Point2f> img_points; // 2D calculated points to draw
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
            draw_road(output_frame, img_points, marker_ids.at(i));
        }
        if (marker_ids.at(i) == 94) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, marker_ids.at(i));
        }
        if (marker_ids.at(i) == 97) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, marker_ids.at(i));
        }
        if (marker_ids.at(i) == 100) {
            cv::projectPoints(object_map["road"], rvecs.at(i), tvecs.at(i), camera_matrix, distortion_coefficients, img_points);
            draw_road(output_frame, img_points, marker_ids.at(i));
        }

    }
}
