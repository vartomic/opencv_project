#pragma once
#include <opencv2/opencv.hpp>

class Model {

protected:
	// Sliders current positions
	int _par1, _par2, _par3;
	//	Total amount of ellapsed time
	double _totalTime;
	//	Counter for proccesed frames
	int _processedFrames;
	//	Total score of founded faces
	int _totalFaceScore;

public:
	//	Virtual function returns window frame
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}
	//	Function sets values of sliders current positions from Controller class 
	void setParams(int par1, int par2, int par3);
	//	Resets counter of faces, total amount of ellapsed time and counter of proccesed frames in the model
	void reset();
};