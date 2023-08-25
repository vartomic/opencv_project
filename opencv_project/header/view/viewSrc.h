#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class ViewSrc {

private:

	//window name
	std::string winName;

	//window size
	int winFlag;

public:

	//default constructor
	ViewSrc() {};

	//constructor with window name and size param
	ViewSrc(const std::string WinName, int flag) {

		//window name
		winName = WinName;

		//window size
		winFlag = flag;

		//Create new window
		cv::namedWindow(winName, flag);
	}

	void showFrame(cv::Mat frame);

};
