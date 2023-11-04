#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class MTCNNModel: public Model {

	cv::Mat process(cv::Mat frame);
};
