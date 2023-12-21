#pragma once
#include <opencv2/opencv.hpp>

class Model {

protected:
	//	Total amount of ellapsed time
	double _totalTime = 0.0;
	//	Counter for proccesed frames
	int _processedFrames = 0;
	//	Total score of founded faces
	int _totalFaceScore = 0;
	//
	std::vector<std::string> _frameText;

public:
	//	Virtual function returns window frame
	virtual cv::Mat process(cv::Mat frame) {
		return frame;
	}
	//	Resets counter of faces, total amount of ellapsed time and counter of proccesed frames in the model
	void reset();
	//
	std::vector<std::string> sendArray();
	//	Renders text with fps value, number of processed frames, number of founded faces and ellapsed time in the input image
	void visualize(cv::Mat& image, double fps, std::string modelName, int processedFrames, int totalFaceScore, double timeElapsed, int thickness = 2);
};