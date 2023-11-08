#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "view/view_src.h"

void ViewSrc::setTrackbar(cv::String name, int* trackbar) {
	cv::createTrackbar(name, _winName, trackbar, 255);
}
void ViewSrc::setHSVtrackbar(cv::String name, int max, int pos) {
	//	Sets the trackbar maximum position
	cv::setTrackbarMax(name, _winName, max);
	//	Sets the trackbar current position
	cv::setTrackbarPos(name, _winName, pos);
}
void ViewSrc::showFrame(cv::Mat frame){
	//	Checks if frame is empty
	if (frame.empty()) {
		return;
	}
	//aspect ratio = rows of window frame divides on columns of window frame and converts to float
	const float ASPECT_YX = (float)frame.rows / frame.cols;
	//	Width of window frame
	const int WIDTH_RESIZED_FRAME = 800;
	//	Finds height of window frame
	const int HEIGHT_RESIZED_FRAME = ASPECT_YX * WIDTH_RESIZED_FRAME;
	cv::Mat resizeFrame;
	//	Resizes image up to or down to the specified size
	cv::resize(frame, resizeFrame, cv::Size(WIDTH_RESIZED_FRAME, HEIGHT_RESIZED_FRAME));
	//	Displays image in a specified window
	cv::imshow(_winName, resizeFrame);
}