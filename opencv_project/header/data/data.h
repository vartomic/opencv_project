#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Data {

private:

	//img object
	cv::Mat img;

	//video object
	cv::VideoCapture vid;

public:

	//default get img
	virtual cv::Mat getData() {
		return img;
	}
};