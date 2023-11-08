#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Model {

protected:
	// Sliders current positions
	int _par1, _par2;

public:
	//	Virtual function returns window frame
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}
	//	Function sets values of sliders current positions from Controller class 
	void setParams(int par1, int par2);
};