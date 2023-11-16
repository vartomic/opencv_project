#include "model/model_gray.h"

cv::Mat GrayModel::process(cv::Mat frame) {
	//	Checks if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}
	cv::Mat gray;
	//	Converts input image to gray colorspace
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	//	Returns gray image
	return gray;
}

