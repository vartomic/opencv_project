#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/model_canny.h"

cv::Mat CannyModel::process(cv::Mat frame) {
	//	Checks if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}
	cv::Mat gray;
	//	Converts input image to gray colorspace
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	cv::Mat canny;
	//	Finds edges in gray image using the Canny algorithm
	cv::Canny(gray, canny, _par1, _par2);
	//	Converts image from grayscale to BGR
	cv::cvtColor(canny, canny, cv::COLOR_GRAY2BGR);
	//	Black edges
	//cv::Mat image = frame - canny;
	//	White edges
	cv::Mat image = frame + canny;
	//	Returns converted image
	return image;
}