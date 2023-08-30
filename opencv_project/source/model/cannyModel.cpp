#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/cannyModel.h"

cv::Mat CannyModel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat gray;

	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

	cv::Mat canny;

	cv::Canny(gray, canny, _par1, _par2);

	return canny;
}