#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "data.h"
#include "view\view.h"

class DataPhoto: public Data {

private:
	cv::Mat _img;
	cv::String _curImageIndex = 0;

public:

	//get img
	cv::Mat getData();

	cv::Mat nextImage();

};