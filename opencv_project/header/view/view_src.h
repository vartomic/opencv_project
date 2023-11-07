#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class ViewSrc {
	//	Window name
	std::string winName;
	//	Window size
	int winFlag;

public:
	//	Empty constructor
	ViewSrc() {};
	//	Constructor with window name and window size as input arguments
	ViewSrc(const std::string WinName, int flag) {
		//	Class window name = function argument window name
		winName = WinName;
		//	Class window size = function argument window size
		winFlag = flag;
		//	Creates new window with window name and window size as function arguments
		cv::namedWindow(winName, winFlag);
	}
	// Function creates the trackbar with the specified name and range and attaches it to the specified window
	void setTrackbar(cv::String name, int* trackbar);
	//	Function creates the trackbar, it's maximum and current position for the HSV model
	void setHSVtrackbar(cv::String name, int max, int pos);
	//	Resizes image up to or down to the specified size and displays it in a specified window
	void showFrame(cv::Mat frame);
};
