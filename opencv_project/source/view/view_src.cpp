#include "view/view_src.h"

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

void ViewSrc::getKeyDescription(std::vector<std::string> keyDescription) {
	_keyDescription = keyDescription;
}

void ViewSrc::showKeyDescription(cv::Mat frame, int thickness) {

	putText(frame, "123", cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(146, 47, 76), thickness);
}