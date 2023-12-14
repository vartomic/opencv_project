#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class ViewSrc {
	//	Window name
	std::string _winName;
	//	Window size
	int _winFlag;
	//	Vector with descriptions of keys
	std::vector<std::string> _keyDescription;
	//	Vector with coordinates of keys descriptions
	std::vector<cv::Point> data = { cv::Point(0, 15), cv::Point(0, 35), cv::Point(0, 55), cv::Point(0, 75),
		cv::Point(0, 95), cv::Point(0, 115), cv::Point(0, 135) };

public:
	//	Empty constructor
	ViewSrc() {};
	//	Constructor with window name and window size as input arguments
	ViewSrc(const std::string winName, int flag) {
		//	Class window name = function argument window name
		_winName = winName;
		//	Class window size = function argument window size
		_winFlag = flag;
		//	Creates new window with window name and window size as function arguments
		cv::namedWindow(_winName, _winFlag);
	}
	//	Resizes image up to or down to the specified size and displays it in a specified window
	void showFrame(cv::Mat frame);
	//	Function receives buttons description and assignes them in ViewSrc class
	void getKeyDescription(std::vector<std::string> keyDescription);
};
