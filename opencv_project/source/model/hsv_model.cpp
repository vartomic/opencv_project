#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "model/hsv_model.h"

cv::Mat HSVModel::process(cv::Mat frame) {

	//check if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}

	cv::Mat hsvImage;

	cv::cvtColor(frame, hsvImage, cv::COLOR_BGR2HSV);

	//par1 = 165, par2 = 42

	//trackbar1 from 0 to 240, pos = 100, range 75-125
	int hue_from = _par1 - 15;
	int hue_to = _par1 + 15;

	if (hue_from < 0){
		hue_from = 0;
	}
	if (hue_to > 240) {
		hue_to = 240;
	}

	//trackbar2 from 0 to 240, pos = 240
	int sat_from = _par2 - 15;
	int sat_to = _par2 + 15;

	if (sat_from < 0) {
		sat_from = 0;
	}
	if (sat_to > 240) {
		sat_to = 240;
	}

	//brightness
	int val_from = 50;
	int val_to = 200;

	cv::Mat rangeImage;

	//Checks if array elements lie between the elements of two other arrays
	/*hsvImage = inputArray, cv::Scalar(inputArray (upper bounds)),
	cv::Scalar(inputArray(lower bounds)), rangeImage = outputArray*/
	cv::inRange(hsvImage, cv::Scalar(hue_from, sat_from, val_from), 
		cv::Scalar(hue_to, sat_to, val_to), rangeImage);

	//третий трекбар

	cv::Mat dilateImage; 
	cv::dilate(rangeImage, dilateImage, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25)));

	//vector of vectors of points
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	std::vector<cv::Point> approx;

	// finds outer contours, using only 4 corner points
	cv::findContours(dilateImage, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

	cv::Scalar green(0, 255, 0);
	cv::Scalar blue(255, 0, 0);

	for (size_t i = 0; i < contours.size(); i++) {
		cv::drawContours(frame, contours, i, green, 2, 8, hierarchy);
		cv::approxPolyDP(contours[i], approx, 10, true);
		cv::polylines(frame, approx, true, blue, 1);
		auto rect = cv::boundingRect(contours[i]);
		cv::rectangle(frame, rect, cv::Scalar(0, 255, 0));
	}
	return frame;
}