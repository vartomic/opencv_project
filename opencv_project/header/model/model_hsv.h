#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class HSVModel: public Model {

public:
	// Function sets ranges for trackbar sliders, dilates an image by using an elliptic structuring element,
	//	finds outer contours of dilated image, draws green contours outlines, approximates a polygonal curves,
	// draws polygonal curves, calculates up-right bounding rectangle, draws rectangle and returns processed image
	cv::Mat process(cv::Mat frame);
};