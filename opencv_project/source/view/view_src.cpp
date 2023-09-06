#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "view/view_src.h"

void ViewSrc::setTrackbar(cv::String name, int* trackbar) {
	cv::createTrackbar(name, winName, trackbar, 255);
}

void ViewSrc::setHSVtrackbar(cv::String name, int max, int pos) {
	cv::setTrackbarMax(name, winName, max);
	cv::setTrackbarPos(name, winName, pos);
}

void ViewSrc::showFrame(cv::Mat frame){

	//check if frame is empty
	if (frame.empty()) {
		return;
	}

	//aspect ratio
	const float aspectYX = (float)frame.rows / frame.cols;
	
	//width
	const int WidthResizedFrame = 800;
	
	//finds height
	const int HeightResizedFrame = aspectYX * WidthResizedFrame;

	//resize image
	cv::Mat resizeFrame;

	cv::resize(frame, resizeFrame, cv::Size(WidthResizedFrame, HeightResizedFrame));

	//Display window
	cv::imshow(winName, resizeFrame);
}