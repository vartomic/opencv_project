#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/hsvModel.h"

cv::Mat HSVModel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat hsv;

	cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

	return hsv;
}