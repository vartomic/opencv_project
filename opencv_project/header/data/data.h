#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Data {
	//	Img object
	cv::Mat img;
	//	Video object
	cv::VideoCapture vid;

public:
	// Virtual function returns image
	virtual cv::Mat getData() {
		return img;
	}
};