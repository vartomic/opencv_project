#pragma once
#include <opencv2/opencv.hpp>
#include "data.h"

//	Derived from class Data, class DataPhoto iterates over the elements of a directory with images, 
//	converts file paths in string and places them in a vector after checking if filepath is regular file.
//	Then reads vector of paths and iterates over them by increasing index.
class DataPhoto: public Data {
	//	Image object
	cv::Mat _img;
	//	Index of image
	int _curImageIndex = 0;

public:
	//	Function changes position of a flag and returns image
	cv::Mat getData();
	//	Function reads path to image from array, then by pressing 'p' button changes image to the next
	void nextImage();
};