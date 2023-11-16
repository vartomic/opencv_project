#pragma once
#include <opencv2/opencv.hpp>
#include "model/model.h"

class CannyModel: public Model {

public:
	//	Function finds edges in gray image using the Canny algorithm and returns image with black or white edges
	cv::Mat process(cv::Mat frame);
};