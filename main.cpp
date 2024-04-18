#include <iostream>

#include "util.h"
#include <opencv2/opencv.hpp>

int main() {

    //

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


    for (;;) {

        *videoCapture >> frame;

        if (frame.empty()) {
            std::cout << "Frame is empty" << std::endl;
            break;
        }


        cv::imshow("Camera", frame); // show frame output

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



    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
