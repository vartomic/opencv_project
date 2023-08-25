#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/cannyModel.h"

cv::Mat CannyModel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}


	return frame;
}