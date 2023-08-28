#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

class Model {

protected:
	int _par1, _par2;

public:
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}

	void setParams(int par1, int par2);
};