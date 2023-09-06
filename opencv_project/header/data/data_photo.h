#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "data.h"
#include "view\view.h"

class DataPhoto: public Data {

public:

	//get img
	cv::Mat getData();

};