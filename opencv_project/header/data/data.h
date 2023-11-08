#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Data {
	//	Img object
	cv::Mat _img;
	//	Video object
	cv::VideoCapture _vid;

public:
	// Virtual function returns image
	virtual cv::Mat getData() {
		return _img;
	}
};