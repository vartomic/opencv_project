#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/grayModel.h"

cv::Mat GrayModel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat gray;

	//image to grey color
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	return gray;
}

