#include "view/view_src.h"

void ViewSrc::getFrameText(std::vector<std::string> frameText) {
	_frameText = frameText;
}

void ViewSrc::showFrame(cv::Mat frame) {
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
	//	Y coordinate of text string 
	int axY = 15;
	//	Loop for all elements in vector with key descriptions
	for (int i = 0; i < _frameText.size(); i++) {
		//	Puts text strings of key descriptions on frame
		putText(resizeFrame, _frameText[i], cv::Point(0, axY), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), 2, cv::LINE_AA);
		putText(resizeFrame, _frameText[i], cv::Point(0, axY), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 0), 1, cv::LINE_AA);
		//	Next string will be placed lower on 20 points
		axY += 20;
	}

	//	Displays image in a specified window
	cv::imshow(_winName, resizeFrame);
}