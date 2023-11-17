#pragma once
#include <opencv2/opencv.hpp>
#include "data/data.h"

class DataCamera: public Data {

public:
	// Overriden function returns videoimage from webcamera
	cv::Mat getData();
};