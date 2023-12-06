#pragma once
#include <opencv2/opencv.hpp>

class Model {

protected:
	// Sliders current positions
	int _par1, _par2, _par3;
	//	Total amount of ellapsed time
	double _totalTime = 0.0;
	//	Counter for proccesed frames
	int _processedFrames = 0;
	//	Total score of founded faces
	int _totalFaceScore = 0;

public:
	//	Virtual function returns window frame
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}
	//	Function sets values of sliders current positions from Controller class 
	void setParams(int par1, int par2, int par3);
	//	Resets counter of faces, total amount of ellapsed time and counter of proccesed frames in the model
	void reset();
	//	Renders text with fps value, number of processed frames, number of founded faces and ellapsed time in the input image
	void visualize(cv::Mat& image, double fps, std::string modelName, int processedFrames, int totalFaceScore, double timeElapsed, int thickness = 2);
};