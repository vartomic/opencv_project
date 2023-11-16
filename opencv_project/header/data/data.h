#pragma once
#include <opencv2/opencv.hpp>

class Data {
	//	Img object
	cv::Mat _img;

public:
	// Virtual function returns image
	virtual cv::Mat getData() {
		return _img;
	}
};