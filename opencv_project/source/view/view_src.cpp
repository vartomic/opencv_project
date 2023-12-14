#include "view/view_src.h"

void ViewSrc::getKeyDescription(std::vector<std::string> keyDescription) {
	_keyDescription = keyDescription;
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
	//	Loop for all elements in vector with key descriptions
	for (int i = 0; i < _keyDescription.size(); i++) {
		//	Loop for all elements in vector with coordinates of key descriptions 
		for (int j = 0; j < data.size(); j++) {
			//	Puts text strings of key descriptions on frame
			putText(resizeFrame, _keyDescription[j], data[j], cv::FONT_ITALIC, 0.5, cv::Scalar(0, 204, 102), 2);
		}
	}
	//	Displays image in a specified window
	cv::imshow(_winName, resizeFrame);
}