#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/hsv_model.h"

cv::Mat HSVmodel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat hsvImage;

	cv::cvtColor(frame, hsvImage, cv::COLOR_BGR2HSV);

	int hue_from = _par1 - 25;
	int hue_to = _par2 + 25;

	//проверку сделать нормально

	//if (hue_from < 0 || hue_to > 240){
	//	return cv::Mat();
	//}

	//par1 = 60, par2 = 230

	int sat_from = _par1 - 25;
	int sat_to = _par2 + 25;

	int val_from = 30;
	int val_to = 220;

	cv::Mat rangeImage;

	cv::inRange(hsvImage, cv::Scalar(hue_from, sat_from, val_from), 
		cv::Scalar(hue_to, sat_to, val_to), rangeImage);

	//cv::Mat dilateImage;

	//cv::dilate(rangeImage, dilateImage, 
	//	cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25)));

	return rangeImage;
}