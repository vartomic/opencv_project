#pragma once
#include <opencv2/opencv.hpp>

class View {
	//	image object
	cv::Mat _img;

public:
	//	virtual function returns photo or video data
	virtual cv::Mat getData() {
		return _img;
	}
};