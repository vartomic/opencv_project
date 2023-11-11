#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include "data.h"

class DataPhoto: public Data {
	//	Image object
	cv::Mat _img;
	//	Index of image
	int _curImageIndex = 0;

public:
	//	Function returns image
	cv::Mat getData();
	//	Function reads path to image from array, then by pressing 'p' button changes image to the next
	void nextImage();
};