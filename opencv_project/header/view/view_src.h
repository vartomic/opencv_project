#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class ViewSrc {
	//	Window name
	std::string _winName;
	//	Window size
	int _winFlag;
	//	Vector with the text, which will be placed on frame
	std::vector<std::string> _frameText;

public:
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
	void getFrameText(std::vector<std::string> frameText);
};
