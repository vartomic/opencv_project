#pragma once
#include <opencv2/opencv.hpp>

class Model {

protected:
	// Sliders current positions
	int _par1, _par2, _par3;

	//Общее время, число обработанных кадров и число обнаруженных лиц
	double _totalTime;
	int _frameNum;
	int _faceScore;

public:
	//	Virtual function returns window frame
	virtual cv::Mat process(cv::Mat frame);
	//	Function sets values of sliders current positions from Controller class 
	void setParams(int par1, int par2, int par3);
	//
	void reset();
};