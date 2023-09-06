#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

#include "data/data.h"

class DataVideo: public Data {

public:

	cv::Mat getData();
};