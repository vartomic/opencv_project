#pragma once
#include <opencv2/opencv.hpp>
#include "data.h"

//	Derived from class Data, class DataVideo iterates over the elements of a directory with videos, 
//	converts file paths in string and places them in a vector after checking if filepath is regular file.
//	Then reads vector of paths and iterates over them by increasing index.
class DataVideo: public Data {
	//
	cv::VideoCapture _videoFrame;
	//	Index of video
	int _curVideoIndex = 0;

public:
	//	Function returns video
	cv::Mat getData();
	//	Function reads path to video from array, then by pressing 'v' button changes video to the next
	void nextVideo();
};