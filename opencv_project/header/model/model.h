#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Model {

public:
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}
};