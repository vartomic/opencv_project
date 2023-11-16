#include "model/model_hsv.h"

cv::Mat HSVModel::process(cv::Mat frame) {
	//	Checks if frame is empty
	if (frame.empty()) {
		return cv::Mat();
	}
	cv::Mat hsvImage;
	//	Converts image from RGB to HSV
	cv::cvtColor(frame, hsvImage, cv::COLOR_BGR2HSV);
	//	Range of 1 trackbar slider from 0 to 240
	int hue_from = _par1 - 15;
	int hue_to = _par1 + 15;
	//	Checks if values of slider is incorrect
	if (hue_from < 0){
		hue_from = 0;
	}
	//	Checks if values of slider is incorrect
	if (hue_to > 240) {
		hue_to = 240;
	}
	// Range of 2 trackbar slider from 0 to 240
	int sat_from = _par2 - 15;
	int sat_to = _par2 + 15;
	//	Checks if values of slider is incorrect
	if (sat_from < 0) {
		sat_from = 0;
	}
	//	Checks if values of slider is incorrect
	if (sat_to > 240) {
		sat_to = 240;
	}
	//	Sets brightness range
	int val_from = 50;
	int val_to = 200;
	//	Checks if values of slider is incorrect
	if (sat_to < 50) {
		sat_to = 50;
	}
	if (sat_to > 200) {
		sat_to = 200;
	}
	cv::Mat rangeImage;
	//	Checks if array elements lie between the elements of two other arrays
	//Input arguments: hsvImage = inputArray, cv::Scalar(inputArray (upper bounds)),
	//cv::Scalar(inputArray(lower bounds)), rangeImage = outputArray*/
	cv::inRange(hsvImage, cv::Scalar(hue_from, sat_from, val_from), 
		cv::Scalar(hue_to, sat_to, val_to), rangeImage);
	cv::Mat dilateImage; 
	//	Dilates an image by using a specific structuring element. Structuring element is an ellipse with a size 25x25 
	cv::dilate(rangeImage, dilateImage, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(25, 25)));
	//	Vector of vectors of points
	std::vector<std::vector<cv::Point>> contours;
	//	Vector with 4 dimensions, with each value an int
	std::vector<cv::Vec4i> hierarchy;
	//	Vector of points
	std::vector<cv::Point> approx;
	//	Finds outer contours of dilated image, using only 4 corner points
	cv::findContours(dilateImage, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
	//	Green color
	cv::Scalar green(0, 255, 0);
	//	Blue color
	cv::Scalar blue(255, 0, 0);
	//	Loop for size of vector of points
	for (size_t i = 0; i < contours.size(); i++) {
		//	Draws green contours outlines 
		cv::drawContours(frame, contours, i, green, 2, 8, hierarchy);
		//	Approximates a polygonal curves with the precision of 10
		cv::approxPolyDP(contours[i], approx, 10, true);
		// Draws several blue polygonal curves
		cv::polylines(frame, approx, true, blue, 1);
		//	Calculates up-right bounding rectangle for every point
		auto rect = cv::boundingRect(contours[i]);
		//	Draws green rectangle
		cv::rectangle(frame, rect, cv::Scalar(0, 255, 0));
	}
	//	Returns processed image
	return frame;
}