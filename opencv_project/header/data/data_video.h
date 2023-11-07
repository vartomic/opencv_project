#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include "data/data.h"

class DataVideo: public Data {

public:
	// Overriden function returns videoimage from webcamera
	cv::Mat getData();
};