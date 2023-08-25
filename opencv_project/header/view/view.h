#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class View {

private:

	//img object
	cv::Mat img;

public:
	
	//default get img
	virtual cv::Mat getData() {
		return img;
	}

};